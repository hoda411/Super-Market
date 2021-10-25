#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Product.h"
#include "Bill.h"
using namespace std;
void Bills()
{
    Bill B;
    char OP[2];
    do
    {
        cout << "============================================================" << endl;
        cout << left << '|' << setw(23) << ' ' << setw (35) << "Super Market" << '|' << endl;
        cout << "============================================================" << endl;
        cout << left << '|' << setw(58) << "1 - Add a new Bill   " << '|' << endl;
        cout << left << '|' << setw(58) << "2 - Add Product to a Bill    " << '|' << endl;
        cout << left << '|' << setw(58) << "3 - return to main menu " << '|' << endl;
        cout << "============================================================" << endl;
        cout << "|Enter the option [1 - 3] : "; cin.getline(OP,2);
        while(!(OP[0] == '1' || OP[0] == '2' || OP[0] == '3'))
        {
            cout << "|Enter the option [1 - 3] : "; cin.getline(OP,2);
        }
        switch(OP[0])
        {
        case '1':
            B.AddBill();
            break;
        case '2':
            B.AddProBill();
            break;
        }
    }while(OP[0] != '3');
}
void Store()
{
    Product Pro;
    char OP[2] , X[2];
    do
    {
        cout << "============================================================" << endl;
        cout << left << '|' << setw(23) << ' ' << setw (35) << "Super Market" << '|' << endl;
        cout << "============================================================" << endl;
        cout << left << '|' << setw(58) << "1 - Add a new Product   " << '|' << endl;
        cout << left << '|' << setw(58) << "2 - Delete a product    " << '|' << endl;
        cout << left << '|' << setw(58) << "3 - Edit a product      " << '|' << endl;
        cout << left << '|' << setw(58) << "4 - Search on a product " << '|' << endl;
        cout << left << '|' << setw(58) << "5 - Display All Product " << '|' << endl;
        cout << left << '|' << setw(58) << "6 - return to main menu " << '|' << endl;
        cout << "============================================================" << endl;
        cout << "|Enter the option [1 - 6] : "; cin.getline(OP,2);
        while(!(OP[0] == '1' || OP[0] == '2' || OP[0] == '3'||OP[0] == '4' || OP[0] == '5' || OP[0] == '6'))
        {
            cout << "|Enter the option [1 - 6] : "; cin.getline(OP,2);
        }
        switch(OP[0])
        {
        case '1':
            do{
            cin >> Pro;
            cout << "|To Add another Product Enter (Y|y) : "; cin.getline(X,2);
            }while(X[0] == 'Y' || X[0] == 'y');
            break;
        case '2':
                        do{
            Pro.Delete();
            cout << "|To Delete another Product Enter (Y|y) : "; cin.getline(X,2);
            }while(X[0] == 'Y' || X[0] == 'y');
            break;
        case '3':
                        do{
            Pro.Edit();
            cout << "|To Edit another Product Enter (Y|y) : "; cin.getline(X,2);
            }while(X[0] == 'Y' || X[0] == 'y');
            break;
        case '4':
                        do{
            Pro.Search();
            cout << "|To Search On another Product Enter (Y|y) : "; cin.getline(X,2);
            }while(X[0] == 'Y' || X[0] == 'y');
            break;
        case '5':
        Pro.Display();
        break;
        }
    }while(OP[0] != '6');
}
int main()
{
    char OP[2];
    do
    {
        system("cls");
        cout << "============================================================" << endl;
        cout << left << '|' << setw(23) << ' ' << setw (35) << "Super Market" << '|' << endl;
        cout << "============================================================" << endl;
        cout << left << '|' << setw(58) << "1 - Store" << '|' << endl;
        cout << left << '|' << setw(58) << "2 - Bill " << '|' << endl;
        cout << left << '|' << setw(58) << "3 - Exit " << '|' << endl;
        cout << "============================================================" << endl;
        cout << "|Enter the option [1 - 3] : "; cin.getline(OP,2);
        while(!(OP[0] == '1' || OP[0] == '2' || OP[0] == '3'))
        {
            cout << "|Enter the option [1 - 3] : "; cin.getline(OP,2);
        }
        switch(OP[0])
        {
        case '1':
            system("cls");
            Store();
            break;
        case '2':
            system("cls");
            Bills();
            break;
        }
    }while(OP[0] != '3');

    cout << endl << left << setw(23) << ' ' << setw (35) << "- Good Bye -" << endl << endl;
    system("pause");
    return 0;
}
