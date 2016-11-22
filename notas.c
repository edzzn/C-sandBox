//gestor de notas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nota{	
	char info[140];
	struct Nota *siguiente;
};

// Reservar espacio de memorioa
struct Nota *crearNota(){
	return (struct Nota *) malloc(sizeof(struct Nota)); // struct Nota o Struct Nota *
}

struct Nota *apilar(struct Nota *lista, char info[140]){ //Puede ser NULL en la primera pasada
	struct Nota *aux;
	aux = crearNota();
	strcpy(aux->info,info);
	aux->siguiente = lista;
	lista = aux;
	return lista;
}

struct Nota *cola(struct Nota *lista, char info[140]){
	struct Nota *aux, *pre;
	aux = crearNota();
	strcpy(aux->info, info);
	aux->siguiente = NULL; // NULL es el final
	
	if (lista == NULL){
		return aux;
	}
	
	pre = lista;
	// buscamos la posicion Final
	while(pre->siguiente != NULL){
		pre  = pre->siguiente;
	}
	pre->siguiente = aux;
	return lista;
}

struct Nota *anularLista(struct Nota *lista){
	struct Nota *p, *q;
	p = lista;
	while(p->siguiente != NULL){
		q = p->siguiente;
		free(p);
		p = q;
	}
	return NULL;
}

void mostrarNotas(struct Nota *lista){
	if (lista == NULL){ printf("No existen Notas guardadas.\n");}
	else{
		struct Nota *aux;
		aux = lista;
		while(aux != NULL)	{
			printf("Nota: %s \n", aux->info);
			aux = aux->siguiente;
		}
	}	
}

int main(){
	struct Nota *lista = NULL;
	int n = 0;
	char nota[140];
	while ( n != 5){
		printf("\n****  MENU ****\n");
		printf("1.- Agregar una nota (Apilar)\n");
		printf("2.- Agregar una nota (Colar)\n");
		printf("3.- Listar Notas\n");
		printf("5.- Finalizar programa\n");
		scanf("%d",&n);
		switch(n){
			case 1:
				printf("Ingrese la Nota (140): ");
				scanf("%s",&nota);
				lista = apilar(lista, nota);
				break;
			case 2:
				printf("Ingrese la Nota (140): ");
				scanf("%s",&nota);
				lista = cola(lista, nota);
				break;
			case 3:
				mostrarNotas(lista);
				break;
			case 5:
				printf("Gracias por usar el programa");
				lista = anularLista(lista);
				free(lista);
				break;
			default:
				printf("Opcion no valida, intente nuevamente.");
				break;
		}
		
	}
	return 0;
}











