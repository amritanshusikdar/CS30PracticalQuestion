/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to check whether given list is sorted or not

#include<iostream.h>
#include<conio.h>

void is_sort(int*, int);

void main()
{
    clrscr();

    int i,*list, size;

    cout << "Enter size of list: ";
    cin >> size;

    list = new int[size];

    for(i=0; i<size; i++)
    {
        cout << "Element " << i+1 << ": ";
        cin >> *(list+i);
    }

    is_sort(list,size);

    getch();
}

void is_sort(int *list, int size)
{
    int i=0,flag=0;

    do {
        if(*(list+i) > *(list+i+1))
            flag = 1;
        i++;
    } while (i != size-2 && flag == 0);

    if(flag == 1)
        cout << "List is NOT sorted!";
    else cout << "List is sorted!";
}
