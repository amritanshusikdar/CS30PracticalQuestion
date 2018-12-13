/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to check palindrome words from file

#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>

void list_palindrome();
int isPalindrome(char*);

void main()
{
    clrscr();
    
    char ans='y';
    char word[10];
    ofstream file("WORDS.TXT", ios::out);
    
    while(ans == 'y' || ans == 'Y')
    {
        cout << "Enter word: ";
        cin >> word;
        file << word << ' ';
        
        cout << "Do you want to continue(y/n): ";
        cin >> ans;
    }
    
    file.close();
    
    list_palindrome();
    
    getch();
}

void list_palindrome()
{
    ifstream file("WORDS.TXT", ios::in);
    
    char word[10];
    int found=0;
    
    if(!file)
    {
        cout << "File not found!";
        getch();
        return;
    }
    
    while(!file.eof())
    {
        file >> word;
        
        if(isPalindrome(word))
        {
            ++found;
            cout << word << endl;
        }
    }
    
    file.close();
    
    if(!found)
        cout << "\nNo palindromes in file.\n";
}

int isPalindrome(char *word)
{
    int len = strlen(word);
    
    for(int i=0; i<len/2; i++)
    {
        if(word[i] != word[len-i-1])
            return 0;
    }
    
    return 1;
}
