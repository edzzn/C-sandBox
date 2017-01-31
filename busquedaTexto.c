// Busqueda Fuerza Bruta

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
	char texto[] = "Este texto esta listo", patron[] = "texto";
	int i, j, aux = 0, contador = 0;
	for (i = 0; i < strlen(texto) - strlen(patron); i++){
		printf("--------\n");
		for	(j = 0; j < strlen(patron); j++){
			contador++; // llevar la posicion
			
			if(patron[j] == texto[i+j]){
				printf("%c", texto[i+j]);
				aux++;
			} else {
				printf("<-\n");
				break;
			}
			
		}
		
		printf("\n");
		
		if (aux == strlen(patron)){
			printf("Evaluado: %d\npatron en: [%d][%d]",j,i,i+j-1);
		} else{
			printf("Veces evaluadas: %d ", j);
		}
		printf("\n");
		aux= 0;
	}
}
