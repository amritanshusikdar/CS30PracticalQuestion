/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  To assign stream according to the given criteria

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class student
{
    private:
        char name[20];
        int roll;
        int marksOf5;

    public:
        char stream[20];

        void input()
        {
            cout << "Name: ";
            gets(name);

            cout << "Roll number: ";
            cin >> roll;

            cout << "Marks of 5 Subjects(Total): ";
            cin >> marksOf5;

            cout << '\n';
        }

        void assignStream()
        {
            int percentage = marksOf5/5;

            if(percentage >= 96 && percentage <= 100)
                strcpy(stream,"Computer Science");

            else if(percentage >= 91 && percentage <= 95)
                strcpy(stream, "Electronics");

            else if(percentage >= 86 && percentage <= 90)
                strcpy(stream, "Mechanical");

            else if(percentage >= 81 && percentage <= 85)
                strcpy(stream, "Electrical");

            else if(percentage >= 76 && percentage <= 80)
                strcpy(stream, "Chemical");

            else if(percentage >= 71 && percentage <= 75)
                strcpy(stream, "Civil");
            else        // Checking if marks entered doesn't exceed the given range or limit
            {
                cout << "Marks out of range, Please reenter!\n";
                input();
                assignStream();
            }
        }

        void display()
        {
            cout << "Name: " << name << endl;
            cout << "Roll number: " << roll << endl;
            cout << "Stream assigned: " << stream << endl;
        }
};

void main()
{
    clrscr();

    student student;

    student.input();
    student.assignStream();
    student.display();

    getch();
}
