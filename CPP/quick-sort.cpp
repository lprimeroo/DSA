#include <iostream>
using namespace std;

int particionar(int vetor[], int inicio, int fim){

	int pivo = vetor[fim]; 
	int P = inicio; 
	int i, aux; 

	for(i = inicio; i<fim; i++){
		if(vetor[i] <= pivo){	
			
			swap(vetor[i], vetor[P]); 
			P++; 

		}
	}

	swap(vetor[fim], vetor[P]); 
	cout << P;
	return P;
}

 void Quicksort(int vetor[],int inicio,int fim)
 {
    if(inicio<fim)
    {
         int P = particionar(vetor,inicio,fim);
             Quicksort(vetor,inicio,P-1);
             Quicksort(vetor,P+1,fim);
             cout << " \n";
    }
}

int main(){

int vetor[6];
cout << "INsert your elements\n";

for(int i = 0; i<6; i++){
	cint >> vetor[i];
}

for(int i = 0; i<6; i++){
	cout << vetor[i] << " ";
}
cout << "\n\n";
Quicksort(vetor,0,6-1);

for(int i = 0; i<6; i++){
	cout << vetor[i] << " ";
}

}