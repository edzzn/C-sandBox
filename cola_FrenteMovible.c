#include <stdio.h>
int INICIO = 0;
int FINAL = 0;

void insertar(int vector[], int nuevo_elemento){
	if(INICIO == 0 && FINAL >= sizeof(vector)+1){
		
		printf("La cola esta llena");
	} else if(FINAL >= sizeof(vector)+1 && INICIO != 0) { //desplazamos el vector para hacer espacio.
		int i, v_aux[sizeof(vector)];
		for(i = 0; i <= FINAL; i++){
			v_aux[i] = vector[i];
		}
		printf("desplazando elementos");
		 // desplazamos los elementos
		for(i = 0; i <= FINAL-INICIO; i++){
			vector[i] = v_aux[INICIO + i];
		}
		vector[FINAL]	= nuevo_elemento;
		FINAL++;		
	} else{
		vector[FINAL]	= nuevo_elemento;
		FINAL++;	
	}
}

void eliminar (int vector[]){
	if(FINAL <= 0)	{
		printf("No existen elementos para eliminar.");
	} else {
		INICIO++;
		
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



void mostrarCola(int vector[]){
	int i;
	
	printf("\nCola:  ");
	for	(i = INICIO; i <= FINAL; i++){
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
	    		printf("Ini: %d, Fin: %d", INICIO, FINAL);
				insertar(cola_FF, num);
				
		        break;
		    case 2: 
				eliminar(cola_FF); // simplemente movemos el INICIO del vector
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
