#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Product
{
private:
	char PID[5], PName[20], PPrice[10], PQTY[10], Temp[50];
public:
	fstream S;
	friend istream &operator >> (istream &input, Product &P)
	{
		bool Found = false;
		int counter = P.NumRec();
		Product *arr = P.GetArrPro();
		cout << "|Enter the product's ID       : "; input.getline(P.PID, 5);
		for (int i = 0; i < counter; i++)
			if (arr[i] == P) {
				Found = true;
				break;
			}
		if (!Found) {
			cout << "|Enter the product's Name     : "; input.getline(P.PName, 20);
		}
		for (int i = 0; i < counter; i++)
			if (arr[i] == P) {
				Found = true;
				break;
			}
		P.S.open("Store.txt", ios::app);
		if (!Found) {
			cout << "|Enter the product's Price    : "; input.getline(P.PPrice, 10);
			cout << "|Enter the product's Quantity : "; input.getline(P.PQTY, 10);
			P.S << P.PID << '|' << P.PName << '|' << P.PPrice << '|' << P.PQTY << endl;
		}
		else
			cout << "|The product Founded !" << endl;
		P.S.close();
		return input;
	}

	friend ostream &operator << (ostream &output, Product &P)
	{
		output << fixed << left << '|' << setw(5) << P.PID << '|' << setw(20) << P.PName << '|' << setw(15)
			<< setprecision(2) << atof(P.PPrice) << '|' << setw(15) << atoi(P.PQTY) << '|' << endl;
		return output;
	}

	bool operator ==(Product & P) {
		if (strcmp(PID, P.PID) == 0 || strcmp(PName, P.PName) == 0)
			return true;
		else
			return false;
	}

	void SetPID(char *X) {
		strcpy(PID, X);
	}
	char *GetPID() {
		return PID;
	}
	void SetPName(char *X) {
		strcpy(PName, X);
	}
	char* GetPPName() {
		return PName;
	}
	void SetPPrice(char *X) {
		strcpy(PPrice, X);
	}
	char *GetPPrice() {
		return PPrice;
	}
	void SetPQTY(char *X) {
		strcpy(PQTY, X);
	}
	char *GetPQTY() {
		return PQTY;
	}

	Product* GetArrPro() {
		Product  arr[50];
		int I = -1;
		S.open("Store.txt", ios::in);
		if (S)
			while (!S.eof()) {
				I++;
				S.getline(arr[I].PID, 5, '|');
				S.getline(arr[I].PName, 20, '|');
				S.getline(arr[I].PPrice, 10, '|');
				S.getline(arr[I].PQTY, 10, '\n');
			}
		S.close();
		return arr;
	}

	int NumRec() {
		int I = -1;
		S.open("Store.txt", ios::in);
		if (S)
			while (!S.eof()) {
				I++;
				S.getline(PID, 5, '|');
				S.getline(PName, 20, '|');
				S.getline(PPrice, 10, '|');
				S.getline(PQTY, 10, '\n');
			}
		S.close();
		return I;
	}

	void Display() {
		int counter = NumRec();
		Product *arr = GetArrPro();
		if (counter > 0) {
			cout << "============================================================" << endl;
			cout << fixed << left << '|' << setw(5) << "ID" << '|' << setw(20) << "Name" << '|' << setw(15) << "Price" << '|' << setw(15) << "Quantity" << '|' << endl;
			cout << "============================================================" << endl;

			for (int i = 0; i < counter; i++)
				cout << arr[i];

			cout << "============================================================" << endl;
			cout << left << '|' << "the number of record : " << setw(35) << counter << '|' << endl;
			cout << "============================================================" << endl;
		}
		else
		{
			cout << "============================================================" << endl;
			cout << left << '|' << setw(58) << "There is no record !" << '|' << endl;
			cout << "============================================================" << endl;
		}
		system("pause");
	}

	void Search() {
		bool Found = false;
		char OP[2];
		int counter = NumRec();
		Product *arr = GetArrPro(), T;
		cout << "============================================================" << endl;
		cout << left << '|' << setw(58) << "1 - Search By ID  " << '|' << endl;
		cout << left << '|' << setw(58) << "2 - Search By Name" << '|' << endl;
		cout << "============================================================" << endl;
		cout << "|Enter the option [1 - 2] : "; cin.getline(OP, 2);
		while (!(OP[0] == '1' || OP[0] == '2')) {
			cout << "|Enter the option [1 - 2] : "; cin.getline(OP, 2);
		}
		switch (OP[0]) {
		case '1':
			cout << "|Enter the product's ID   : "; cin.getline(T.PID, 5);
			break;
		case '2':
			cout << "|Enter the product's Name : "; cin.getline(T.PName, 20);
			break;
		}
		for (int i = 0; i < counter; i++) {
			if (T == arr[i]) {
				cout << "============================================================" << endl;
				cout << fixed << left << '|' << setw(5) << "ID" << '|' << setw(20) << "Name" << '|' << setw(15)
					<< "Price" << '|' << setw(15) << "Quantity" << '|' << endl;
				cout << "============================================================" << endl;
				cout << arr[i];
				cout << "============================================================" << endl;
				Found = true;
				break;
			}
		}
		if (!Found)
			cout << "|The product not found !" << endl;
	}

	void Edit() {
		bool Found = false;
		char OP[2];
		int counter = NumRec();
		Product *arr = GetArrPro(), T;
		cout << "============================================================" << endl;
		cout << left << '|' << setw(58) << "1 - Edit By ID  " << '|' << endl;
		cout << left << '|' << setw(58) << "2 - Edit By Name" << '|' << endl;
		cout << "============================================================" << endl;
		cout << "|Enter the option [1 - 2] : "; cin.getline(OP, 2);
		while (!(OP[0] == '1' || OP[0] == '2')) {
			cout << "|Enter the option [1 - 2] : "; cin.getline(OP, 2);
		}
		switch (OP[0]) {
		case '1':
			cout << "|Enter the product's ID   : "; cin.getline(T.PID, 5);
			break;
		case '2':
			cout << "|Enter the product's Name : "; cin.getline(T.PName, 20);
			break;
		}
		for (int i = 0; i < counter; i++) {
			if ((T == arr[i])) {
				cout << "============================================================" << endl;
				cout << fixed << left << '|' << setw(5) << "ID" << '|' << setw(20) << "Name" << '|' << setw(15)
					<< "Price" << '|' << setw(15) << "Quantity" << '|' << endl;
				cout << "============================================================" << endl;
				cout << arr[i];
				cout << "============================================================" << endl;
				cout << "|Enter the product's Price    : "; cin.getline(arr[i].PPrice, 10);
				cout << "|Enter the product's Quantity : "; cin.getline(arr[i].PQTY, 10);
				Found = true;
			}
		}
		S.open("Store.txt", ios::out);
		for (int i = 0; i < counter; i++)
			S << arr[i].PID << '|' << arr[i].PName << '|' << arr[i].PPrice << '|' << arr[i].PQTY << endl;
		S.close();
		if (Found)
			cout << "|The product successfully updated!" << endl;
		else
			cout << "|The product not found !" << endl;
	}

	void Delete() {
		bool Found = false;
		char OP[2];
		int counter = NumRec();
		Product *arr = GetArrPro(), T;
		cout << "============================================================" << endl;
		cout << left << '|' << setw(58) << "1 - Delete By ID  " << '|' << endl;
		cout << left << '|' << setw(58) << "2 - Delete By Name" << '|' << endl;
		cout << "============================================================" << endl;
		cout << "|Enter the option [1 - 2] : "; cin.getline(OP, 2);
		while (!(OP[0] == '1' || OP[0] == '2')) {
			cout << "|Enter the option [1 - 2] : "; cin.getline(OP, 2);
		}
		switch (OP[0]) {
		case '1':
			cout << "|Enter the product's ID   : "; cin.getline(T.PID, 5);
			break;
		case '2':
			cout << "|Enter the product's Name : "; cin.getline(T.PName, 20);
			break;
		}
		S.open("Store.txt", ios::out);
		for (int i = 0; i < counter; i++) {
			if (T == arr[i])
				Found = true;
			else
				S << arr[i].PID << '|' << arr[i].PName << '|' << arr[i].PPrice << '|' << arr[i].PQTY << endl;
		}
		S.close();
		if (Found)
			cout << "|The product successfully Deleted!" << endl;
		else
			cout << "|The product not found !" << endl;
	}
};
