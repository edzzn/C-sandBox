#include <stdio.h>
#include <stdlib.h>
// Agenda

struct Agenda {
	char nombre[20]	;
	char telefono[12];
	struct Agenda *siguiente;
};

struct Agenda *crearAgenda(){ // Crea un Nodo de tipo agenda.
	return (struct Agenda *) malloc(sizeof(struct Agenda)); // reserva espacio para la agenda
};

struct Agenda *apilar(struct Agenda *lista, char nombre_nuevo[20], char telefono_nuevo[12]){
	struct Agenda *aux = malloc(sizeof(struct Agenda)); //creamos un puntero auxiliar, nuevo NODO
	aux = crearAgenda();
	strcpy(aux->nombre,nombre_nuevo);
	strcpy(aux->telefono, telefono_nuevo);
	aux->siguiente = lista;
	lista  = aux;
	return lista;
};

struct Agenda *insertarFinal(struct Agenda *lista, char nombre_nuevo[20], char telefono_nuevo[12]){
	struct Agenda *aux = malloc(sizeof(struct Agenda));
	struct Agenda *p = NULL;
	
	aux = crearAgenda();
	p = lista;
	strcpy(aux->nombre, nombre_nuevo);
	strcpy(aux->telefono, telefono_nuevo);
	aux->siguiente = NULL;
	
	if(lista == NULL){
		return aux;
	}
	
	p = lista;
	
	// Buscamos el final
	while (p->siguiente != NULL){
		p = p->siguiente;
	}
	
	p->siguiente = aux;
	return lista;
};

void listarAgenda(struct Agenda *lista){
	struct Agenda *aux = NULL;
	aux = lista;
	while(aux != NULL){
		printf("Nombre: %s \n", (aux->nombre));
		printf("Telefono: %s \n", (aux->telefono));
		aux = aux->siguiente;
	}
};

int main(int argc, char *argv[]){
	struct Agenda *lista = NULL;
	int n, i;
	char nombre[20], telefono[12];
	printf("Cuantos contactos desea ingresar: ");
	scanf("%d", &n);
	for	(i = 1; i <= n; i++){
		printf("\n Ingrese el contacto N: %d",i);
		printf("\n Nombre: ");
		scanf("%s", &nombre);
		printf("Telefono: ");
		scanf("%s", &telefono);
		lista = insertarFinal(lista, nombre, telefono);
		//lista = apilar(lista, nombre, telefono);
	}
	printf("\nMostrar lista:\n");
	listarAgenda(lista);
	return 0;
}
