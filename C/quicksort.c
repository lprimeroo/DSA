Quicksort is an algorithm based on divide and conquer approach in which the array is split into subarrays and these sub-arrays are recursively called to sort the elements.


// LANGUAGE: C
// AUTHOR: Nathalia-b
// GITHUB: https://github.com/nathalia-b

#include <stdio.h>

int part(int vector[], int start, int end){

	int pivo = vector[end]; 
	int P = start; 
	int i, aux; 

	for(i = start; i<end; i++){
		if(vector[i] <= pivo){	
			int temp;
			temp = vector[i];
			vector[i] = vector[P];
			vector[P] = temp;
			P++; 

		}
	}

	int temp;
	temp = vector[end];
	vector[end] = vector[P];
	vector[P] = temp;
	return P;
}

 void Quicksort(int vector[],int start,int end)
 {
    if(start<end)
    {
         int P = part(vector,start,end);
             Quicksort(vector,start,P-1);
             Quicksort(vector,P+1,end);
             
    }
}

int main(){

int size;
printf("Insert how many numbers you want to sort:\t");
scanf("%i", &size);
int vector[size];
printf("Insert your elements:\t");

for(int i = 0; i<size; i++){
	scanf("%i",&vector[i]);
}
printf("\n\tB E F O R E\n");
for(int i = 0; i<size; i++){
	printf("%i ", vector[i]);
}
printf("\n");
Quicksort(vector,0,size-1);

printf("\n\tA F T E R\n");
for(int i = 0; i<size; i++){
	printf("%i ", vector[i]);
}
printf("\n");

}
