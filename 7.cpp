/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Done as directed in Q7

#include <constream.h>

class student
{
    private:
        char name[20];
        int rollNumber;

    public:
        void getData()
        {
            cout << "Enter Name: ";
            cin.getline(name,20);

            cout << "Enter Roll: ";
            cin >> rollNumber;
        }

        void printData()
        {
            cout << "Name: " << name << endl;
            cout << "Roll: " << rollNumber << endl;
        }
};

class marks: public student
{
    private:
        int eng, phy, chem, math, cs;

    public:
        void inputData()
        {
            getData();

            cout << "Enter marks of English, Physics, Chemistry, Math, CS: \n";
            cin >> eng >> phy >> chem >> math >> cs;
        }
        void outData()
        {
            printData();

            cout << "Marks as follows: \n";

            cout << "English: " << eng << endl;
            cout << "Physics: " << phy << endl;
            cout << "Chemistry: " << chem << endl;
            cout << "Math: " << math << endl;
            cout << "CS: " << cs << endl;
        }
};

void main()
{
    clrscr();

    marks ofStudent;

    ofStudent.inputData();
    ofStudent.outData();

    getch();
}
