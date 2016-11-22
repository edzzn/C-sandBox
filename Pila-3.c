#include <stdio.h>
#include <stdlib.h> //malloc, sizeof
#include <string.h> // copiar char[] - strcpy(Fin,Inicio); 
struct Agenda{
	char nombre[30];
	char telefono[12];
	struct Agenda *siguiente;
};

struct Agenda *crearAgenda(){
	return (struct Agenda *) malloc(sizeof(struct Agenda));
}

struct Agenda *apilar(struct Agenda *lista, char nombre_n[30], char telf_n[12] ){
	//struct Agenda *aux = malloc(sizeof(struct Agenda));
	struct Agenda *aux = crearAgenda();
	
	if(aux==NULL){
		printf("No hay memoria disponible!");
		exit(EXIT_FAILURE);
	}

	strcpy(aux->nombre,nombre_n);
	strcpy(aux->telefono,telf_n);
	aux->siguiente = lista;
	lista = aux;
	return lista;	
}

//Elimina el elemento en el tope
struct Agenda *desapilar(struct Agenda *lista){
	struct Agenda *aux;
	aux = lista->siguiente;
	free(lista);
	return aux;
}


struct Agenda *cola(struct Agenda *lista, char nombre_n[30], char telf_n[12]){
	struct Agenda *aux, *pre;
	aux = crearAgenda();
	if(aux == NULL){
		printf("ERROR de Memoria.");
		exit(1);
	}	
	//lenamos aux
	strcpy(aux->nombre,nombre_n);
	strcpy(aux->telefono,telf_n);
	aux->siguiente = NULL;
	if (lista == NULL){
		return aux;
	}
	pre = lista;
	while (pre->siguiente != NULL){
		pre = pre->siguiente;
	}
	pre->siguiente = aux;
	return lista;
}


struct Agenda *anularLista(struct Agenda *lista){
	struct Agenda *p,*q;
	p = lista;
	while (p != NULL){
		q = p->siguiente;
		free(p);
		p = q;
	}
	return NULL;	
}

void mostrarAgenda(struct Agenda *lista){
	struct Agenda *aux = NULL;
	aux = lista;
	printf("\n *** Lista de contactos *** \n");
	while (aux != NULL){
		printf("nombre: %s ", aux->nombre);
		printf("Telf: %s \n", aux->telefono);
		aux = aux->siguiente;
	}
}

int main(){
	struct Agenda *lista = NULL;
	menu(lista);
		
}

int menu(struct Agenda *lista){
	
	char nombre[30], telefono[12];	
	int condicion;
	printf("\n********** Menu **********\n");
	printf("1.- Ingresar un contacto, Pila:\n");
	printf("2.- Ingresar un contacto, Cola:\n");
	printf("3.- Mostrar todos los contactos\n");
	printf("4.- Desapilar\n");
	printf("5.- Salir\n");
	scanf("%d",&condicion);	
	switch(condicion){
		case 1:
			printf("Ingrese el Nombre:");
			scanf("%s", &nombre);
			printf("Ingrese el telefono:");
			scanf("%s", &telefono);
			lista = apilar(lista, nombre, telefono);
			menu(lista);
		case 2:
			printf("Ingrese el Nombre:");
			scanf("%s", &nombre);
			printf("Ingrese el telefono:");
			scanf("%s", &telefono);
			lista = cola(lista, nombre, telefono);
			menu(lista);
		case 3:
			mostrarAgenda(lista);
			menu(lista);
		case 4:
			lista = desapilar(lista);
			menu(lista);
		case 5:
			printf("Gracias por usar el programa");
			lista = anularLista(lista);
			free(lista);
			exit(0);
		default:
		printf("Opcion no es valida");
		menu(lista);
	}
	return 0;
}
