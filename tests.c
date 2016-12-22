#include <stdio.h>
#include <stdlib.h>
int FINAL = 0;
int INICIO = 0;

int * insertar (int num, int * vector){
	
	int i, *vector_aux;
		
	if ((FINAL)==0){ // Ingresamos nuestro primer elemento
		vector[FINAL]=num;
		FINAL++;
		return vector;
	}else{
		vector_aux=realloc(vector, sizeof(int));
		vector[FINAL]=num;
		FINAL++;
	}
	return vector_aux;
}

void mostrarCola(int * vector){
	printf("\nCola:\t");
	int i;
	for(i=0; i<FINAL; i++){
		printf("%3.d", vector[i]);
	}
}

void remover ( int *vector){
	
	int i;
	if ( FINAL <= 0 ){
		printf("\nLa cola esta vacia\n");
	}
	else if (FINAL > 0){
		
		for (i=0; i<FINAL; i++){
			vector[i]=vector[i+1];
		}
		
		FINAL--;		
	}
}

int main(int argc, char *argv[]) {
	int opcion, num;

	int * vector;
	vector=malloc(sizeof(int));
	do {
		printf("\n**********\nElija una opcion\n1.Insertar\n2.Remover\n3.Verificar si esta llena o vacia\n4.Salir\n**********\n");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
				
				printf("Ingrese un numero: "); scanf("%d", &num);
				vector=insertar(num, vector);
				mostrarCola(vector);
				break;
			case 2:
				INICIO++;
				remover(vector);
				mostrarCola(vector);
				break;	
			case 3:
				if (FINAL<=0){
					printf("\nLa cola esta vacia\n");
				}else if (FINAL>0){
					printf("\nLa cola no esta vacia\n");
				}
				break;
			default:
				printf("\nFIN\n");
				break;	
		}
		
	}while(opcion!=4);
	

	return 0;
}

