#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

typedef struct persona{
	char cedula[11];
	char nombre[50];
	char apellido[50];
	struct persona *sig;
}persona;

persona * array[SIZE];

int hash(char cedula[11]){
	int i, suma = 0;
	
	for (i = 0; i < strlen(cedula); i++){
		suma +=  cedula[i];
	}
	
	return (suma%SIZE);
}

void inciarVector(){
	int i;
	for (i=0; i < SIZE; i++){
		array[i] = NULL;
	}
}

void agregar(char cedula[11], char nombre[50], char apellido[50]){
	
	int i, key;
	
	key = hash(cedula);
	
	persona *nuevo = (persona *)malloc(sizeof(persona));
	persona *actual = (persona *)malloc(sizeof(persona));
	
	strcpy(nuevo->cedula, cedula);
	strcpy(nuevo->nombre, nombre);
	strcpy(nuevo->apellido, apellido);
	nuevo->sig = NULL;
	
	if (array[key] == NULL){
		array[key] = nuevo;
	} else {
		
		actual = array[key];
		
		while (actual->sig != NULL){
			actual = actual->sig;
		}
		
		actual->sig = nuevo;
	}	
}

void buscar(char cedula[11]){
	int i; int key;
	key = hash(cedula);
	
	persona *actual = array[key];
	
	while (actual != NULL){
		if(strcmp(actual->cedula, cedula) == 0){
			printf("Nombre: %s\n", actual->nombre);
			return;
		}
		actual = actual->sig;	
	}
	printf("No existe usuario.\n");
}



void eliminarTabla(){
	int i;
	for	(i = 0; i < SIZE; i++){
		array[i] = eliminarLista(array[i]);
	}
}

void eliminarLista(persona* puntero){
	persona *actual = puntero;
	persona *aux = NULL;
	
	if (actual == NULL){
		return NULL;
	}
	
	while (actual->sig != NULL){
		aux = actual->sig;
		free(actual);
		actual = aux;
	}
	return NULL;
	
}

void mostrarArray(){
	int i;
	for	(i = 0; i < SIZE; i++){
		printf("%d", i);
		mostrarLista(array[i]);
	}
}

void mostrarLista(persona *puntero){
	int i;
	persona *actual = puntero;
	printf("->");
	if (actual == NULL){
		printf("NULL\n");
	} else {
		
		while (actual != NULL){
			printf("%s->",actual->cedula);
			actual = actual->sig;
		}
		printf("NULL\n");
	}

	
}







void main(){
	
	int i; int opcion;
	char nombre[50],apellido[50], cedula[11];

	
	do {
		printf("\n\n**************************************************\n");
		printf("**                    MENU                      **\n");
		printf("**                                              **\n");
		printf("**    1. Agregar persona                        **\n");
		printf("**    2. Buscar persona                         **\n");
		printf("**    3. Mostrar personas                       **\n");
		printf("**    4. Eliminar agenda                        **\n");
		printf("**    5. Salir                                  **\n");
		printf("**                                              **\n");
		printf("**************************************************\n\n");
		
		scanf("%d",&opcion);
		switch (opcion)	 {
			case 1:
				
				printf("Ingresar cedula: ");
				scanf("%s",&cedula);
				
				printf("Ingresar nombre: ");
				scanf("%s",&nombre);
				
				printf("Ingresar apellido: ");
				scanf("%s",&nombre);
				
				agregar(cedula, nombre, apellido);

				break;
			case 2: 
			
				printf("Ingresar cedula: ");
				scanf("%s",&cedula);
				
				buscar(cedula);
				
				break;
			case 3:
				mostrarArray();
				break;
			case 4: 
				eliminarTabla();
				break;
			case 5:
				printf("Fin.");
				break;
			default: 
				break;
		}
	} while (opcion != 5);
	
}
