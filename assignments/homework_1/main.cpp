/*
*	Jered Stevens
*	1063 - Data Structs
*	Prof. Griffin
*	09/02/2019
*/
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>



using namespace std;

/**
 * Struct:		Student
 *	
 * Contains:	First Name
 *				Last Name
 *				Number of Grades
 *				Array of Grades
 *
 */

struct Student {
	string fname;
	string lname;
	int numGrades;
	int grades[10];
};


/*
*	Function: loadClassList		
*	
*	Opens file containing class list and grades.
*	Read file and load into array "students".
*	Return Number of students
*/

int loadClassList(Student *classList, string fileName) {
	ifstream infile;			//Stream Variable
	infile.open(fileName);		//Open file to be read
	int i = 0;					//Initialize index. # of students.
	
	infile >> classList[9].fname >> classList[9].lname;

	while (!infile.eof()) {
		//Read 1 student at a time into 1 struct at array location 'i'
		infile >> classList[i].fname >> classList[i].lname >> classList[i].numGrades;
		
		//Read the students grades
		for (int x = 0; x < classList[i].numGrades; x++) {
		infile >> classList[i].grades[x];
	}
		//increment 'i' to move to next student
		i++;
	}
	//Return student count
	return i;
}
/*
*	Function: printClassList
*
*	Prints each student and their grades to
*	an outfile in a formatted way
*/
void printClassList(Student *classList, int classSize) {
	// Open the output file that results will be printed in
	ofstream outfile("student_output.txt");

	// Document heading
	outfile << classList[9].fname << " " << classList[9].lname
			<< endl << endl;

	outfile << "Students" << endl;
	outfile << "=====================================" << endl;

	// First read student name and number of grades
	for (int i = 0; i < classSize; i++) {	
		outfile << i + 1 << ". " << left << setw(6) << classList[i].fname << " "
			<< left << setw(6) << classList[i].lname << ": ";

	// Cycle through grades for each student using
	// number of grades for loop
		for (int x = 0; x < classList[i].numGrades; x++) {
			outfile << right << setw(4) << classList[i].grades[x] << " ";
		}

	// Next line for next student
		outfile << endl;
	}
}

int main() {


	// Create Array of Students
	Student classList[100];

	// Initialize class size
	int classSize = 0;
	
	classSize = loadClassList(classList, "theClass2.txt");
	printClassList(classList, classSize);

	return 0;
}