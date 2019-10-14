/**
 * File: stack.h
 * Aurhor:  Jered Stevens / Terry Griffin
 * Course: CMPS 1063 - Fall 2019
 * Date: 24 Sep 24
 * Description:
 *    Definition of our stack class.
 */
#include<fstream>
#include<iostream>

using namespace std;

class Stack{
  private:
    int *A;                 // container of items (could make it a list)
    int Top;                // keep track of top
    int Size;               // Arrays need a size
    bool Enlarged = false;  // True when enlarged
    int Largest;           // Keeps track of largest array size
  public:
    
    Stack();                // Default constructor
    
    Stack(int);             // overloaded constructor
    bool Push(int);         // Push value onto stack
    int Pop();              // Remove item from top of stack
    void Print(ofstream &);           // Help inspect values
    bool Empty();           // Is stack empty
    bool Full();            // is stack full
    void checkResize();     // Is stack near capacity
    void Enlarge();         // Make it bigger
    void Reduce();          // Make it smaller
    void Error();           // Prints Error Message
    void LoadFile();        // Reads input
};