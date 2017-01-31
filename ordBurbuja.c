#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int array[] = {5,7,3,2,6,9,7,4,1, 5};


void OrdBurbuja(){
	int i, j, aux;
	for( i =0; i < SIZE; i++){
		for	(j = i; j < SIZE; j++){
			if (array[j] < array[i]){
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
		}
	}
	
}

void mostrarArray(){
	int i;
	for (i=0; i< SIZE; i++){
		printf("%5.d",array[i]);
	}
	printf("\n");
}

main(){
	mostrarArray();
	OrdBurbuja();
	mostrarArray();
	
}
