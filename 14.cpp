/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to calculate electricity bill and print in given format

#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<iomanip.h>

struct elecBill
{
    char name[20];
    int currReading;
    int prevReading;
};

void line();

void main()
{
    clrscr();

    int i, consumed;
    float amount;
    elecBill bill;
    fstream file("CSEB.txt", ios::in | ios::out);

    cout << "Enter customer details: \n";
    for(i=0; i<5; i++)
    {
        cout << "Name: ";
        gets(bill.name);

        cout << "Current reading: ";
        cin >> bill.currReading;

        cout << "Previous Reading: ";
        cin >> bill.prevReading;

        cout << endl;

        file.write((char*) &bill, sizeof(bill));
    }

    // Printing the Bill
    line();
    cout << "Consumer's_Name\tCurrent_Reading\tPrevious_Reading  Consumed_Unit  Bill_Amount" << endl;
    line();

    file.seekg(0, ios::beg);
    while(file.read((char*) &bill, sizeof(bill)))
    {
        consumed = bill.currReading - bill.prevReading;

        if(consumed <= 100)
            amount = consumed * 2.0;
        else if(consumed > 100 && consumed <= 200)
            amount = consumed * 3.25;
        else if(consumed > 200 && consumed <= 300)
            amount = consumed * 4.75;
        else if(consumed > 300)
            amount = consumed * 5.25;

        cout << setw(10) << bill.name << '\t' << setw(10) << bill.currReading << '\t' << setw(10) << bill.prevReading
        << '\t' << setw(10) << consumed << '\t' << setw(10) << amount << endl;
    }

    line();

    file.close();
    getch();
}

void line()
{
    for(int i=0; i<79; i++)
        cout << '-';
    cout << endl;
}
