

#include <iostream>
#include <fstream>
#include "BigNum.hpp"

using namespace std; 

int main() {                
    ifstream in;
    ofstream out;
    ofstream& outref = out;
    out.open("output.txt");
    in.open("input.txt");
    int numOps;
    char operation;
    string num1, num2;
    BigNum BN;
    DLList* result = new DLList();
    DLList* Num1;
    DLList* Num2;
    string banana;
    in>>numOps;

    for (int i = 0; i < numOps; i++){
        in >> operation;
        switch (operation){
            case '+':
                in >> num1 >> num2;
                Num1 = new DLList(num1);
                Num2 = new DLList(num2);
                Num1->Print(outref);
                out << operation << endl;
                Num2->Print(outref);
                out << "=" << endl;
                result = BN.Add(Num1,Num2);
                banana = BN.ToString(result, out);
                out << banana << endl << endl;
                break;
            case '-':
                in >> num1 >> num2;
                Num1 = new DLList(num1);
                Num2 = new DLList(num2);
                Num1->Print(outref);
                out << operation << endl;
                Num2->Print(outref);
                out << "=" << endl;
                result = BN.Sub(Num1,Num2);
                banana = BN.ToString(result, out);
                out << banana << endl << endl;
                break;
            case '*':
                in >> num1 >> num2;
                Num1 = new DLList(num1);
                Num2 = new DLList(num2);
                Num1->Print(outref);
                out << operation << endl;
                Num2->Print(outref);
                out << "=" << endl;
                result = BN.Mul(Num1,Num2);
                banana = BN.ToString(result, out);
                out << banana;
                break;
        }
    }
    return 0;
}