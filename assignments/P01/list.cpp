//Jered Stevens
//ds 1063
//Griffin
//9/16

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Determines wether or not an email contains some or all of a string
bool string_match(string big, string small)
{
	int index = big.find(small);
	return index >= 0;
}

//casts search to all lower case
string lower_string(string orig)
{
	string result = "";
	for (int i = 0; i < orig.size(); i++)
	{
		result += tolower(orig[i]);
	}
	return result;
}

// Object containing info of each employee
// contains constructor
struct Employee{
	string emp_id;
	string first_name;
	string last_name;
	string gender;
	string email;
	double hourly_pay;

	Employee()
	{
		emp_id = "";
		first_name = "";
		last_name = "";
		gender = "";
		email = "";
		hourly_pay = 0.0;
	}

	Employee(string id, string first, string last, string sex, string mail, double pay) {
		emp_id = id;
		first_name = first;
		last_name = last;
		gender = sex;
		email = mail;
		hourly_pay = pay;
	}
};

//object containing an employee object and a node to point to next employee
struct Node
{
	Employee emp;
	Node *next;
	Node(Employee data, Node *n = NULL)
	{
		emp = data;
		next = n;
	}
};

//List made up of employees and a node to direct to next item in list
class List{
private:
	Node* head;

public:
	List(){
		head = NULL;
	}

	//function to enter new employee obj into list
	void push(Employee emp)
	{
		Node *temp = new Node(emp, head);
		head = temp;
	}

	//Returns employee requested then deletes from list
	Employee pop()
	{
		Employee result = head->emp;
		Node *temp_del = head;
		head = head->next;
		delete temp_del;
		return result;
	}

	//Prints entire list containing every employee and all of their data
	void print(ofstream* out) {
		Node* Temp = head;

		while (Temp != NULL) {
			*out << Temp->emp.emp_id << ", " << Temp->emp.first_name << ", " << Temp->emp.last_name
				<< ", " << Temp->emp.gender << ", " << Temp->emp.email << ", " << Temp->emp.hourly_pay << endl;
			if (Temp->next) {
				*out << "->";
			}
			Temp = Temp->next;
		}
	}

	//Used to find employee based on a part of or their whole email 
	void find(string email, ofstream* out)
	{
		Node *temp = head;
		*out << "Searched for: " << email << endl;
		while (temp != NULL)
		{
			
			if (string_match(lower_string(temp->emp.email), lower_string(email)))
			{
				*out << temp->emp.email << endl;
			}
			temp = temp->next;
			
		}
	}

	//Prints data of first 30 employees in list
	void first30(List emplist, ofstream* out) {
		Node* Temp = head;

		for (int i = 0; i < 30; i++) {
			*out << Temp->emp.emp_id << ", " << Temp->emp.first_name << ", " << Temp->emp.last_name
				<< ", " << Temp->emp.gender << ", " << Temp->emp.email << ", " << Temp->emp.hourly_pay << endl;
			Temp = Temp->next;
		}
		*out << endl << endl;
	}
};

void header(ofstream* out) {
	*out << "Jered Stevens" << endl;
	*out << "ds 1063" << endl;
	*out << "Griffin" << endl;
	*out << "9/16" << endl << endl;
}

int main()
{
	//create list and intitalize variables of list
	List EmpList;
	string empid;
	string first;
	string last;
	string email;
	string gender;
	double pay;

	//open i/o files
	ifstream in;
	in.open("employees.dat");
	ofstream out;
	out.open("out.txt");

	//pointer to outfile for functions
	ofstream* ptrOut = &out;
	
	header(ptrOut);

	//read 1 line of input file into variables
	//transfer variables into an employee object
	//send employee to list and repeat
	while (!in.eof())
	{
		Employee empIn;
		in >> empid >> first >> last >> gender >> email >> pay;
		empIn.emp_id = empid;
		empIn.first_name = first;
		empIn.last_name = last;
		empIn.email = email;
		empIn.gender = gender;
		empIn.hourly_pay = pay;
		EmpList.push(empIn);
	};

	//Print first 30 employee id's
	EmpList.first30(EmpList, ptrOut);	

	//Search for "salon"
	EmpList.find("salon", ptrOut);

	return 0;
}
