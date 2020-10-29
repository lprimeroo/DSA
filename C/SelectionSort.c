#include <stdio.h>
// Function to swap elements
//Code is Written By Krishna
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Selection Sort
void selectionSort(int array[], int n)
{
    int i, j, min_element;
    for (i = 0; i < n - 1; i++)
    {
        min_element = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[min_element])
                min_element = j;
        swap(&array[min_element], &array[i]);
    }
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
    int array[] = {15, 10, 99, 53, 36};
    int size = sizeof(array) / sizeof(array[0]);
    selectionSort(array, size);
    printf("Sorted array: ");
    printArray(array, size);
    return 0;
}