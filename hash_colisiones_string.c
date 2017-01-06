#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10 //Constante (Tamaño del Vector)

//Probar con 4 y 14 (Colision)

typedef struct nodo{ //Estructura del nodo
	
	char cedula[11];
	char nombre[50];
	struct nodo* next;
	
}nodo;

nodo * vector[SIZE]; //Vector de Hash

//Prototipado de las Funciones
int hash(char[11]);
void mostrar2();
void agregar(char[11],char[50]);
void eliminar(nodo**,int);
void mostrar(nodo*);
void iniciarVector();
void buscarPersona(char[11]);

int main(){
	
	iniciarVector();
	mostrar2();
	agregar("0105817258","Carlos");
	agregar("0106789123","Fabian");
	agregar("0367123123","Ernesto");
	mostrar2();
	buscarPersona("0105817258");
	return 0;
	
}

int hash(char clave[11]){ //Funcion Hash (Puede ser modificada)
	
	int i;
	int suma = 0;
	for(i = 0; i < strlen(clave); i++){
		
		suma += clave[i];
		
	}
	return (suma%SIZE);
	
}

void iniciarVector(){ //Inicializar los punteros del vector en NULL
	
	int i;
	for(i = 0; i < SIZE; i++){
		
		vector[i] = NULL;
		
	}
	
	
}

void buscarPersona(char clave[11]){ //Funcion para buscar personas
	
	nodo * aux = vector[hash(clave)];
	while(aux != NULL){
			
		if(strcmp(aux->cedula,clave) == 0){
			
			printf("El nombre es: %s",aux->nombre);
			return;
			
		}
		aux = aux->next;
			
	}
	printf("No existe el valor");
	
}

/*void eliminar(nodo** puntero,int a){
	
	nodo* aux = (nodo*)malloc(sizeof(nodo));
	nodo* ant = (nodo*)malloc(sizeof(nodo));
	if(*puntero == NULL){
		
		printf("No hay naranjas!\n");
		
	}else if((*puntero)->n == a){
	
		*puntero = (*puntero)->next;
	
	}else{
		
		aux = *puntero;
		while(aux != NULL){
			
			
			if(aux->n == a){

				break;

			}
			ant = aux;
			aux = aux->next; 
			
		}
		if(aux == NULL){
			
			printf("No hay nada!\n");
			
		}else{
			
			printf("Si hay algo!\n");
			ant->next = aux->next;
			
		}
		
		
	}
	
}*/

void agregar(char clave[11], char nombre[50]){ //Agregar un nuevo nodo en el vector de hash
	
	nodo* aux = (nodo*)malloc(sizeof(nodo));
	nodo* aux2 = (nodo*)malloc(sizeof(nodo));
	strcpy(aux->cedula,clave);
	strcpy(aux->nombre,nombre);
	aux->next = NULL;
	if(vector[hash(clave)] == NULL){
		
		vector[hash(clave)] = aux;
		
	}else{
		
		aux2 = vector[hash(clave)];
		while(aux2->next != NULL){
			
			aux2 = aux2->next; 
			
		}
		aux2->next = aux;
		
	}
	
}

void mostrar2(){ //Mostrar cada indice del vector de hash
	
	int i;
	printf("VECTOR DE HASH\n\n");
	for(i = 0; i < SIZE; i++){

		printf("Posicion %d: ",i);
		mostrar(vector[i]);
		
	}
	printf("\n\n");
	
}

void mostrar(nodo* puntero){ //Mostrar la lista ligada
	
	nodo* aux = (nodo*)malloc(sizeof(nodo));
	printf("->");
	if(puntero == NULL){
		
		printf("NULL\n");
		
	}else{
		
		aux = puntero;
		while(aux != NULL){
			
			printf("%s->",aux->cedula);
			aux = aux->next; 
			
		}
		printf("NULL\n");
		
	}
	
}
