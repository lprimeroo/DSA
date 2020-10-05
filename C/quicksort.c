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


For bettter understanding you can use this code also for beginers level;

// Quick sort in C

#include <stdio.h>

// Function to swap position of elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Function to partition the array on the basis of pivot element
int partition(int array[], int low, int high) {
  
  // Select the pivot element
  int pivot = array[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left 
  // and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // Select pivot position and put all the elements smaller 
    // than pivot on left and greater than pivot on right
    int pi = partition(array, low, high);
    
    // Sort the elements on the left of pivot
    quickSort(array, low, pi - 1);
    
    // Sort the elements on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// Function to print eklements of an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 6};
  int n = sizeof(data) / sizeof(data[0]);
  quickSort(data, 0, n - 1);
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}
