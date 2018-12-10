/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to swap half of the integer array with the other half

#include<iostream.h>
#include<conio.h>
#define size 10

void halfSwap(int*, int);

int main()
{
    clrscr();
    int i;
    int array[size] = {1,2,3,4,5,6,7,8,9,10};

    cout << "Original array: " << endl;

    for(i=0; i < size; i++)
    {
        cout << "A[" << i << "]:" << *(array+i) << endl;
    }

    halfSwap(array, size);

    cout << "Swapped array: " << endl;

    for(i=0; i < size; i++)
    {
        cout << "A[" << i << "]:" << *(array+i) << endl;
    }

    getch();
    return 0;
}

void halfSwap(int *array, int limit)
{
    int i, j, condition, temp;

    for(i=0,j=limit/2; i < limit/2; i++,j++)
    {
        temp = *(array+i);
        *(array+i) = *(array+j);
        *(array+j) = temp;
    }
}
