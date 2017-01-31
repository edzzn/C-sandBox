#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

typedef struct persona{
	int cedula;
	char nombre[50];
	char apellido[50];
	struct persona *sig; 
}Persona;

int hash(int cedula){
	return (cedula/7)%7;
}

void ingresar(int cedula, Persona **array[], char nombre[50], char apellido[50]){
	int key = hash(cedula);
	Persona *nuevo = (Persona *) malloc(sizeof(Persona));
	Persona *actual = (Persona *) malloc(sizeof(Persona));
	nuevo->sig = NULL;
	nuevo->cedula = cedula;
	strcpy(nuevo->nombre, nombre);
	strcpy(nuevo->apellido, apellido);
	
	if(array[key] == NULL){
		array[key] = &nuevo;
	} else{
		// Buscar Cedula REPETIDA
		actual = &array[key];
		while(actual->sig != NULL){
			actual = actual->sig;
		}
		actual->sig = nuevo;
	}
}

void mostrarIndice(Persona *array[]){
	int i;
	printf("Vector De Hash\n\n");
	for	(i = 0; i < SIZE; i++){
		printf("Posicion: %d: ", i);
		
	}
	print("\n\n");
}

void mostrarListaLigada(Persona * puntero){
	Persona * actual = (Persona *) malloc(sizeof(Persona));
	printf("->");
	
	if (puntero == NULL){
		printf("NULL\n");
		
	} else {
		Persona *nuevo = puntero;
		
		while(nuevo != NULL){
			printf("%d->", nuevo->cedula);
			nuevo = nuevo->sig;
		}
		printf("NULL\n");
	}
	
}

void buscarCedula(int cedula, Persona *array[]){
	int key = hash(cedula);
//	printf("Key : %p\n", array[key]);
	
	if(array[key] == NULL){
		printf("No se encontro cedula %d.\n", cedula);
	} else{
	//	printf("Entra Al ELSE");
		
		Persona *actual = array[key];
		
		//printf("p: %p\n", actual );
		while(cedula != actual->cedula && actual->sig != NULL){
			actual = actual->sig;
			
//			printf(" B p: %p\n", actual );
//			printf("Entra Al while\n");
		}
			printf("Cedula: %d\nNombre: %s\nApellido: %s\n\n\n", actual->cedula, actual->nombre, actual->apellido);
	}

	
}


main(){
	Persona *array[SIZE];
	int i, cedula;
	for (i = 0; i < SIZE; i++) array[i] = NULL;
	char nombre[50], apellido[50];	
	ingresar(1400757116, &array, "Edisson", "Reinozo"); // key = 6
	ingresar(1400757186, &array, "Eed", "RZ"); // key = 2
	ingresar(1400757166, &array, "Ed6", "RZ6"); // key = 6
	
	
	buscarCedula(1400757166, array);
	buscarCedula(1400757116, array);
	
//	printf("Empieza Busqueda\n");
	buscarCedula(1400757196, array);
	
	//ingresar(cedula, &array, nombre, apellido);
}
