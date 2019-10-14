/*
 * File: stack.cpp
 * Aurhor: Jered Stevens / Terry Griffin
 * Course: CMPS 1063 - Fall 2019
 * Date: 24 Sep 24
 * Description:
 *    Class implementation file for our array based stack of ints
 */

#include <iostream>
#include "stack.h"
#include <fstream>
#include <string>
using namespace std;


/*
 * Stack constructor
 * Description:
 *    Inits an array of ints and sets our top
 */
Stack::Stack(){
    //cout<<"Default stack created" << endl;

  Size = 100;
  A = new int [Size];
  Top = -1;
  Largest = Size;
}

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints to a specified size and sets our top
 * Params:
 *    int s : integer size
 */
Stack::Stack(int s){
    //cout<<"Stack was created" << endl;

  Size = s;
  A = new int [Size];
  Top = -1;
  Largest = Size;
}

/**
 * Push
 * Description:
 *    Adds item to top of stack
 * Params:
 *    int val : integer size
 * Returns:
 *     bool : true = success
 */
bool Stack::Push(int val){
  if(!Full()){
    Top++;
    A[Top] = val;
    return true;
  }else{
    return false;
  }
}

/**
 * Pop
 * Description:
 *    Removes top of stack and returns it
 * Params:
 *    ofstream* out
 * Returns:
 *     int : item on stack
 */
int Stack::Pop(){
   //std::cout<<"Pop was called" << endl << endl;

  if(!Empty()){
    int temp = 0;   
    temp = A[Top];
    Top--;
    return temp;
  }else{
    // should return a value that implies failure
    cout<<"Cannot remove item from empty stack"<<endl;
  }
  return 0;
}

/**
 * Print
 * Description:
 *    Prints stack for inspection
 * Params:
 *    ofstream
 * Returns:
 *     void
 */
void Stack::Print(ofstream &outf){
  outf << "Top: " << Top << endl;
  outf << "Value @ Top: " << A[Top] << endl;
  outf << "Largest Size: " << Largest << endl;
  outf << "Stack Size: " << Size <<endl;
  
  for(int i = Top;i>=0 ; i--){
    outf <<A[i]<<endl;
  }
}

/**
 * Empty
 * Description:
 *    Is stack empty
 * Params:
 *    void
 * Returns:
 *    bool : true = empty
 */
bool Stack::Empty(){
  return Top < 0;
}

/**
 * Full
 * Description:
 *    Is stack full
 * Params:
 *    void
 * Returns:
 *    bool : true = full
 */
bool Stack::Full(){

  return (Top == Size - 1);
  
}


 /**
 * Enlarge
 * Description:
 *    increase stack size
 * Params:
 *    void
 * Returns:
 *    bigger stack
 */

void Stack::Enlarge(){
    //cout<<"Enlarge was called" << endl;

    
    int newSize = Size *= 1.5;;
    int* array2 = new int[newSize];
    for(int i = 0; i < Size; i++){
      array2[i]=A[i];
    }
  
    int* temp = A;
    Size = newSize;
    
    if(Size > Largest){         //Keep track of how big array gets
      Largest = Size;
    }

    A = array2;
    delete []temp;
    Enlarged = true;
   // cout << Enlarged <<endl;

  
}

/**
 * Reduce
 * Description:
 *    decrease stack size
 * Params:
 *    void
 * Returns:
 *    smaller stack
 */
void Stack::Reduce(){
   


    if(Enlarged){
    //cout << "Top is: "<< Top << endl;
    //cout << "Size is: " << Size << endl;

    int newSize = (Size * .5);

    //cout << "newSize is: " << newSize << endl;
    //cout << "before a new array is made" << endl;

    int* smallerArray = new int[newSize];
    Size = newSize;
    //cout << endl <<"after a new array is made" << endl;


    for(int i = 0; i <= Top; i++){      //changed from i < top
      smallerArray[i]=A[i];             
      //cout << smallerArray[i]<<endl;
    }
  
    //cout<<"Reduce was called" << endl << endl;
    // cout << "Top is: " << A[Top] << endl;

    int* temp = A;                    //<-Here is the problem*
    A = smallerArray;                 //<-
    delete[] temp;                    //<- *go to line 184 for problem
    return;
    }
    else if(!Enlarged){
      //cout << "Stack has not been enlarged" << endl;
      return;
    }
    else
    Stack::Error();
    return;
}

/**
 * Error
 * Description:
 *    Dispays error message
 * Params:
 *    void
 * Returns:
 *    
 */
void Stack::Error(){
    cout << "There was an error\n\n";
    return;
}


/**
 * checkResize
 * Description:
 *    checks if stack should increase or decrease in size
 * Params:
 *    void
 * Returns:
 *    reformatted stack
 */
void Stack::checkResize(){
    //std::cout<<"CheckResize was called" << endl;

    if(Top >= (Size * .8)){
        Stack::Enlarge();
        return;
    }
    else if(Top <= (Size * .2)){
        Stack::Reduce();
        return;
    }
    else{
        return;
    }
}  

/**
 * LoadFile
 * Description:
 *    Loads input file to be read
 * Params:
 *    void
 * Returns:
 *    
 */
void Stack::LoadFile(){
  ifstream in;
  in.open("input_data.txt");
  ofstream out;
  out.open("stack_out.txt");
  ofstream* ptrOut = &out;

    // Load the stack from infile
  while(!in.eof()){
    int counter = 0;
    if(counter % 3 == 0){
      checkResize();
    }
    counter++;
    int data;
    string useless;
    in >> useless >> data;
    if(data > 0){
      Push(data);
      //cout << "data is: " << data << endl;
    }
    else{
    Pop();
    }
 }
  return;
}
