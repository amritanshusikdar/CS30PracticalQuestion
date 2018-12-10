/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to find record in student phone directory

#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>

struct student
{
    char name[20];
    int phone;
};

void main()
{
    clrscr();
    int i, found=0;
    char name[20];
    student record;
    fstream file("PHONE.DAT", ios::in | ios::out | ios::binary);
    
    cout << "Enter student details:-\n";
    for(i=0; i<5; i++)
    {
        cout << "Student " << i+1 << ": \n";
        
        cout << "Name: ";
        gets(record.name);
        
        cout << "Phone number: ";
        cin >> record.phone;
        
        file.write((char*) &record, sizeof(record));
    }
    
    cout << "Enter name of student to be searched: ";
    gets(name);
    
    file.seekg(0,ios::beg);
    while(!file.eof() && found == 0)
    {
        file.read((char*) &record, sizeof(record));
        
        if(!strcmpi(name,record.name))
            found = 1;
    }
    
    if(found)
        cout << "Record found!\nPhone number: " << record.phone << endl;
    else cout << "Record not found!";
    
    file.close();
    getch();
}
