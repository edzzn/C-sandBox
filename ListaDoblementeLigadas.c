//Agenda sencilla

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct personas{
	char nombre[50];
	char telefono[20];
	struct personas *sig;
	struct personas *ant;
}Persona;

void agregarTop(Persona ** inicio, Persona ** fin, char nombre[50], char telefono[20]){
	Persona *nuevo = (Persona *) malloc(sizeof(Persona));
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	strcpy(nuevo->nombre,nombre);
	strcpy(nuevo->telefono,telefono);
	if (*inicio == NULL){
		*inicio = nuevo;
		*fin = nuevo;
	} else{
		nuevo->sig;
		nuevo->sig = *inicio;
		(*inicio)->ant = nuevo;
		*inicio = nuevo;
	}
}

void agregarBot(Persona ** inicio, Persona ** fin, char nombre[50], char telefono[20]){
	Persona *nuevo = (Persona *) malloc(sizeof(Persona));
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	strcpy(nuevo->nombre,nombre);
	strcpy(nuevo->telefono,telefono);
	if(*fin == NULL){
		*inicio = nuevo;
		*fin = nuevo;
	}else{
		nuevo->ant = *fin;
		(*fin)->sig = nuevo;		
		*fin = nuevo;
	}
}

void mostrarTopDown(Persona *incio){
	Persona *actual;
	actual = incio;
	if(actual == NULL){
		printf("No existen registros\n");
	} else{
		while(actual != NULL){
			printf("Nombre: %s\n", actual->nombre);
			printf("Telf.: %s\n", actual->telefono);
			actual = actual->sig;
		}
	}
}
void mostrarBottomUP(Persona *fin){
	Persona *actual;
	actual = fin;
	if(actual == NULL){
		printf("No existen registros\n");
	} else{
		while(actual != NULL){
			printf("Nombre: %s\n", actual->nombre);
			printf("Telf.: %s\n", actual->telefono);
			actual = actual->ant;
		}
	}
}


main(){
	char nombre[50], telefono[20];
	int opcion=0;
	Persona *inicio = NULL, *fin = NULL;

	while(opcion !=6){
		printf("********** Menu **********\n" );
		printf("1. ingresarTop\n");
		printf("2. ingresarBottom\n");
		printf("3. mostrarBottomUp\n");
		printf("4. mostrarTopDown\n");
		printf("6. Salir\n");
		scanf("%d", &opcion);
		switch (opcion) {
			case 1:
				printf("Nombre:");
				scanf("%s",&nombre);
				printf("Telefono:");
				scanf("%s",&telefono);
				agregarTop(&inicio, &fin, nombre, telefono);
				break;
			case 2:
				printf("Nombre:");
				scanf("%s",&nombre);
				printf("Telefono:");
				scanf("%s",&telefono);
				agregarBot(&inicio, &fin, nombre, telefono);
				break;
			case 3:
				mostrarBottomUP(fin);
				break;
			case 4:
				mostrarTopDown(inicio);
				break;
			case 5:
				break;
			case 6:
				break;

				break;
			default:
				break;
		}

	}
}
