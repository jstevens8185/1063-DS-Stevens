#include <iostream>
#include<string>
#include"stack.h"
using namespace std;


int main(){
    // Node<int> n1(-16);
    // n1.print();

    // Node<string> s1("Welcome ");
    // Node<string> s2("Proffessor");
    // s1.next = &s2;
    // s1.print();
    // s1.next->print();

    Stack<double> trouble;
    trouble.push(2.48);
    trouble.push(3.15);
    trouble.push(42);
    trouble.push(-9);
    trouble.pop();
    trouble.push(0.0000);
    trouble.print();
}