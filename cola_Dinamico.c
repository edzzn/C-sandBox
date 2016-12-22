#include <stdio.h>
#include <stdlib.h>
int FINAL = 0;
int INICIO = 0;

int * insertar (int * vector, int num){
	
	int i, *vector_aux;
		
	if ((FINAL)==0){ // Ingresamos nuestro primer elemento
		vector[FINAL]=num;
		FINAL++;
		return vector;
	}else{
		vector_aux=realloc(vector, sizeof(int));
		vector[FINAL]=num;
		FINAL++;
	}
	return vector_aux;
}

void mostrarCola(int * vector){
	printf("\nCola:\t");
	int i;
	for(i=0; i<FINAL; i++){
		printf("%3.d", vector[i]);
	}
}

void eliminar ( int *vector){
	
	
	int i;
	if ( FINAL <= 0 ){
		printf("\nLa cola esta vacia\n");
	}
	else if (FINAL > 0){
		
		for (i=0; i<FINAL; i++){
			vector[i]=vector[i+1];
		}
		
		FINAL--;		
	}
}


int topeCola(int vector[]){
	return vector[0];	
}

void esta_llena(int vector[]){
	if(FINAL <= 0){
		printf("La cola esta vacia");
	} else {
		printf("La cola no esta vacia");
	}
}

void main (){
	int opcion, num;
	int *vector; // FF Frente Fijo - Desplazamiento de elementos cada vez que se remueve un elemento
	vector = malloc(sizeof(int));
	
	do {
		
		 printf("\n\nMenu\n\n");
		 printf("1. Insertar\n");
		 printf("2. Eliminar\n");
		 printf("3. LLena\n");
		 printf("4. Tope de Cola\n");
		 printf("5. Mostrar Cola\n");
		 printf("6. Salir\n");
		 scanf("%d",&opcion);
		   
		switch (opcion){
		    case 1: 
	    		printf("Ingrese un numero:\n");
	    		scanf("%d",&num);
				vector= insertar(vector, num);
				break;

		    case 2: 
		    	eliminar(vector);

		        break;
		    case 3:
		    	esta_llena(vector);
		        break;
		    case 4:
		    	printf("El tope de la cola es: %d", topeCola(vector));
		    	break;
		    case 5: 
		    	mostrarCola(vector);
		        break;
		    case 6: 
		    	
		        break;
		    default: 
			 	printf("Opcion no valdia\n");
		        break;
		 } 
  
		
	} while (opcion != 6);
}


