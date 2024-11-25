#include <stdio.h> // standard io 


int a = 0; // acceleration 
int v = 0; // velocity
int t = 0; // time

int main(int argc, int *argv[])
{ /* main */

	int arr[1000]; // arr of size 1000 (hope this is enough)
	int i = 0;

	for(i = 0; scanf("%d %d", &v, &t) == 2); i++)
     	{ /* f */ 
		arr[i] = t * v * 2; // displacement in double this time	
	} /* f */ 
	
	for(i = 0; i < sizeof(arr) - 1; i++)
	{ /* f */ 
		printf("%d\n", arr[0]);	
	} /* f */ 

	return 0;

} /* main */ 
