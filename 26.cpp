/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to store city names in a queue and access data using a menu

#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char city[20];
    node *link;
};

class queue
{
    private:
        node *front, *rear;

    public:
        queue() { front = rear = NULL; }

        void add();
        void del();
        void view();
        ~queue();
};

void queue::add()
{
    node *temp = new node;
    gets(temp->city);
    temp->link = NULL;

    if(rear == NULL)
        rear = front = temp;
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

void queue::del()
{
    if(front == NULL)
        cout << "Underflow!!!\n";
    else
    {
        node *ptr = front;
        front = front->link;
        delete ptr;

        if(front == NULL)
            rear = NULL;
    }
}

void queue::view()
{
    node *temp = front;

    while(temp!=NULL)
    {
        cout << temp->city << "-->";
        temp = temp->link;
    }
    cout << "!!!\n";
}

queue::~queue()
{
    node *temp;
    while(front != NULL)
    {
        temp = front;
        front = front->link;
        delete temp;
    }
}

void main()
{
    clrscr();

    int ch;
    queue qt;

    while(1)
    {
        cout << "Menu:\n1. Add\n2. Delete\n3. View\n4. Exit\n";
        cout << "Choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
            cout << "Enter city: ";
                qt.add();
                break;
            case 2:
                qt.del();
                cout << "City deleted!\n";
                break;
            case 3:
                qt.view();
                break;
            case 4:
                cout << "Closing program!";
                getch();
                return;
            default:
                cout << "Invalid option!\n";
                break;
        }
    }
}
