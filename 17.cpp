/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program for Income Tax

#include <constream.h>
#include<stdio.h>

class income
{
    private:
        char name[20];
        long income;
        float tax;

    public:
        void input()
        {
            cout << "Enter name: ";
            gets(name);

            cout << "Enter Total Income: ";
            cin >> income;
        }

        void calculate()
        {
            if(income > 35000 && income <= 60000)
                tax = income * 0.2;
            else if(income > 60000 && income <= 120000)
                tax = income * 0.3;
            else if(income > 120000)
                tax = income * 0.4;
            else tax = 0;
        }

        void show()
        {
            cout << "Calculated Income Tax is " << tax << " INR.\n";
        }
};

void main()
{
    clrscr();

    income tax;

    tax.input();
    tax.calculate();
    tax.show();

    getch();
}
