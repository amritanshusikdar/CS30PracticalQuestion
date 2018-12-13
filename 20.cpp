/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Student database BSP / NBSP

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

struct student
{
    char name[20], cat, sex;
    int standard;   //  Synonym for class(school)
};

//  User defined function prototype

void line();

void main()
{
    clrscr();

    int i;
    char cat[5], sex[7];
    fstream file("STUD_DB.TXT", ios::in | ios::out);
    student detail;

    // Entering Details

    cout << "Enter student details:\n";
    for(i=0; i<5; i++)
    {
        cout << "Student " << i+1 << ":- \n";

        cout << "Name: ";
        gets(detail.name);

        cout << "Class(1-12): ";
        cin >> detail.standard;

        cout << "Category(B-BSP / N-NBSP): ";
        cin >> detail.cat;

        cout << "Sex(M/F): ";
        cin >> detail.sex;

        file.write((char*) &detail, sizeof(detail));
    }

    //  Displaying Details

    line();
    cout << "S.No.\tName\t\tClass\tCategory(BSP/NBSP)\tSex\n";
    line();

    file.seekg(0,ios::beg);

    for(i=0; i<5; i++)
    {
        file.read((char*) &detail,sizeof(detail));

        if(detail.cat == 'B' || detail.cat == 'b')
            strcpy(cat,"BSP");
        else if(detail.cat == 'N' || detail.cat == 'n')
            strcpy(cat,"NBSP");
        else
            strcpy(sex,"#!INV");

        if(detail.sex == 'M' || detail.sex == 'm')
            strcpy(sex,"Male");
        else if(detail.sex == 'F' ||  detail.sex == 'f')
            strcpy(sex,"Female");
        else
            strcpy(sex,"#!INV");

        cout << i+1 << '\t' << detail.name << "\t\t" << detail.standard << '\t' << cat << "\t\t\t" << sex << endl;
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
