/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Print merit list of students

#include <fstream.h>
#include <conio.h>
#include <iomanip.h>

struct merit
{
    int roll, percentage;
};

void line();
void bubbleSortReverse(int*, int);

void main()
{
    clrscr();
    int i, j, meritList[10];
    merit student;
    fstream list("RESULT.TXT", ios::in | ios::out);

    cout << "Enter details: " << endl;
    for(i=0; i<10; i++)
    {
        cout << "Student " << i+1 << ":-\n";
        cout << "Roll no.: ";
        cin >> student.roll;

        cout << "Percentage: ";
        cin >> student.percentage;

        meritList[i] = student.percentage;

        list.write((char*) &student, sizeof(student));
    }

    bubbleSortReverse(meritList, 10);

    cout << "\n\nMerit list of Top 10 Students: \n";
    line();
    cout << "S.No.\tRoll No.  Percentage\n";
    line();

    list.seekg(0,ios::beg);

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            list.read((char*) &student, sizeof(student));
            if(meritList[i] == student.percentage)
            {
                cout << setw(3) << i+1 << '\t' << setw(7) << student.roll << "  " << setw(10) << student.percentage << endl;
                break;
            }
        }
        list.seekg(0,ios::beg);
    }

    line();

    list.close();
    getch();
}

void bubbleSortReverse(int *array, int size)
{
    int i = size, j, temp;

    do
    {
        for(j = size-i-1; j >= 0; j--)
        {
            if(array[j] < array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
        i--;
    }while(i > 0);
}

void line()
{
    for(int i=0; i<69; i++)
    {
        cout << '-';
    }
    cout << endl;
}
