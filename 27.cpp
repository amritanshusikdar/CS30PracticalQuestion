/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Quiz ---- Countries & their Capitals

#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>

struct quiz
{
    char name[20], capital[20];
};

void main()
{
    clrscr();
    
    int i, found=0;
    char name[20];
    quiz country;
    fstream file("QUIZ.DBF", ios::in | ios::out | ios::binary);
    
    cout << "Enter country & its capital:-\n";
    for(i=0; i<5; i++)
    {
        cout << "Country " << i+1 << ": \n";
        
        cout << "Name: ";
        gets(country.name);
        
        cout << "Capital: ";
        gets(country.capital);
        
        file.write((char*) &country, sizeof(country));
    }
    
    cout << "Enter name of country you want to know capital of: ";
    gets(name);
    
    file.seekg(0,ios::beg);
    while(!file.eof() && found == 0)
    {
        file.read((char*) &country, sizeof(country));
        
        if(!strcmpi(name,country.name))
            found = 1;
    }
    
    if(found)
        cout << "Capital: " << country.capital << endl;
    else cout << "Country not in database!";
    
    file.close();
    getch();
}
