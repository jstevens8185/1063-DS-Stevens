#include<iostream>
using namespace std;


template<class T>       //<- temp placeholder class
// can also use template<typename T>
// Applies to anything in the next immediate code block




struct Node{
    T data;
    Node* next;
    Node(){
        next = NULL;
    }
    Node(T d){
        data = d;
        next = nullptr;
    }
    Node(T d, Node* n){         // cant default to null bc class doesnt exist yet
        data = d;               // cant have default values
        next = n;               // Must make multiple constructors
    }
    void print(){
        cout << "Data: " << data << "\nNext Address: " << next << endl;
    }
};

template<class U>
class Stack{
    private:
        Node<U>* Top;
        int size;
    public:
        Stack(){
            Top = nullptr;
            size = 0;
        }
        void push(U val){
            Top = new Node<U>(val , Top);
            size++;

            return;
        }
        U pop(){
            U result = Top->data;
            Node<U>* tempTop;
            Top = Top->next;
            delete[] tempTop;
            size--;
            return U();
        }
        void print(){

            
            Node<U>* tempTop = Top;
            while(tempTop){
                cout << tempTop->data << " ";
                tempTop = tempTop->next;
            }
            cout << endl;
            return;
        }

};