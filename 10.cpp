/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  To accept student data and print it

#include<constream.h>
#include<stdio.h>
#include<fstream.h>
#include<iomanip.h>

struct student
{
    char name[20];
    char house[11];
    int amount;
};

// User define function declaration
void line();

void main()
{
    clrscr();

    student student;
    fstream file("STUDENT.TXT", ios::in | ios::out);

    for(int i=0; i<5; i++)
    {
        cout << "Enter Details:- " << endl;
        cout << "Name: ";
        gets(student.name);

        cout << "House: ";
        gets(student.house);

        cout << "Amount Collected: ";
        cin >> student.amount;

        file.write((char*) &student, sizeof(student));
    }

    line();
    cout << "Name\t  House\t\tAmount Collected" << endl;
    line();

    file.seekg(0, ios::beg);        //  Moving the file pointer to the begining of the file

    while(file.read((char*) &student, sizeof(student)))
    {
        cout << student.name << "\t" << setw(9) << student.house << "\t" << student.amount << endl;
    }
    line();

    file.close();
    getch();
}

//  User define function
void line()
{
    for(int i=0; i<60; i++)
        cout << '-';

    cout << endl;
}
