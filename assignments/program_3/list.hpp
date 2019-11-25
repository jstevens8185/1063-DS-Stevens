///////////////////////////////////////////////////////////////////////////////
//
// Author:           Jered Stevens
// Assignment:       Program_03
// Date:             20 November 2019
// Description:
//       This file is an implementation of a doubly linked list of integers.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *Next;
    Node *Prev;

    Node(int d) {
        data = d;
        Next = NULL;
        Prev = NULL;
    }
};

class DLList {
private:
    Node *Head;               // Head of list pointer
    Node *Tail;               // Tail of list pointer
    int Count;                // Count of items in list
    int _DeleteTail();
public:
    DLList();                   // Constructor
    DLList(string);             // makes list from a string
    DLList(const DLList &);     // Copy Constructor
    ~DLList();                  // Destructor
    int Size();                 // returns size of list
    void frontSert(int);        // inserts in front
    void endSert(int);          // inserts in back
    void Print(ofstream&);               // prints contents of list in order
    void RevPrint();            // prints contents of list in reverse order
    int Delete();               // deletes and returns tail. moves tail to tail->prev
    bool isEmpty();             //returns true if list is empty
};

/**
 * Public Default Constructor
 */
DLList::DLList() {
    Head = Tail = NULL;
    Count = 0;
}

/**
  * Create a BigNum from a string. Each digit will be stored in a Node.
  */
DLList::DLList(string big_number){
    Head = Tail = NULL;
    Count = 0;

    for(int i=0;i<big_number.size();i++){
      endSert(big_number[i]-48);
    }
}

bool DLList::isEmpty(){
  if (!Head && !Tail){
      return true;
  }else{
      return false;
  }
}

/**
 * Public Copy Constructor 
 *      constructs a new list with values from another list. 
 */
DLList::DLList(const DLList &list){
    Head = Tail = NULL; // Initialize pointers like always
    Count = 0;

    // Point to "Other" lists head. Even though its private we
    // can access it beacuase we are in a class of the same type.
    Node* Other = list.Head;

    // Travers the other list
    while(Other){
        // Insert values into new nodes in this list.
        endSert(Other->data);
        Other = Other->Next;
    }
}

/**
 * Public Destructor
 */
DLList::~DLList() {
    Node *temp = Head;

    while (temp) {
        temp = temp->Next;
        delete Head;
        Head = temp;
    }
}

/**
 * Public frontSert
 * 
 * Adds item to head of list by calling private method with a node.
 * 
 * @Params:
 * 
 *     int data : item to be placed in list
 * 
 * @Returns:
 * 
 *     void
 */
void DLList::frontSert(int data) {
    Node *Temp = new Node(data);

    if (!Head) {
        Head = Temp;
        Tail = Temp;
    } else {
        Head->Prev = Temp;
        Temp->Next = Head;
        Head = Temp;
    }
    Count++;
}

/**
 * Public endSert
 * 
 * Adds item to tail of list by calling private method with a node.
 * 
 * @Params:
 * 
 *     int data : item to be placed in list
 * 
 * @Returns:
 * 
 *     void
 */
void DLList::endSert(int data) {
    Node *Temp = new Node(data);

    if (!Head) {
        Head = Temp;
        Tail = Temp;
    } else {
        Tail->Next = Temp;
        Temp->Prev = Tail;
        Tail = Temp;
    }
    Count++;
}

/**
 * Public Print
 * 
 * Prints list to stdout from head to tail
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
void DLList::Print(ofstream& out) {
    Node* Temp = Head;
    
    while (Temp) {
        out << Temp->data;
        // if (Temp->Next) {
        //     out << "->";
        // }
        Temp = Temp->Next;
    }
    out << endl;
}

/**
 * Private _DeleteTail
 * 
 * Deletes last node in list
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
int DLList::_DeleteTail() {
    int val=-1;
    if(Tail){
        Node *Temp = Tail;
        val = Tail->data;
        if(Tail == Head){
            Tail = Head = NULL;
            delete Temp;
        }else{
            
            Tail = Tail->Prev;
            Tail->Next = NULL;
            delete Temp;
        }
        Count--;
    }
    return val;
}

/**
 * Public Delete
 * 
 * Deletes last node in list
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
int DLList::Delete() {
    return _DeleteTail();
}

/**
 * Public Size
 * 
 * Returns size of list
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     int
 */
int DLList::Size(){
    return Count;
}


/**
 * Public RevPrint
 * 
 *  Prints list to stdout in reverse (tail to head)
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
void DLList::RevPrint() {
    Node *Temp = Tail;

    while (Temp) {
        cout << Temp->data;
        if (Temp->Prev) {
            cout << "->";
        }
        Temp = Temp->Prev;
    }
    cout << endl;
}