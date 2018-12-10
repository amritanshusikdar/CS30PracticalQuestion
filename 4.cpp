/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to demonstrate the use of Single Inheritance

#include<iostream.h>
#include<conio.h>
#include<string.h>

class STUDENT
{
    protected:
        char name[20], house[8];
    public:
        STUDENT()
        {
            strcpy(name, "EMPTY");
            strcpy(house, "EMPTY");
        }
        ~STUDENT(){}
};

class MARKS: public STUDENT
{
    private:
        int eng, phy, chem, math, cs;
    
    public:
        MARKS()
        {
            eng = phy = chem = math = cs = 0;
        }

        void input()
        {
            cout << "Enter Name: ";
            cin.getline(name, 20);      // Accessing data members of STUDENT class

            cout << "Enter House: ";
            cin.getline(house, 8);      // Accessing data members of STUDENT class

            cout << "Enter marks of English, Physics, Chemistry, Math, CS: " << endl;
            cin >> eng >> phy >> chem >> math >> cs;
        }

        void display()
        {
            cout << "Name: " << name << endl;       // Accessing data members of STUDENT class
            cout << "House: " << house << endl;     // Accessing data members of STUDENT class
            cout << "Marks as follows: " << endl;
            cout << "English: " << eng << endl;
            cout << "Physics: " << phy << endl;
            cout << "Chemistry: " << chem << endl;
            cout << "Math: " << math << endl;
            cout << "CS: " << cs << endl;
        }

        ~MARKS(){}
};

void main()
{
    clrscr();
    
    MARKS student;

    student.input();
    student.display();

    getch();
}
