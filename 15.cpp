/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to store 10 numbers in a linear queue design menu to access queue

#include <constream.h>

const int size = 10;
int queue[size], front = -1, rear = -1;

void insertNo(int[], int);
int removeNo(int[]);
void display(int[], int, int);

void main()
{
    clrscr();

    char ch;
    int no;

    while(1)
    {
        cout << "Menu:\n1. Add\n2. Delete\n3. View\n4. Exit\n";
        cout << "Choice: ";
        cin >> ch;

        switch(ch)
        {
            case '1':
                cout << "Enter no.: ";
                cin >> no;
                insertNo(queue, no); break;
            case '2':
                no = removeNo(queue);
                if(no != -1)
                    cout << no << " deleted successfully!\n"; break;
            case '3':
                display(queue, front, rear); break;
            case '4':
                cout << "Closing program!\n";
                getch();
                return;
            default:
                cout << "Wrong choice entered!\n";
                break;
        }
    }
}


void insertNo(int queue[], int element)
{
    if(rear == size-1)
    {
        cout << "Overflow!!!\n";
        return;
    }
    else if(rear == -1)
    {
        front = rear = 0;
        queue[rear] = element;
    }
    else
    {
        rear++;
        queue[rear] = element;
    }
}

int removeNo(int queue[])
{
    int no;
    if(front == -1)
    {
        cout << "Underflow!!!\n";
        return -1;
    }
    else
    {
        no = queue[front];
        if(front == rear)
            front = rear = -1;
        else
            front++;
    }
    return no;
}

void display(int queue[], int front, int rear)
{
    if(front == -1)
    {
        cout << "Queue is empty!\n";
        return;
    }

    for(int i=front; i<=rear; i++)
        cout << queue[i] << "-->";

    cout << "!!!\n";
}
