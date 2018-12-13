/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Find sum of all alternate elements of a 2D Array

#include <constream.h>

int alterSum(int a[][5], int, int);

void main()
{
    clrscr();

    int i, j;
    int arr[5][5], sum;

    //  Input

    for (i=0; i < 5; i++)
    {
        for (j=0; j < 5; j++)
        {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }


    //  Getting the sum of alternate elements

    sum = alterSum(arr,5,5);


    //  Output

    cout << "Entered array is: \n";
    for (i=0; i < 5; i++)
    {
        for (j=0; j < 5; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Sum of all alternate elements: " << sum << endl;

    getch();
}

int alterSum(int a[][5], int m, int n)
{
    int i, j, sum=0;

    for (i=0; i < m; i++)
    {
        for (j=0; j < n; j++)
        {
            if(i%2 == 0 && j%2 == 0)    //  Checking if both indices are even
                sum += a[i][j];

            if(i%2 == 1 && j%2 == 1)    //  Checking if both indices are odd
                sum += a[i][j];
        }
    }

    return sum;
}
