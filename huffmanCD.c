/*
http://www.dfists.ua.es/~gil/huffman.c
Este programa implementa un sencillo compresor
de Huffman, que podria usarse para un programa
de mayor envergadura.

comprimir: huf C entrada salida
descompr.: huf D entrada salida
info:      huf I entrada
*/

#include <stdio.h>
#include <malloc.h>

struct nodo
{
    struct nodo *der,*izq,*arr;  /* forma el nodo */
    int cuenta;                  /* apariciones del carÃ¡cter */
    char bit;                    /* 0 o 1 */
    unsigned char karacter;      /* el carÃ¡cter (para la descompresiÃ³n */
    char *codigo;                /* cadena de ceros y unos con la codificaciÃ³n */
    char nbits;                  /* me apunto el numero de bits que codifican el carÃ¡cter */
}HOJAS[256],*TELAR[256],*MENOR,*SEGUNDO;

int NSIMB=0,nsimb;
FILE *f,*g;
int NBYTES=0;

/*--------------------------------
preparar las hojas
--------------------------------*/
int preparar_hojas(char *archivo)
{
    int j;
    for(j=0;j<256;++j){
        HOJAS[j].der=HOJAS[j].izq=HOJAS[j].arr=NULL;
        HOJAS[j].cuenta=0;
        HOJAS[j].karacter=j;
        HOJAS[j].codigo=NULL;
    }
    if ((f=fopen(archivo,"rb"))!=NULL){
        while ((j=fgetc(f))!=EOF){
            ++HOJAS[j].cuenta;
            ++NBYTES;
        }
        fclose(f);
    }
    else
    {
        return(1);
    }
    for(j=0;j<256;++j){
        if (HOJAS[j].cuenta!=0)
            ++NSIMB;
    }
    nsimb=NSIMB;
    return(0);
}

/*--------------------------------
preparar telar
--------------------------------*/
void preparar_telar()
{
    int j;
    for(j=0;j<256;++j){
        TELAR[j]=&(HOJAS[j]);
    }
    return;
}

/*--------------------------------
tejer el Ã¡rbol
--------------------------------*/
void tejer()
{
    int menor=-1;     /* guarda indice */
    int segundo=-1;   /* guarda indice */
    int temporal;     /* guarda cuenta */
    int j;
    struct nodo *P;   /* nuevo nodo */

    if (nsimb==1) return;

    /* buscar menor valor */
    for(j=0;j<256;++j){
        if (TELAR[j]==NULL) continue;
        if (TELAR[j]->cuenta==0) continue;
        if (menor==-1){
            menor=j;
            temporal=TELAR[j]->cuenta;
        } else
        {
            if (TELAR[j]->cuenta<temporal){
                menor=j;
                temporal=TELAR[j]->cuenta;
            }
        }
    }

    /* buscar segundo menor */
    for(j=0;j<256;++j){
        if (TELAR[j]==NULL) continue;
        if (TELAR[j]->cuenta==0) continue;
        if (j==menor) continue;
        if (segundo==-1){
            segundo=j;
            temporal=TELAR[j]->cuenta;
        } else
        {
            if (TELAR[j]->cuenta<temporal){
                segundo=j;
                temporal=TELAR[j]->cuenta;
            }
        }
    }

    /* tejer un nuevo nodo */
    P=(struct nodo *)malloc(sizeof(struct nodo));
    TELAR[menor]->arr=P;
    TELAR[segundo]->arr=P;
    P->izq=TELAR[menor];
    P->der=TELAR[segundo];
    P->arr=NULL;
    TELAR[menor]->bit=0;
    TELAR[segundo]->bit=1;
    P->cuenta=TELAR[menor]->cuenta+TELAR[segundo]->cuenta;
    TELAR[menor]=NULL;
    TELAR[segundo]=P;
    --nsimb;

    /* sigue tejiendo hasta que sÃ³lo quede un nodo */
    tejer();
}

/*--------------------------------
Una vez construido el Ã¡rbol, puedo codificar
cada carÃ¡cter. Para eso recorro desde la hoja
a la raÃ­z, apunto 0 o 1 en una pila y luego
paso la pila a una cadena. Un 2 determina el
fin de la cadena.
--------------------------------*/
void codificar()
{
    char pila[64];
    char tope;
    int j;
    char *w;
    struct nodo *P;
    for(j=0;j<256;++j){
        if (HOJAS[j].cuenta==0) continue;
        P=(struct nodo *)(&(HOJAS[j]));
        tope=0;
        while (P->arr!=NULL){
            pila[tope]=P->bit;
            ++tope;
            P=P->arr;
        }
        HOJAS[j].nbits=tope;
        HOJAS[j].codigo=(char *)malloc((tope+1)*sizeof(char));
        w=HOJAS[j].codigo;
        --tope;
        while (tope>-1){
            *w=pila[tope];
            --tope;
            ++w;
        }
        *w=2;
    }
    return;
}


/*--------------------------------
debug. Imprime la info sobre cada
carÃ¡cter, como nÃºmero de apariciones
y cadena con que se codifica
--------------------------------*/
void debug()
{
    int j,k;
    char *w;
    int tam_comprimido=0;
    for(j=0;j<256;++j){
        if (HOJAS[j].cuenta==0) continue;
        tam_comprimido+=(HOJAS[j].cuenta*HOJAS[j].nbits);
        printf("%3d %6d ",j,HOJAS[j].cuenta);
        w=HOJAS[j].codigo;
        while (*w!=2){
            printf("%c",48+(*w));
            ++w;
        }
        printf("\n");
    }
    printf("NSIMB: %d\n",NSIMB);
    printf("NBYTES: %d\n",NBYTES);
    printf("TAMAÃ‘O COMPRIMIDO: %d\n",tam_comprimido/8+1);
    return;
}

/*--------------------------------
Escribe la cabecera del archivo de
destino. La cabecera contiene: el
nÃºmero de bytes del archivo origen,
el nÃºmero de caracteres distintos
en ese archivo y una lista de parejas
nÃºmero de carÃ¡cter-cuenta de ese
carÃ¡cter. Eso es suficiente para la
descompresiÃ³n
--------------------------------*/
int escribe_cabecera(char *destino)
{
    int j,k;
    FILE *g;

    char *p=(char *)(&NBYTES);
    if ((g=fopen(destino,"wb"))==NULL) return(1);
    for(j=0;j<4;++j){
        fputc(*p,g);
        ++p;
    }

    p=(char *)(&NSIMB);
    fputc(*p,g);

    for(j=0;j<256;++j){
        if (HOJAS[j].cuenta==0) continue;
        fputc(j,g);
        p=(char *)(&(HOJAS[j].cuenta));
        for(k=0;k<4;++k){
            fputc(*p,g);
            ++p;
        }
    }
    fclose(g);
    return(0);
}

/*--------------------------------
Una vez construido el Ã¡rbol y codificado
cada carÃ¡cter se puede proceder a la
compresiÃ³n: se tomarÃ¡ carÃ¡cter a carÃ¡cter
del archivo origen y se usarÃ¡ la cadena
de codificaciÃ³n para ir escribiendo
bits en un buffer de un carÃ¡cter, que
cada vez que quede lleno se pasarÃ¡ al
archivo de destino
--------------------------------*/
int comprimir(char *origen, char *destino)
{
    unsigned char d=0;
    int x;
    char nbit=0;
    char *p;

    if ((f=fopen(origen,"rb"))==NULL) return(1);
    if ((g=fopen(destino,"ab"))==NULL) return(2); /* ya esta la cabecera */

    while ((x=fgetc(f))!=EOF){
        p=HOJAS[x].codigo;
        while (*p!=2){
            if (nbit==8){
                nbit=0;
                fputc(d,g);
                d=0;
            } else
            {
                if (*p==1){
                    d|=(1<<nbit);
                }
                ++nbit;
                ++p;
            }
        }
    }
    fputc(d,g);
    fclose(f);
    fclose(g);
    return(0);
}

/*--------------------------------
Descomprime el archivo. El primer paso
es leer la cabecera, paso previo a la
descompresiÃ³n. Recuerdo formato de
la cabecera:
NBYTES|NSIMB|(char,cuenta)*
--------------------------------*/
int descomprimir(char *origen, char *destino)
{
    char *p;
    int j,k,n,m;
    unsigned char x,nbit;
    struct nodo *P,*Q;

    if ((g=fopen(origen,"rb"))==NULL) return(1);
    if ((f=fopen(destino,"wb"))==NULL) return(2);

    /* leer NBYTES */
    p=(char *)(&n);
    for(j=0;j<4;++j){
        *p=(unsigned char)fgetc(g);
        ++p;
    }
    NBYTES=n;

    /* leer NSIMB */
    NSIMB=nsimb=fgetc(g);

    /* preparar las hojas */
    for(j=0;j<256;++j){
        HOJAS[j].cuenta=0;
        HOJAS[j].izq=HOJAS[j].der=HOJAS[j].arr=NULL;
        HOJAS[j].karacter=j;
    }
    for(j=0;j<NSIMB;++j){
        n=fgetc(g);
        p=(char *)(&m);
        for(k=0;k<4;++k){
            *p=(unsigned char)fgetc(g);
            ++p;
        }
        HOJAS[n].cuenta=m;
    }

    /* construyo el Ã¡rbol */
    preparar_telar();
    tejer();

    /* apunto a la raÃ­z del Ã¡rbol */
    j=0;
    while (HOJAS[j].cuenta==0) ++j;
    P=(struct nodo *)(&(HOJAS[j]));
    while (P->arr!=NULL) P=P->arr;

    /* ahora ya se puede descomprimir */
    j=0;
    x=fgetc(g);
    nbit=0;
    Q=P;
    while(j<NBYTES){
        if (Q->izq==NULL){
            fputc(Q->karacter,f);
            Q=P;
            ++j;
        } else
        if (nbit==8){
            x=fgetc(g);
            nbit=0;
        } else
        {
            if (x&(1<<nbit)){
                Q=Q->der;
            }
            else
            {
                Q=Q->izq;
            }
            ++nbit;
        }
    }
    fclose(f);
    fclose(g);
    return(0);
}

main(int argc, char *argv[])
{

    int j;
    if (argc<2) return;
    if (*(argv[1])=='C'){ /* comprimir */
        if (argc!=4) return;
        if (preparar_hojas(argv[2])){
            printf("error abriendo archivo\n");
            return;
        }
        preparar_telar();
        tejer();
        codificar();
        if (escribe_cabecera(argv[3])){
            printf("error abriendo archivo\n");
            return;
        }
        if (comprimir(argv[2],argv[3])){
            printf("error abriendo archivo\n");
            return;
        }
    }
    else
    if (*(argv[1])=='D'){ /* descomprimir */
        if (argc!=4) return;
        if (descomprimir(argv[2],argv[3])){
            printf("error abriendo archivo\n");
            return;
        }
    }
    else
    if (*(argv[1])=='I'){ /* info */
        if (argc!=3) return;
        if (preparar_hojas(argv[2])){
            printf("error abriendo archivo\n");
            return;
        }
        preparar_telar();
        tejer();
        codificar();
        debug();
    }
    return;
}
