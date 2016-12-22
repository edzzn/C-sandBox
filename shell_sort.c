#include<stdio.h>
#define MAX 20


void main(){
	int arr[MAX], i,j,k,n,incr;
	printf ("\nIngresa el numero de elementos : ");
	scanf ("%d",&n);
	for (i=0;i < n;i++)	{
		printf ("\nIngresa un elemento %d : ",i+1);
		scanf ("%d",&arr[i]);
	}
	
	printf ("\nLista desordenada :\n");
	for (i = 0; i < n; i++)	printf ("%d ", arr[i]);
	
	/*Shell sort */
	incr = n / 2;
	while(incr>=1){
		for (j=incr;j<n;j++){
			k=arr[j];
			for(i = j-incr; i >= 0 && k < arr[i]; i = i-incr){
				arr[i+incr]=arr[i];
			}	
			arr[i+incr]=k;
		}
		
		printf ("\nIncremento=%d \n",incr);
		for (i = 0; i < n; i++)	printf("%d ", arr[i]); // muestra vector
		
		printf ("\n");
		incr = (int) (incr/2); /*Incremento es incr/2*/
	}/*fin while*/
	
	printf ("\nLista ordenada :\n");
	
	for (i = 0; i < n; i++)	printf ("%d ", arr[i]); // muestra vector

}/*fin main()*/
