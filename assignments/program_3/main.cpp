#include <iostream>
#include <fstream>
#include "BigNum.hpp"

using namespace std; 

int main() {                
    ifstream in;
    ofstream out;
    out.open("output.txt");
    in.open("input.txt");
    int numOps;

    char operation;
    string num1, num2;
    BigNum BN;
    DLList* result = new DLList();
    DLList* Num1;
    DLList* Num2;
    in>>numOps;

    for (int i = 0; i < numOps; i++){
        in >> operation;
        switch (operation){
            case '+':
                in >> num1 >> num2;
                Num1 = new DLList(num1);
                Num2 = new DLList(num2);
                Num1->Print();
                Num2->Print();
                result = BN.Add(Num1,Num2);
                result->Print();
                cout << endl;
                break;
            case '-':
                in >> num1 >> num2;
                Num1 = new DLList(num1);
                Num2 = new DLList(num2);
                Num1->Print();
                Num2->Print();
                result = BN.Sub(Num1,Num2);
                result->Print();
                cout << endl;
                break;
            case '*':
                in >> num1 >> num2;
                Num1 = new DLList(num1);
                Num2 = new DLList(num2);
                Num1->Print();
                Num2->Print();
                result = BN.Mul(Num1,Num2);
                result->Print();
                break;
        }
    }
    return 0;
}