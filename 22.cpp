/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to access elements of a Stack using menu

#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char item[20];
    node *link;
};

class stack
{
    private:
        node *top;

    public:
        stack() { top = NULL; }

        void push();
        void pop();
        void display();

        ~stack();
};

void stack::push()
{
    node *temp = new node;
    gets(temp->item);
    temp->link = top;
    top = temp;
}

void stack::pop()
{
    if(top == NULL)
        cout << "Underflow!!!\n";
    else
    {
        node *ptr = top;
        top = top->link;
        delete ptr;
    }
}

void stack::display()
{
    node *temp = top;

    while(temp != NULL)
    {
        cout << temp->item << "<--";
        temp = temp->link;
    }
    cout << "!!!\n";
}

stack::~stack()
{
    node *temp;

    while(top != NULL)
    {
        temp = top;
        top = top->link;
        delete temp;
    }
}


void main()
{
    clrscr();

    stack st;
    int ch;

    while(1)
    {
        cout << "Menu:\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter item: ";
                st.push(); break;
            case 2:
                st.pop();
                cout << "Item deleted!\n"; break;
            case 3:
                st.display(); break;
            case 4:
                cout << "Closing program!";
                getch();
                return;
            default:
                cout << "Wrong choice entered!";
                break;
        }
    }
}
