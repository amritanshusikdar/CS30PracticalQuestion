/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to store ID and Password & check login credentials

#include <fstream.h>
#include <conio.h>
#include <string.h>

struct db
{
    char id[10];
    char pass[10];
};

void main()
{
    clrscr();

    db user;
    int found;
    char userID[10], userPass[10];
    fstream file("password.dbf", ios::in | ios::out);

    //  Input

    for(int i=0; i<5; i++)
    {
        cout << "Enter Details:- " << endl;
        cout << "User Name: ";
        cin >> user.id;

        cout << "Password: ";
        cin >> user.pass;

        file.write((char*) &user, sizeof(user));
    }

    cout << "Login Page!\n";
    cout << "Username: ";
    cin >> userID;
    cout << "Password: ";
    cin >> userPass;

    //  Checking

    file.seekg(0,ios::beg);
    while(file.read((char*) &user, sizeof(user)) && found != 1)
    {
        if(strcmpi(userID, user.id) == 0 && strcmpi(userPass,user.pass) == 0)
            found = 1;
        else found = 0;
    }

    if(found == 1)
        cout << "Access Allowed!\n\n";
    else cout << "Access Denied!\n\n";

    file.close();
    getch();
}
