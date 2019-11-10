#include <iostream>
#include <fstream>
#include <random>

using namespace std;


/*  The Node
*   This thing holds each digit of our bigass #s.
*   Default value is 0
*/

struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};



/*  The list
*   The object that will hold our bigass numbers
*/

class BigNums{
    private:
        Node* head;
        Node* tail;

    public:
        BigNums(){
            head = NULL;
            tail = NULL;
        }
        void push(int x){
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
        }
        void print(){
            Node* temp = head;
        
            while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
            };
        }

        void emptyIt();
};







int main(){
/*  Open the file
*   file will contain:
*   1. first number that says how many operations are to be done
*   2. the sign operator (+-x/)
*   3. the bigass numbers
*/
    //ifstream input;
    //input.open("input_data.txt");

/*  Set variables
*   1. one will contain how many ops are to be performed
*   2. one will be a char to hold the operator
*   3. the other will have one # at a time to be pushed onto a list
*/

    int howMany;
    char operation;
    int digit;

    //input >> howMany;

/*   We need three lists.
*   1. The first will hold the first bigass #
*   2. The second will hold the next bigass #
*   3. The third will hold the result.
*   all three should be emptied before the next operation
*/

    BigNums ban1;
   // BigNums ban2;
   // BigNums bar; //(big ass result)

    //cout << howMany;
    for(int i = 0; i < 10; i++){
        ban1.push(i);
    };

    ban1.print();

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