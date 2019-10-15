// LANGUAGE: C
// AUTHOR: Nathalia-b
// GITHUB: https://github.com/nathalia-b

#include <stdio.h>

int particionar(int vetor[], int start, int end){

	int pivo = vetor[end]; 
	int P = start; 
	int i, aux; 

	for(i = start; i<end; i++){
		if(vetor[i] <= pivo){	
			int temp;
			temp = vetor[i];
			vetor[i] = vetor[P];
			vetor[P] = temp;
			P++; 

		}
	}

	int temp;
	temp = vetor[end];
	vetor[end] = vetor[P];
	vetor[P] = temp;
	return P;
}

 void Quicksort(int vetor[],int start,int end)
 {
    if(start<end)
    {
         int P = particionar(vetor,start,end);
             Quicksort(vetor,start,P-1);
             Quicksort(vetor,P+1,end);
             
    }
}

int main(){

int size;
printf("Insert how many numbers you want to sort:\t");
scanf("%i", &size);
int vetor[size];
printf("Insert your elements:\t");

for(int i = 0; i<size; i++){
	scanf("%i",&vetor[i]);
}
printf("\n\tB E F O R E\n");
for(int i = 0; i<size; i++){
	printf("%i ", vetor[i]);
}
printf("\n");
Quicksort(vetor,0,size-1);

printf("\n\tA F T E R\n");
for(int i = 0; i<size; i++){
	printf("%i ", vetor[i]);
}
printf("\n");

}