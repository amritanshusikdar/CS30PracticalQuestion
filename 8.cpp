/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  To accept Employee data and display in given format

#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<iomanip.h>

struct emp
{
    char name[20];
    int basic;
};

void line();    //  Prototype

void main()
{
    clrscr();

    int sno;
    emp emp;
    float da, hra, total, pf, netpay;
    fstream file("EMP.TXT", ios::in | ios::out);

    //  Entering Employee data
    for(sno=1; sno<=5; sno++)
    {
        cout << "Employee " << sno << ":- " << endl;
        cout << "Name: ";
        gets(emp.name);

        cout << "Basic: ";
        cin >> emp.basic;
        cout << endl;

        file.write((char*) &emp, sizeof(emp));
    }

    //  Displaying Employee data

    cout << "\t\t\tSALARY REGISTER\n";
    line();
    cout << "S.No.   Name \t Basic\t DA\tHRA\tTotal\tPF\tNetPay" << endl;
    line();

    file.seekg(0,ios::beg);
    sno=1;    // Serial Number
    while(file.read((char*) &emp, sizeof(emp)))
    {
        da = emp.basic*0.3;
        hra = emp.basic*0.1;
        total = emp.basic + da + hra;
        pf = (emp.basic + da)*0.1;
        netpay = total + pf;

        cout << setw(3) << sno << "    " << setw(5) << emp.name  << '\t' << setw(5) << emp.basic << '\t' << setw(5) << da << '\t' << setw(4) << hra << '\t' << setw(5) << total << '\t' << setw(5) << setprecision(5) << pf << '\t' << setw(5) << setprecision(5) << netpay << endl;
        sno++;
    }

    line();

    file.close();
    getch();
}

void line()
{
    for(int i=0; i<64; i++)
        cout << '-';
    cout << endl;
}
