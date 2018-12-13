/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  To store 10 names in list, print in alphabetical order via selection sort

#include <constream.h>
#include <string.h>

void selectionNames(char[][20], int);

void main()
{
    clrscr();

    int i;
    char name[10][20];

    //  Taking input

    for(i=0; i<10; i++)
    {
        cout << "Enter name " << i+1 << ": ";
        cin >> name[i];
    }

    //  Sorting the array

    selectionNames(name, 10);

    //  Displaying sorted array

    cout << "\n\nNames in alphabetical order: " << endl;
    for(i=0; i<10; i++)
    {
        cout << name[i] << endl;
    }

    getch();
}

void selectionNames(char name[][20], int size)
{
    char min[20], temp[20];
    int i, j, pos;


    for(i=0; i<size-1; i++)
    {
        pos = i;
        strcpy(min, name[pos]);

        for(j=i+1; j<=size-1; j++)
        {
            if(strcmp(name[j], min) < 0)
            {
                strcpy(min, name[j]);
                pos = j;
            }
        }

        if(strcmp(name[i], name[pos]) > 0)      //  not changing or comparing with min here because changes are to be made in the array
        {
            strcpy(temp, name[i]);
            strcpy(name[i], name[pos]);
            strcpy(name[pos], temp);
        }
    }
}
