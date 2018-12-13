/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to store sentences in a text file and print number of "To" & "The" in it.

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>

void main()
{
    clrscr();

    int to = 0, the = 0, flag = 0;
    char letter, word[10];

    fstream count("SENT.TXT", ios::in | ios::out);

    if(count.bad())
    {
        cout << "Error opening file! \nExiting now..." << endl;
        getch();
        exit(0);
    }

    cout << "Enter your sentence: (Press ESC to exit)" << endl;
    while(flag == 0)
    {
        letter = cin.get();
        if(letter == 27)    // ASCII value of ESC (escape) key
            flag = 1;
        else count << letter;
    }

    //  Counting number of To and The

    count.seekg(0,ios::beg);    //  Setting the file pointer to the beginning of file

    while(!count.eof())
    {
        count >> word;

        if(strcmpi(word, "the") == 0)
            the++;

        if(strcmpi(word, "to") == 0)
            to++;
    }

    cout << "Total TO: " << to << endl;
    cout << "Total THE: " << the << endl;

    count.close();

    getch();
}
