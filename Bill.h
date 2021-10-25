#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Bill: public Product
{
private :
    char BID[5],Total[15];
    fstream B;
public  :
    void SetBID(char *X) {
		strcpy(BID, X);
	}
	char *GetBID() {
		return BID;
	}
	void SetTotal(char *X) {
		strcpy(Total, X);
	}
	char* GetTotal() {
		return Total;
	}

    void AddBill(){
        bool Found = false;
        char Path[50];
        cout << "|Enter Bill's ID : " ;cin.getline(BID,5);
        strcpy(Path, "");
        strcat(Path, BID);
        strcat(Path, ".txt");
        B.open(Path,ios::in);
        if(B)
            cout << "|The Bill is already Founded !" << endl;
        else{
            B.close();
            B.open(Path,ios::app);
            cout << "|the Bill Add Successfully !" << endl;
        }
        B.close();
    }

    void AddProBill(){
        int counter = NumRec();
		Product *arr = GetArrPro() , T;
        bool Found = false;
        char Path[50] , OP[2], X[0] ,TPID[5] , TQ[10];

        cout << "|Enter Bill's ID : " ;cin.getline(BID,5);

        strcpy(Path, "");
        strcat(Path, BID);
        strcat(Path, ".txt");
        B.open(Path,ios::in);
        if(B)
            Found = true;
        B.close();
        if (Found)
        {
        B.open(Path,ios::app);
        do{
        bool Flag = false;
        cout << "|Enter the product's ID   : "; cin.getline(TPID, 5); T.SetPID(TPID);
		cout << "|Enter the product's ID   : "; cin.getline(TQ, 5);
		for (int i = 0; i < counter; i++)
			if (T == arr[i] &&atoi(arr[i].GetPQTY()) <= atoi(TQ)){
                Flag = true;

            }
		if(Flag){
            B << TPID << '|' << TQ << endl;
            cout << "|The product Added successfully !" << endl;
		}
        else
            cout << "|The product not found !" << endl;
		cout << "|To Edit another Product Enter (Y|y) : "; cin.getline(X,2);
        }while(X[0] == 'y' || X[0] == 'Y');
            B.close();
        }
        else
        {
            cout << "The Bill not found " << endl;
        }
    }
};
