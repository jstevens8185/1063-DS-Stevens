#include <iostream>
#include <fstream>
#include <random>
#include <string>

using namespace std;


/*  The Node
*   This thing holds each digit of our bigass #s.
*   Default value is 0
*/

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int x){
        data = x;
        next = prev = NULL;
    }
};



/*  The list
*   The object that will hold our bigass numbers
*/

class BigNums{
    private:
        Node* head;
        Node* tail;
        int size = 0;

        //Overloaded Functions to find sum and carrys
        int getSum(BigNums*, BigNums*, int);
        int getSum(BigNums*, int);
        int getCarry(BigNums*, BigNums*, int);
        int getCarry(BigNums*, int);

    public:
        BigNums(){
            head = NULL;
            tail = NULL;
        }
        
        void frontsert(int);
        void endsert(int);
        void print(ofstream*);
        void emptyIt();
        void add(BigNums, BigNums);
};

/**********************************
*   Function: getSum
*   Params: 2 Bignums*, int
*   returns: int
************************************/
int BigNums::getSum(BigNums* a, BigNums* b, int c){
   int sum = ((a->tail->data) + (b->tail->data) + c) % 10;
   return sum;
};

/**********************************
*   Function: getSum
*   Params: 1 Bignums*, int
*   returns: int
************************************/
int BigNums::getSum(BigNums* a, int c){
   int sum = ((a->tail->data) + c) % 10;
   return sum;
};

/**********************************
*   Function: getCarry
*   Params: 2 Bignums*, int
*   returns: int
************************************/
int BigNums::getCarry(BigNums* a, BigNums* b, int c){
   int carry = ((a->tail->data) + (b->tail->data) + c) / 10;
   return carry;
};

/**********************************
*   Function: getCarry
*   Params: 1 Bignums*, int
*   returns: int
************************************/
int BigNums::getCarry(BigNums* a, int c){
   int carry = ((a->tail->data) + c) / 10;
   return carry;
};
void BigNums::add(BigNums a, BigNums b){
    //
    int carry, sum = 0;
    BigNums* aCopy = new BigNums(a);
    BigNums* bCopy = new BigNums(b);

     this->head = NULL;
     this->tail = NULL;
     this->size = 0;


     //While there are sill nums in at least one of the list:
     while(aCopy->tail != NULL || bCopy->tail != NULL){
         //If there are nums still in both the lists
         if (aCopy->tail != NULL && bCopy->tail != NULL){
             sum = getSum(aCopy, bCopy, carry);
             carry = getCarry(aCopy, bCopy, carry);
             aCopy->tail = aCopy->tail->prev;
             bCopy->tail = bCopy->tail->prev;
         }
         //If list b still has nums in it
         else if (aCopy->tail == NULL && bCopy->tail != NULL){
            sum = getSum(bCopy, carry);
            carry = getCarry(bCopy, carry);
            bCopy->tail = bCopy->tail->prev;
         }
         //If list a still has nums in it
         else if (aCopy->tail != NULL && bCopy->tail == NULL){
            sum = getSum(aCopy, carry);
            carry = getCarry(aCopy, carry);
            aCopy->tail = aCopy->tail->prev;
         }

        frontsert(sum);
     }
     if (carry){
         frontsert(carry);
     }
};

void BigNums::print(ofstream* out){
            Node* temp = head;
        
            while(temp != NULL){
            *out << temp->data << "->";
            temp = temp->next;
            }
};

void BigNums::frontsert(int x){
            Node *n = new Node(x);

            //if its NOT empty do something
            if(head!=NULL){
                head->prev = n;
                n->next = head;
                n->prev = NULL;
                head = n;
            }
            //if its empty do something different
            //this is second because it will happen less often    
            else{
                head = tail = n;
            }
            size++;
};

void BigNums::endsert(int x){
    Node* temp = new Node(x);

    if (!tail){
        head = tail = temp;
    }else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp; 
    }
    size++;
};



int main(){
/*  Open the file
*   file will contain:
*   1. first number that says how many operations are to be done
*   2. the sign operator (+-x/)
*   3. the bigass numbers
*/
    ifstream input;
    input.open("input_data.txt");
    ofstream out;
    ofstream* outptr = &out;
    out.open("output.num");

/*  Set variables
*   1. one will contain how many ops are to be performed
*   2. one will be a char to hold the operator
*   3. the other will have one # at a time to be pushed onto a list
*/

    int howMany;
    char operation;
    string BAN1;
    string BAN2;

    input >> howMany;
    input >> operation;
    input >> BAN1;
    input >> BAN2;

    BigNums test1;
    BigNums test2;
    BigNums result;


    
    for (int i = 0; i < BAN1.length(); i++){
        test1.endsert(BAN1[i]-48);
    }
    
    for (int i = 0; i < BAN2.length(); i++){
        test2.endsert(BAN2[i]-48);
    }

    result.add(test1, test2);
    result.print(outptr);

/*   We need three lists.
*   1. The first will hold the first bigass #
*   2. The second will hold the next bigass #
*   3. The third will hold the result.
*   all three should be emptied before the next operation
*/

    //BigNums ban1;
   // BigNums ban2;
   // BigNums bar; //(big ass result)

    //cout << howMany;
//     for(int i = 0; i < 10; i++){
//         ban1.push(i);
//     };

//     ban1.print();

 }

/*void BigNums::push(int x){
    Node *n = new Node(x);

    //if its NOT empty do something
    if(head!=NULL){
        tail->next = n;
        tail = n;
    }
    //if its empty do something different
    //this is second because it will happen less often    
    else{
        head = n;
        tail = n;
    }
};

void BigNums::print(){
    Node* temp = head;
    
    while(temp->next != NULL){
        cout << temp->data;
        temp = temp->next;
    };
};
*/