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
void insertionSort(int [], int, int);
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
        insertionSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        insertionSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    } // End Inner Else    
    
} // End mergeSort()



// insertionSort() Function will sort sub-arrays, using Insertion Sort.
void insertionSort(int a[], int l, int r) // left and right bounds
{
    int i, j;
    int current = 0;


    // For to sort the sub-array
    for (i = l + 1; i < r; i++)
    {
        current = a[i];
        j = i;
        // Comparisons between the sub-array
        while (j > 0 && a[j - 1] > current)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = current;
    } // End For
    
}



// merge() This will merge the separated elements sort them into their respected order.
void merge(int a[], int l, int m, int h)
{
    // Might need a static array
    int transferArray[SIZE] = {0};
    int i, j, k; 
    /*
    What do I need this merge function to do?
    Once the merge is called, it must be used to merge both sides of the array. To do this both arrays will be checked, their start and end will be examined to distinguish 
    where the boundaries are for each set of arrays. Then the first element of both arrays are checked first, lowest will be entered into the new array, then is crossed off the list,
    the next few numbers are checked until both arrays are used up. This function ends and the program returns back into the mergeSort(). 
    */
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


