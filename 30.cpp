/*

    @Author: Amritanshu Sikdar
    Session: 2018-'19
    
    Repository: https://github.com/amritanshusikdar/CS30PracticalQuestion

*/

//  Program to demonstrate retail shopping

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class iteminfo
{
private:
    int iCode;
    char iName[10];
    int price;
    unsigned int qty;
    float discount, netPrice;

public:
    iteminfo()
    {
        iCode = price = qty = discount = netPrice = 0;
        strcpy(iName,"NULL");
    }

    void buy()
    {
        cout << "Enter product details: " << endl;

        cout << "Item code: ";
        cin >> iCode;

        cout << "Item name: ";
        gets(iName);

        cout << "Price: ";
        cin >> price;

        cout << "Quantity: ";
        cin >> qty;

        discount = findDisc(qty);

        netPrice = (price*qty) - discount;
    }

    int findDisc(int qty)
    {
        if(qty <= 10)
            discount = 0;
        else if(qty >= 11 && qty < 20)
            discount = 15;
        else discount = 20;

        return discount;
    }

    void showAll()
    {
        cout << "Item code: " << iCode << endl;
        cout << "Item name: " << iName << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << qty << endl;
        cout << "Discount: " << discount << endl;
        cout << "Net price: " << netPrice << endl;
    };

    ~iteminfo(){};
};

void main()
{
    clrscr();

    iteminfo item;

    item.buy();
    item.showAll();

    getch();
}
