/**
 * File: main.cpp
 * Author: Jered Stevens
 * Course: CMPS 1063 - Fall 2019
 * Date: 10/10/2019
 * Description:
 * Main driver of an Array based implementation of a stack.
 */

#include <iostream>
#include "stack.h"
#include "stdlib.h"
#include <fstream>
#include <string>

using namespace std;


/**
 * Main Program
 * 
 */
int main() {
  ifstream in;
  in.open("input_data.txt");
  ofstream out;
  out.open("stack_out.csv");

  //Header
  out << "Jered Stevens" << endl
      << "10/10/2019" << endl
      << "Griffin" << endl
      << "Homework 2\n\n";

 
 
  Stack S2(10);  // Instance of our stack specified size
  S2.LoadFile();
  S2.Print(out);
  return 0;
}

