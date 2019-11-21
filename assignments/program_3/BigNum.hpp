#include <string>
#include "list.hpp"

using namespace std;

class BigNum {
private:
  DLList *BNum1;
  DLList *BNum2;
public:
    /**
     * Create a BigNum with an empty list. No value yet.
     */
    BigNum(){
      BNum1 = new DLList();
      BNum2 = new DLList();
    }

    /**
     * Add some other BigNum to this BigNum and return the
     * result (as a BigNum). The original two BigNums should be unaffected.
     */
    DLList* Add(DLList *bnum1, DLList *bnum2){
        BNum1 = bnum1;
        BNum2 = bnum2;

        int num1=0;
        int num2=0;
        int carry=0;
        int sum=0;


        DLList* Result = new DLList();

        while((!BNum1->isEmpty()) || (!BNum2->isEmpty())){
            if((!BNum1->isEmpty()) && (!BNum2->isEmpty())){
            num1 = BNum1->Delete();
            num2 = BNum2->Delete();
            sum = num1 + num2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            //cout<<num1<<"+"<<num2<<"+"<<carry<<"="<<sum<<endl;
            Result->frontSert(sum);

            //if numbers are in list 1 but not list 2
            }else if ((!BNum1->isEmpty()) && (BNum2->isEmpty())){
                num1 = BNum1->Delete();
                sum = num1 + carry;
                //cout<<num1<<"+"<<carry<<"="<<sum<<endl;
                carry = sum / 10;
                sum = sum % 10;
                Result->frontSert(sum);
            }else if((BNum1->isEmpty()) && (!BNum2->isEmpty())){
                num2 = BNum2->Delete();
                sum = num2 + carry;
                carry = sum / 10;
                sum = sum % 10;
                //cout<<num2<<"+"<<carry<<"="<<sum<<endl;
                Result->frontSert(sum);
            }else{
                cout << "Something went wrong" << endl;
            }
        }
         if(carry){
                Result->frontSert(carry);
            }
        // handle carry + rest of nums
        return Result;
    }

    DLList* Sub(DLList *bnum1, DLList *bnum2){
        BNum1 = bnum1;
        BNum2 = bnum2;

        int num1=0;
        int num2=0;
        int borrow=0;
        int diff=0;

        DLList* Result = new DLList();

        while((!BNum1->isEmpty()) || (!BNum2->isEmpty())){
            if((!BNum1->isEmpty()) && (!BNum2->isEmpty())){
                num1 = BNum1->Delete();
                num2 = BNum2->Delete();
                if(!(num1 < num2)){
                    diff = num1 - num2 - borrow;
                    borrow = 0;
                }else if(num1 < num2){
                    num1 += 10;
                    diff = num1 - num2 - borrow;
                    borrow = 1;
                }else{
                    cout << "Something went wrong" << endl;
                }
            }else if((!BNum1->isEmpty()) && (BNum2->isEmpty())){
                
            }
            Result->frontSert(diff);
        }
        return Result;
    };
    /**
     * Multiply some other BigNum with this BigNum and return the
     * result (as a BigNum). The original two BigNums should be unaffected.
     */
    DLList* Mul(DLList other);
    /**
     * Traverse list and add the number from each Node to a string. Return
     * that string.
     */
    string ToString(DLList other);

};