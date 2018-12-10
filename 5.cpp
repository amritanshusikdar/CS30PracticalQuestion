/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to accept 10 numbers and print in descending order using Bubble Sort

#include<iostream.h>
#include<conio.h>

void input(int *array);
void BubSort(int *array);
void display(int *array);

void main()
{
    clrscr();

    int *array;

    input(array);
    BubSort(array);
    display(array);

    getch();
}

void input(int *array)
{
    for(int i=0; i<10; i++)
    {
        cout << "A[" << i+1 << "]: ";
        cin >> *(array+i);
    }
    cout << "Input Successful! \n\n";
}

void BubSort(int *array)
{
    int i = 0, j, temp;

    do
    {
        for(j = 0; j < 10-i-1; j++)
        {
            if(*(array+j) > *(array+j+1))
            {
                temp = *(array+j);
                *(array+j) = *(array+j+1);
                *(array+j+1) = temp;
            }
        }
        i++;
    }while(i < 10);
}

void display(int *array)
{
    for(int i=9; i>=0; i--)
    {
        cout << "A[" << i+1 << "]: " << *(array+i) << endl;
    }
}
