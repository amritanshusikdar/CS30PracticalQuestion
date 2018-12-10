/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program for hostel administration

#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class hostel
{
    private:
        int roomNo;
        char name[20];
        float tar;
        int stay;
    
        float calculate()
        {
            if((stay*tar) > 10000)
                return 1.05*stay*tar;
            else return stay*tar;
        }
    
    public:
        void checkIn()
        {
            cout << "Name: ";
            gets(name);
            
            cout << "Room No.: ";
            cin >> roomNo;
            
            cout << "Tariff: ";
            cin >> tar;
            
            cout << "No. of days of stay: ";
            cin >> stay;
        }
    
        void checkOut()
        {
            float amount = calculate();
            
            cout << roomNo << '\t' << tar << '\t' << stay << "\t\t" << amount << endl;
        }
};

void line();

void main()
{
    clrscr();
    
    hostel stud;
    
    stud.checkIn();
    
    line();
    cout << "RoomNo.\tTariff\tStay(days)\tAmount\n";
    line();
    
    stud.checkOut();
    
    line();
    
    getch();
}

void line()
{
    for(int i=0; i<79; i++)
        cout << '-';
    cout << endl;
}
