#include<stdio.h>
#define MAX 10


void main(){	
	srand(time(NULL)); //
	int arr[MAX], i,j,k,l, incr, num_comp, n, sum_comp=0, num_max, num_min=999999;
	n = MAX;
	for (l=0; l < 10; l++){ // Realizamos esta comparacion 
		num_comp = 0;
	
		for (i=0;i < n;i++) arr[i] = (rand() % (99))+1;
		
		
		printf ("\nLista desordenada :\n");
		for (i = 0; i < n; i++)	printf ("%3.d ", arr[i]);
		
		
		/*Shell sort */
		incr = n / 2;
		while(incr>=1){
			for (j=incr;j<n;j++){
				k=arr[j];
				for(i = j-incr; i >= 0 && k < arr[i]; i = i-incr){
					arr[i+incr]=arr[i];
					num_comp++;
				}
				arr[i+incr]=k;
			}
			
			//printf ("\nIncremento=%d \n",incr);
			//for (i = 0; i < n; i++)	printf("%3.d ", arr[i]); // muestra vector
			
		//	printf ("\n");
			incr = (int) (incr/2); /*Incremento es incr/2*/
		}/*fin while*/
		
		printf ("\nLista ordenada :\n");
		
		for (i = 0; i < n; i++)	printf ("%3.d ", arr[i]); // muestra vector
		
		printf("\n Numero de comparaciones: %d\n", num_comp);
		sum_comp = sum_comp + num_comp;
		if(num_comp > num_max) num_max = num_comp;
		if(num_comp < num_min) num_min = num_comp;
	}
	printf("\n\n Para %d ", MAX);
	printf("\n\n Promedio de comparaciones: %d", sum_comp/10);
	printf("\n\n Maximo Numero de comparaciones: %d", num_max);
	printf("\n\n Minimo Numero de comparaciones: %d", num_min);

}/*fin main()*/
