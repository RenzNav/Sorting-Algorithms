/*
    Program Description: Merge sort attempt, Code supposed to successfully do merge sort.

    Author: Clarence Navarro

    Date: 8th March 2024
*/

// Header Files
#include <stdio.h>

// Symbolic Names
#define SIZE 10

// Function Signatures
void mergeSort(int [], int, int);
void merge(int [], int, int, int);


int main(void)
{
    // Initialise Variables
    int array[SIZE] = {24, 32, 91, 2, 23, 99, 17, 6, 10, 82};
    int i;
    int low = 0;
    int high = SIZE - 1;


    // Display the original order of the array
    printf("\n\nOriginal Order:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    } // End For


    // Call on the mergeSort() Function
    mergeSort(array, low, high);


    // Display the new sorted order.
    printf("\n\nSorted Order:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    } // End For
    
    return 0;

} // End main



// mergeSort() will be the function to break down the array into individual arrays.
void mergeSort(int arr[], int l, int h)
{
    int mid = 0;


    // Recursive - divides the array until the elements are fully individuals.
    if (l >= h)
    {
        // Causes the pop
        return;
    } // End Inner If
    else
    {
        mid = (h + l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    } // End Inner Else    
    
} // End mergeSort()



// merge() This will merge the separated elements sort them into their respected order.
void merge(int a[], int l, int m, int h)
{
    // Might need a static array
    int transferArray[SIZE] = {0};
    int i, j, k; 
    

    i = l; // Start index for transfer array
    j = l; // Start index for left sub-array
    k = m + 1; // Start Index for right sub-array

    // While loop ensures that all elements within the arrays are used.
    while (j <= m && k <= h )
    {
        // If compares the two arrays, if a[j] is bigger than a[k] then a[k] will be put into the tranferArray[i] first. Then the k++ indicates the sorted part of the array.
        if (a[j] <= a[k])
        {
            transferArray[i] = a[j];
            j++;
        } // End Inner If
        else
        {
            transferArray[i] = a[k];
            k++;
        } // End Inner Else
        i++;
    } // End While

    // While will take care of the rest of the elements within the array that are not dealt with.
    while (j <= m)
    {
        transferArray[i] = a[j];
        i++;
        j++;
    } // End While

    while (k <= h)
    {
        transferArray[i] = a[k];
        i++;
        k++;
    } // End While 

    // This will transfer sorted elements and only sorted elements back into the original array.
    for (j = l; j < i; j++)
    {
        a[j] = transferArray[j];
    } // End For
    
} // End merge()


