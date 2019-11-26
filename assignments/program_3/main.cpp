////////////////////////////////////////////////////////////
//                  Program_03
//  Author:     Jered Stevens
//  Date:       Nov 24 2019
//  Assignment: Program_03
//  What I Do:
//          Reads in an operation sign and VERY large numbers 
//          from a file and performs arithmetic on them
/////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "BigNum.hpp"
#include <string>

using namespace std; 

int main() {                
    ifstream in;
    ofstream out;
    ofstream& outref = out;
    out.open("output.num");
    in.open("input_data.txt");
    int numOps;                     //get the number of times to run
    char operation;                 //get the first operation to perform
    string num1, num2;              //variable to hold the numbers
    BigNum BN;                      //class that can interact with the numbers
    DLList* result = new DLList();  //place to store final answers
    DLList* Num1;                   //list for first number
    DLList* Num2;                   //""  ""   2nd   ""
    string banana;                  //holds the number after the calculation
    in>>numOps;                    
////////////////////////////////////////////////
//  loop to keep doing math  until all math
//  is done.
//
//  uses switch statement to decide what to 
//  do.
////////////////////////////////////////////////
    for (int i = 0; i < numOps; i++){
        in >> operation;
        switch (operation){
            
//if its a plus sign do addition
//sends number to add funtion 
// and returns a list pointer
            case '+':
                in >> num1 >> num2;
                Num1 = new DLList(num1);
                Num2 = new DLList(num2);
                Num1->Print(outref);
                out << operation << endl;
                Num2->Print(outref);
                out << "=" << endl;
                result = BN.Add(Num1,Num2);
                result->Print(out);
                out << endl;
                //banana = BN.ToString(result, out);
                //out << banana << endl << endl;
                break;
//if its a minus sign do subtraction.
//sends number to subtraction funtion 
// and returns a list pointer            
            case '-':
                in >> num1 >> num2;
                Num1 = new DLList(num1);
                Num2 = new DLList(num2);
                Num1->Print(outref);
                out << operation << endl;
                Num2->Print(outref);
                out << "=" << endl;
                result = BN.Sub(Num1,Num2);
                result->Print(out);
                out << endl;
                //banana = BN.ToString(result, out);
                //out << banana << endl << endl;
                break;
//if its a star do multiplication
//sends number to multiply funtion 
// and returns a list pointer
            case '*':
                in >> num1 >> num2;
                Num1 = new DLList(num1);
                Num2 = new DLList(num2);
                Num1->Print(outref);
                out << operation << endl;
                Num2->Print(outref);
                out << "=" << endl;
                result = BN.Mul(Num1,Num2);
                result->Print(out);
                //banana = BN.ToString(result, out);
                out << banana;
                break;
        }
    }
    return 0;
}