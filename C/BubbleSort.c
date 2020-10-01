#include <stdio.h>
// Function to swap elements
//Code is Written By Krishna
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// bubble sort function
void bubbleSort(int array[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
}
// Function to print the elements of an array
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("n");
}
// Main Function
int main()
{
    int array[] = {89, 32, 20, 113, -15};
    int size = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, size);
    printf("Sorted array: ");
    printArray(array, size);
    return 0;
}