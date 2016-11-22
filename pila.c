#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int info;
	struct Nodo *sig;
};

// longitud de la lista
int longitud(struct Nodo *lista){
	struct Nodo *pAux;// declaramos un puntero auxiliar
	int n = 0; // Contador declarado e inicializado
	pAux = lista;

	while(pAux != NULL){ // Mientras el valor del proximo punto exista
		n++; //Aunmentamos el contador
		pAux = pAux->sig;  //asignamos a pAux el valor del puntero al siguiente nodo
	}
	return n;
}

// definimos que la funcion va a retornar un puntero detipo Nodo
struct Nodo * creaNodo(void){
	return(struct Nodo *) malloc(sizeof(struct Nodo));
 	// reservamos el espacio de memoria
}

// Insertamos un nuevo nodo al inicio de la lista.
struct Nodo * insertarComienzo(struct Nodo *lista, int value){
	struct Nodo *aux = malloc(sizeof(struct Nodo)); // creamos un aux
	aux = creaNodo(); // Inicializamos el nodo
	aux->info = value;
	aux->sig = lista;
	lista = aux;
	return lista;
}

struct Nodo * insertarFinal(struct Nodo *lista, int value){
	struct Nodo *aux, *p;
	aux = creaNodo(); // Crea Nuevo Nodo
	aux->info = value;
	aux->sig = NULL;

	if (lista == NULL){ // si no existe elementos en la lista
		return aux;
	}
	p = lista;

	while (p->sig != NULL){ // Buscamos el fin de la lista
		p = p->sig;
	}
	
	p->sig = aux;
	return lista;
}

// Anula la lista, libera memoria
struct Nodo * anulaLista(struct Nodo *lista){
	struct Nodo *p = NULL; // Aux
	struct Nodo *q = NULL;
	p = lista;

	while(p != NULL){
		q = p->sig; // No perder el nodo
		free(p);
		p = q;
	}
	return NULL;
}

void mostrarLista(struct Nodo *lista){
	struct Nodo *aux = NULL;
	aux = lista;
	while (aux != NULL){
		printf("numero : %d \t", (aux->info));
		aux = aux->sig;
	}

}


int main(int argc, char *argv[]){
	struct Nodo *lista = NULL;
	int num, numero, i;
	printf("\n cuantos n�meros: ");
	scanf("%d", &num);
	for	(i=1; i<=num; i++){
		printf("\n Numero %d: -> ", i);
		scanf("%d", &numero);
		//lista = insertarComienzo(lista, numero);
		lista = insertarFinal(lista, numero);
	}
	printf("\n Tamano Lista %d \n",longitud(lista));
	mostrarLista(lista);
}
