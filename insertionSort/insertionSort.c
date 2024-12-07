// Program Insertion Sort

#include <stdio.h>

#define SIZE 8
int main(void)
{
    int array[SIZE] = {5, 7, 6, 8, 9, 10, 12, 11};
    int i = 0;
    int j = 0;
    int current = 0;

    for (i = 1; i < SIZE; i++)
    {
        current = array[i]; // current 1
        j = i;
        while (j > 0 && array[j - 1] > current)
        {
            array[j] = array[j - 1]; // a0 is 3, this value is now assigned to a1, a1 = 3
            j = j - 1; // j is now 0
        }
        array[j] = current; // current (1) will be placed into a0, so a0 is now 1 
    }

    for  (i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    
    return 0;

}

