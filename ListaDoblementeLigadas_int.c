#include <stdio.h>
#include <stdlib.h>

typedef struct nodos{
	int n;
	struct nodos *sig;
	struct nodos *ant;
}Nodo;

void agregarTop(Nodo **inicio, Nodo **fin, int n){
	Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
	nuevo->n = n;
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	if(*inicio == NULL){
		*inicio = nuevo;
		*fin  = nuevo;		
	} else {
		nuevo->sig = *inicio;
		(*inicio)->ant = nuevo;
		*inicio = nuevo;
	}
}

void agregarBot(Nodo ** inicio,Nodo ** fin,int n){

	Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
	nuevo->n = n;
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	if(*fin == NULL){
		*inicio = nuevo;
		*fin = nuevo;
	} else{
		nuevo->ant = *fin;
		(*fin)->sig = nuevo;
		*fin = nuevo;
	}
}

void mostrarTOP(Nodo *inicio){
	Nodo *actual = inicio;
	if ( inicio == NULL){
		printf("No existen registros.\n");
	} else{
		while(actual != NULL){
			printf("n: %d\n", actual->n);
			actual = actual->sig;
		}
	}
}

void mostrarBot(Nodo *fin){
	Nodo *actual;
	actual = fin; 
	if ( actual == NULL){
		printf("No existen registros.\n");

	} else{
		while(actual != NULL){
			printf("n: %d\n", actual->n);
			actual = actual->ant;
		}
	}
}

main(){
	Nodo *inicio = NULL;
	Nodo *fin = NULL;
	int n, opcion;
	
	while(opcion != 6){
	printf("\n******* Inicio *******\n");
	printf("1. AgregarTOP\n");
	printf("2. AgregarBOT\n");
	printf("3. MostrarTOP\n");
	printf("4. MostrarBOT\n");
	printf("5. MostrarPunteros\n");
	printf("6. Salir\n");
	scanf("%d", &opcion);
	
	switch(opcion){
		case 1:
			printf("Int:");
			scanf("%d", &n);
			agregarTop(&inicio, &fin, n);
			
			break;
		case 2:
			printf("Int:");
			scanf("%d", &n);
			agregarBot(&inicio, &fin, n);
			break;
		case 3:
			mostrarTOP(inicio);
			break;
		case 4:
			mostrarBot(fin);
			break;
		case 5:
				printf("Inicio: %p\t FIN: %p/n", inicio, fin);
			break;
		case 6:
			break;
		default:
			printf("Opcion Incorrecta\n");
			break;	
	}
	}
}
