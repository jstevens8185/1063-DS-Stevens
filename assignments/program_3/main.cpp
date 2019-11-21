#include <iostream>
#include "BigNum.hpp"

using namespace std; 

int main() {                
  
    BigNum BN;

    DLList* Num1 = new DLList("5555");
    DLList* Num2 = new DLList("123");

    Num1->Print();
    Num2->Print();

    DLList* Result = BN.Mul(Num1,Num2);



    Result->Print();
    
    return 0;
}