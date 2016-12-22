#include <stdio.h>
int INICIO = 0;
int FINAL = 0;


void insertar(int vector[], int nuevo_elemento){
	if( FINAL >= sizeof(vector) ){
		printf("La cola esta llena");
	}else{
		vector[FINAL]	= nuevo_elemento;	
		FINAL++;
	}	
}

void eliminar (int vector[]){
	// Creamos un vector aux de los elementos
	int i, v_aux[sizeof(vector)];
	for(i = 0; i < FINAL; i++){
		v_aux[i] = vector[i];
	} // desplazamos los elementos
	for(i = 0; i < FINAL-1; i++){
		vector[i] = v_aux[i+1];
	}
	FINAL--;
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


void mostrarCola(int vector[]){
	int i;
	
	printf("\nCola:  ");
	for	(i=0; i <= FINAL; i++){
		printf("%4.d", vector[i]);
	}
	printf("\n");
}



void main (){
	int opcion, num;
	int cola_FF[10]; // FF Frente Fijo - Desplazamiento de elementos cada vez que se remueve un elemento
	
	
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
				insertar(cola_FF, num);

		        break;
		    case 2: 
		    	eliminar(cola_FF);

		        break;
		    case 3:
		    	esta_llena(cola_FF);
		        break;
		    case 4:
		    	printf("El tope de la cola es: %d", topeCola(cola_FF));
		    	break;
		    case 5: 
		    	mostrarCola(cola_FF);
		        break;
		    case 6: 
		    	
		        break;
		    default: 
			 	printf("Opcion no valdia\n");
		        break;
		 } 
  
		
	} while (opcion != 6);
}
