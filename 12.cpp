/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to calculate total amount collected in class Travel

#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#define PEOPLE 5

void line();    // Prototype

int i=0;      // Global variable 'i'

class travel
{
    private:
        char name[PEOPLE][20], vip[PEOPLE];
        int people, amount;

    public:
        travel()    //  Constructor
        {
            strcpy(name[i],"NULL");
            vip[i] = 'n';   // NO
            people = amount = 0;
        }

        void input()
        {
            cout << "Name: ";
            gets(name[i]);

            cout << "VIP(y/n): ";
            cin >> vip[i];

            if(vip[i] == 'y' || vip[i] == 'Y') isVIP();
            else notVIP();
        }

        void isVIP()
        {
            people++;
        }

        void notVIP()
        {
            people++;
            amount += 50;
        }

        void showAll()
        {
            cout << name[i] << "\t\t";
            if(vip[i] == 'n' || vip[i] == 'N')
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }

        int getPeople(){return people;}

        int getAmount(){return amount;}

        ~travel(){};    //  Deconstructor
};


//  Globally declared
travel fare;

void main()
{
    clrscr();

    for(i=0; i<PEOPLE; i++)
    {
        fare.input();
    }

    //  Displaying the contents

    line();
    cout << "S.No.\tName\t\tVIP\n";
    line();

    for (i = 0; i < PEOPLE; i++)
    {
        cout << i+1 << '\t';
        fare.showAll();
    }
    line();

    cout << "Total people visited: " << fare.getPeople() << endl;
    cout << "Total amount collected: " << fare.getAmount() << endl;

    line();

    getch();
}


void line()
{
    for (int i = 0; i < 40; i++)
        cout << '-';
    cout << endl;
}
