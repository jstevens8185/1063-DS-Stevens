#include <iostream>
#include "BigNum.hpp"

using namespace std; 

int main() {                
  
    BigNum BN;

    DLList* Num1 = new DLList("999847475484747");
    DLList* Num2 = new DLList("459834987347859");

    Num1->Print();
    Num2->Print();

    DLList* Result = BN.Sub(Num1,Num2);



    Result->Print();

    //

    //D.Print();                      // Proves E and D are not linked
    
    return 0;
}