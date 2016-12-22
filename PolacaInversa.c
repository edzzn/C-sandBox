// Reverse Polish Notation 
// 21/12/16


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct operaciones{
	int info;
	struct operaciones* sig;
}Operacion;


void apilar(Operacion **lista, int numero){
	Operacion *nuevo = malloc(sizeof(Operacion));
	nuevo->info = numero;
	nuevo->sig = *lista;
	*lista = nuevo;
}

int desapilar(Operacion **lista){
	Operacion *actual = *lista;
	int n= 0;
	n = actual->info;
	*lista = actual->sig;
	free(actual);
	return n;
} 

void sumar(Operacion **lista){
	int a, b;
	a = desapilar(lista);
	b = desapilar(lista);	
	printf("\n >>>   %d + %d : %d\n", a,b,a+b);
	apilar(lista, a+b);
}

void restar(Operacion **lista){
	int a, b;
	a = desapilar(lista);
	b = desapilar(lista);
	printf("\n >>>   %d - %d : %d\n", a,b,a-b);
	apilar(lista, a-b);
}

void multiplicar(Operacion **lista){
	int a, b;
	a = desapilar(lista);
	b = desapilar(lista);
	printf("\n >>>   %d * %d : %d\n", a,b,a*b);
	apilar(lista, a*b);
}

void dividir(Operacion **lista){
	int a, b;
	a = desapilar(lista);
	b = desapilar(lista);
	printf("\n >>>   %d / %d : %d\n", a,b,a/b);
	apilar(lista, a/b);
}
	
int obtenerInt(int caracter){
	
	if(caracter == 97){
		return 4;
	}else if(caracter == 98) {
		return 5;
	} else if(caracter == 99){
		return 6;
	} else if(caracter == 100){
		return 7;
	} else if(caracter == 101){
		return 8;
	} else {
		printf("Caracter invalido");
		exit(1);
	}
}	

void mostrarPila(Operacion *lista){
	Operacion *aux = lista;
	printf("\n Pila: ");
	while (aux != NULL){
		printf("%3.d",aux->info);
		aux = aux->sig;
	}
	printf("\n");
	
}

main(){
	Operacion *lista = NULL;
	int len= 0, i, n;
	char str[50];
	scanf("%s",str);
	len = strlen(str);
	for (i=0; i<len; i++){
		if(isalpha(str[i])){ //si es una letra
			n = obtenerInt(str[i]);
			apilar(&lista,n);
			mostrarPila(lista);
		} else if((int) str[i] == 43){ // es un '+'
			sumar(&lista);
			mostrarPila(lista);
		} else if((int) str[i] == 45){ // es un '-'
			restar(&lista);
			mostrarPila(lista);
		} else if((int) str[i] == 42){ // es un '*'
			multiplicar(&lista);
			mostrarPila(lista);
		} else if((int) str[i] == 47){ // es un '/'
			dividir(&lista);
			mostrarPila(lista);
		}else {
			printf("Caracter INVALIDO");
			exit(2);
		}
	}
	printf("\n\nResultado: %d", lista->info);
}




