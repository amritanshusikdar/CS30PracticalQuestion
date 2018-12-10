//  Program to swap every even with following odd location of an integer array

#include<iostream.h>
#include<conio.h>
#define size 10

void oddEvenSwap(int*, int);

int main()
{
    clrscr();

    int array[size] = {1,2,3,4,5,6,7,8,9,10}, i;

    cout << "Original array: " << endl;

    for(i=0; i < size; i++)
    {
        cout << "A[" << i << "]:" << *(array+i) << endl;
    }

    oddEvenSwap(array, size);

    cout << "Swapped array: " << endl;

    for(i=0; i < size; i++)
    {
        cout << "A[" << i << "]:" << *(array+i) << endl;
    }

    getch();
    return 0;
}

void oddEvenSwap(int *array, int limit)
{
    int i=0, check=1, temp;

    while(i < limit && check == 1)
    {
        temp = *(array+i);
        *(array+i) = *(array+i+1);
        *(array+i+1) = temp;

        i += 2;

        if(limit % 2 != 0 && i == limit-1)
            check = -1;

    }
}
