/**
 * Hw 4 
 * 
 * List based queue 
 * 
 * Author: Jered Stevens/Terry Griffin
 * Date: Oct 14 2019
 * 
 * creates list based queue of Animals
 */
#include <iostream>
#include <fstream>
#include <string>
#include "ListQueue.hpp"

using namespace std;


int main() {
    ifstream fin("animals.txt");  // input file of animal info                   
    Animal *a;                    // animal pointer used to hold popped animals

  ListQueue LQ;                 // Queue instance 
   
   
   
    while (!fin.eof()) {
        string name;            // Create temporary variables for animal info
        double weight;
        double scary;                                       
        fin >> name >> weight >> scary;     // load animal with file data
        a = new Animal(name, weight, scary);    //push variables into new animal
        LQ.Push(a);                        // push animal onto the stack
    }

  LQ.Print();                     // print queue to see where values are

  LQ.Pop();

  LQ.Print();                     // print again to show front removal
  LQ.PrintPointers();

  Node* f = LQ.GetFront();        // We added this in class JUST to see what front
  cout<<f->A<<endl;            // pointed to.
}