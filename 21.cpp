/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

// Program representing binary search in a Sorted Array of integers

#include <constream.h>
#include <stdio.h>

//  User defined function prototypes
void input_data(int*, int);
void binary_search(int*, int, int);

void main()
{
    clrscr();

    int *list, search;
    int size=10;

    list = new int[size];

    input_data(list, size);

    cout << "Enter element to be searched: ";
    cin >> search;

    cout << "\n\n";

    binary_search(list, size, search);

    delete list;
    getch();
}


void input_data(int *array, int size)
{
    for(int i=0; i < size; i++)
    {
        cout << "Element " << i+1 << ": ";
        cin >> array[i];
    }
}

void binary_search(int *array, int size, int number)
{
    int first = 0, last = size-1, middle, position = -1;

    while(first <= last && position == -1)
    {
        middle = (first + last) / 2;

        if(array[middle] == number)
        {
            position = middle;
        }

        if(array[middle] > number)
        {
            last = middle-1;
        } else {
            first = middle+1;
        }
    }

    if (position == -1)
    {
        cout << "Entered number \'" << number << "\' not found!" << endl;
    } else {
        cout << "Entered number found!" << endl;
        cout << "Requested for: " << number << endl;
        cout << "Matches with element number: " << position + 1 << endl;
    }
}
