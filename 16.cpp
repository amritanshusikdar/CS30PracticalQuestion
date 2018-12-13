/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to swap odd places of 2 arrays

#include <constream.h>

void input(int*, int*);
void transfer(int*, int*);
void display(int*, int*);

void main()
{
    clrscr();

    int a[6], b[6];

    input(a,b);
    transfer(a,b);
    cout << "\nAfter Swapping odd places:- \n";
    display(a,b);

    getch();
}

void input(int a[6], int b[6])
{
    int i;

    cout << "Input in first array!" << endl;
    for(i=0; i<6; i++)
    {
        cout << "A[" << i << "]: ";
        cin >> a[i];
    }

    cout << "Input in second array!" << endl;
    for(i=0; i<6; i++)
    {
        cout << "B[" << i << "]: ";
        cin >> b[i];
    }
}

void transfer(int a[6], int b[6])
{
    int i, temp;

    for(i=0; i<6; i++)
    {
        if(i % 2 == 1)
        {
            temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
    }
}


void display(int a[6], int b[6])
{
    int i;

    cout << "First array!" << endl;
    for(i=0; i<6; i++)
    {
        cout << "A[" << i << "]: " << a[i] << endl;
    }

    cout << "Second array!" << endl;
    for(i=0; i<6; i++)
    {
        cout << "B[" << i << "]: " << b[i] << endl;
    }
}
