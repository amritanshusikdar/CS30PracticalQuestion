/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  A little Student Database

#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>

struct student
{
    char name[20];
    long phone;
};

int main()
{
    clrscr();

    int i=0, found;
    char name[20];
    fstream file("STD.TXT", ios::in | ios::out);
    student record;

    //  Writing into File

    for(i=0; i<5; i++)
    {
        cout << "Name: ";
        gets(record.name);

        cout << "Phone: ";
        cin >> record.phone;

        file.write((char*) &record, sizeof(record));
    }

    cout << "Enter name of student to search: ";
    gets(name);

    file.seekg(0,ios::beg);     //  Setting the file pointer to the beginning of file

    //  Searching for requested record

    while(!file.eof() && found != 1)
    {
        file.read((char*) &record, sizeof(record));
        if(strcmpi(name, record.name) == 0)
            found = 1;
        else found = 0;
    }

    if(found == 1)
        cout << "Phone of " << record.name << " is: " << record.phone << endl << endl;
    else cout << "Not found in the directory! \n\n";

    file.close();
    getch();
    return 0;
}
