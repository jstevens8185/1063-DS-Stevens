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
        BNum1 = new DLList(*bnum1);
        BNum2 = new DLList(*bnum2);

        int num1=0;
        int num2=0;
        bool borrow = false;
        int diff=0;

        DLList* Result = new DLList();


        while((!BNum1->isEmpty()) && (!BNum2->isEmpty())){
            num1 = BNum1->Delete();
            num2 = BNum2->Delete();
            
            if(borrow){
                num1 -= 1;
            }
            if(num2 > num1){
                borrow = true;
                num1 += 10;
                diff = num1 - num2;
            }else if(num2 <= num1){
                borrow = false;
                diff = num1 - num2;
            }else{
                cout << "Something went wrong" << endl;
            }
            Result->frontSert(diff);
        }while((!BNum1->isEmpty()) && (BNum2->isEmpty())){
            num1 = BNum1->Delete();
            if(borrow){
                num1 -= 1;
                borrow = false;
            }
            Result->frontSert(num1);
        }
        //bnum1->Print();
        //cout << endl;
        return Result;
    };
    /**
     * Multiply some other BigNum with this BigNum and return the
     * result (as a BigNum). The original two BigNums should be unaffected.
     */
    DLList* Mul(DLList *bnum1, DLList *bnum2){
        BigNum BN;
        BNum2 = bnum2;
        int top = 0;
        int bottom = 0;
        int p = 0;
        int k = 0;
        
        DLList* result2 = new DLList();

        while(!BNum2->isEmpty()){
            
            DLList* result = new DLList();
            int c = 0;
            BNum1 = new DLList(*bnum1); 
            //BNum2->Print();
            bottom = BNum2->Delete();
            
            for(int i = 0; i<k; i++){
                result->endSert(0);
            }
            while (!BNum1->isEmpty()){
                
                top = BNum1->Delete();
                p = ((top * bottom) + c) % 10;
                c = ((top * bottom) + c) / 10;
                result->frontSert(p);
            }if(c){result->frontSert(c);}
            if(result2->isEmpty()){
                result2 = new DLList(*result);
            }
            else{
                result2 = BN.Add(result,result2);
            }
            k++;
            
            delete result;    
        }
        
        return result2;
        
        
    };
    /**
     * Traverse list and add the number from each Node to a string. Return
     * that string.
     */
    // THIS DOESNT WORK AND IDK WHY
    string ToString(DLList* other, ofstream& out){
        string result;
        DLList* Other = new DLList(*other);
        int digit;
        int i = 0;
         while(!Other->isEmpty()){
              digit = Other->Delete();
              result[i] = digit;
              result[i] = (result[i]+48);
              i++;
         }
        return result;
    };
};