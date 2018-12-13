/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Check for magic square

#include<iostream.h>
#include<conio.h>

#define false 0
#define true 1

int isMagic(int[3][3]);
int allDifferentNumbers(int[3][3]);

void main()
{
    clrscr();

    int i, j, square[3][3], magic;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> square[i][j];
        }
    }

    magic = isMagic(square);

    if(magic)
        cout << "It is a magic square!";
    else
        cout << "It ain't a magic square!";

    getch();
}

int isMagic(int square[3][3])
{
    int i, j, diagSum=0, rowSum=0, colSum=0;
    
    if (allDifferentNumbers(square))
    {
        for(i=0; i<3; i++)
            diagSum += square[i][i];
        
        for(i=0; i<3; i++)
        {
            rowSum = 0;
            colSum = 0;
            for(j=0; j<3; j++)
            {
                rowSum += square[i][j];
                colSum += square[j][i];
            }
            if(diagSum != rowSum || diagSum != colSum)
                return false;
        }
        
    } else return false;
    
    return true;
    
}

int allDifferentNumbers(int square[3][3])
{
    //  Checking for repetition of numbers

    int i, j, k=1, numberCheck[9] = {0,0,0,0,0,0,0,0,0};   // setting initial value to false

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            k = square[i][j]-1;
            
            if(numberCheck[k])
                return false;

            numberCheck[k] = true;
        }
    }
    return true;
}
