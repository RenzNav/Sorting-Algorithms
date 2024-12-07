/*

    Program Description: Program sorts an array using selective sorting.

    Author: Clarence Navarro

    Date: 24th February 2024

*/

#include <stdio.h>

#define SIZE 8

// Function Signatures
void swap(int [], int, int);
void display(int []);


int main(void) 
{

    // Variables Initialised
    int array[SIZE] = {3, 1, 8, 7, 2, 4, 6, 5};
    int i, j;
    int min = 0;
    int smallest = 0;
    int sorted = 0;

    // Display original order of the array.
    printf("\n\nOriginal Order:\n");
    display(array);

    // For goes through the array to find the numbers for sorting.
    for (i = 0; i < SIZE - 1 && sorted == 0; i++)
    {
        // This will be used to indicate whether the code is sorted or not. Code will end early if sorted.
        sorted = 1;

        // Resetting variables after each loop.
        smallest = i;
        for (j = i + 1; j < SIZE; j++)
        {

            if (array[j] < array[smallest])
            {

                smallest = j;
                sorted = 0;

            } // End if   
        
        } // End for
        swap(array, i, smallest); // This function will swap the minimum, from one phase. with the indexed number of the given phase in the loop.
   
    } // End for

    // Displays the new order of the array.
    printf("\nNew Order:\n");
    display(array);
    

    return 0;

} // End main

// Worst Case for selection sort is N^2 and worst is also N^2

// Swap Function
void swap(int arr[], int i, int loc)
{

    int temp = 0;

    temp = arr[i];
    arr[i] = arr[loc];
    arr[loc] = temp;

} // End swap()



// Display Function
void display(int arr[])
{

    int i;

    // Prints out the content of the array.
    for (i = 0; i < SIZE; i++)
    {

        // Prevents comma in the last element
        if (i < SIZE - 1)
        {

            printf("%d,", arr[i]);
        
        } // End inner if
        else
        {

            printf("%d", arr[i]);
        
        } // End inner else

    } // End for
    
} // End display()