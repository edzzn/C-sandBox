#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 27

typedef struct palabra{
	char palabra[15];
	struct palabra *sig;
} Palabra;

int f_hash(char valor){ // El valor de la key es la primera letra de la palabra.
	int key = (int) tolower(valor) - 97;
	return key;
}

void insertar(char valor[15], Palabra **hash_table){
	int key = f_hash(valor[0]);
	
	Palabra *nuevo = malloc(sizeof(Palabra));
	Palabra *aux = NULL;
	
	printf("%d",key);
	
	if( hash_table[key] == NULL) printf(" Punteros nulos");
	nuevo->sig = NULL;
	
	//printf("llega");
	strcpy(nuevo->palabra, valor);
	
	if(hash_table[key] == NULL){ // Insertamos el primer item,
		hash_table[key] = nuevo;
	} else{
		aux = hash_table[key];
		while( aux->sig != NULL){
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
	
}

void buscar_palabra(char valor[15], Palabra **hash_table){
	int key = f_hash(valor[0]);
	printf("\n%d\n",key);
	if (strcmp(hash_table[key]->palabra, valor) == 0){ // check the first item in the list
		printf("La palabra %s esta en la tabla\n", hash_table[key]->palabra);
	} else {
			printf("%s != %s",valor, hash_table[key]->palabra );
	}
}

main(){
	Palabra *hash_table[SIZE]; // Inicializamos un vector de Punteros con valores NULL
	int i;
	for (i = 0; i < SIZE-1; i++){
		hash_table[i] = NULL;
	}   
	
	if( hash_table[0] != NULL) printf("Error, Punteros NO nulos");
	
	
//	Palabra *puntero = malloc(sizeof(Palabra));
	char valor[15] = "AsteEsUnaValor";
//	strcpy(puntero->palabra, valor);
	//hash_table[0] = puntero;
	//printf("%s",hash_table[0]->palabra);
	
	insertar(valor, &hash_table);
	insertar("blabla", &hash_table);
	insertar("blablaBLE", &hash_table);
	
	
	printf("\n%s\n",hash_table[0]->palabra);
	printf("\n%s\n",hash_table[1]->palabra);
	printf("\n%s\n",hash_table[1]->sig->palabra);
	buscar_palabra("Hola", &hash_table);



}
