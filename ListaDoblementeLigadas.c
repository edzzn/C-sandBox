#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct personas{
	char nombre[50];
	char telefono[20];	
	struct persona *sig;
	struct persona *ant;
}persona;


void agregarTop(persona *inicio, persona *fin, char nombre[50], char telefono[20] ){
	persona *nuevo = (persona *) malloc(sizeof(persona));
	strcpy(nuevo->nombre, nombre);
	strcpy(nuevo->telefono, telefono);
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	printf("\n %p\n", nuevo);

	if (inicio == NULL){
		inicio = nuevo;
		fin = nuevo;
	} else{
		//nuevo = Inicio;
		nuevo->sig = inicio;
		inicio = nuevo;
	}
	
}

void mostrarTopBottom(persona **inicio, persona **fin){
	persona *actual;
	actual = inicio;
	if (actual == NULL){
		printf("La lista esta vacia\n");
	} else {
		while (actual->sig != NULL){
			printf("Nombre: %s\n", actual->nombre);
			printf("Telefono: %s\n", actual->telefono);
			actual = actual->sig;
		}
	}
}


int main( ){
	persona *inicio = NULL;
	persona *fin = NULL;
	printf("\n %p\n", inicio);

	char nombre[50], telefono[20];
	int opcion = 0;
	
	while (opcion != 6){
		printf("************* Agenga *************\n");
		printf("1. Agregar un contacto\n");
		printf("2.\n");
		printf("3.\n");
		printf("4. Mostrar contactos\n");
		printf("6. Salir\n");
		scanf("%d", &opcion);
		switch (opcion){
			case 1:
				printf("Nombre:");
				scanf("%s",nombre);
				printf("telefono:");
				scanf("%s",telefono);
				agregarTop(inicio, fin, nombre, telefono);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				mostrarTopBottom(inicio, fin);
				break;
			case 5:
				break;
			case 6:
				printf ("Gracias por usar nuestro programa");
				break;
			default:
				break;
		}
	}
		
}



