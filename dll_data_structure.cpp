#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct node {
	string student_name;
	int student_ID;
	double student_gpa;
	node *next;
};
node *start_ptr = NULL;
void menu(); // Function prototypes
void options();
void add_node();
void delete_node();
void modify_node();
void display_node();
void display_list();
void purge();
void check_empty();
int main() {
	menu();
}
void menu() { // menu with choices
	cout << "\nMenu: \n";
	cout << "1. Add a node\n";
	cout << "2. Delete a node\n";
	cout << "3. Modify a node\n";
	cout << "4. Display a node\n";
	cout << "5. Display the list\n";
	cout << "6. Purge the list\n";
	cout << "7. Exit\n";
	cout << "Enter your choice: ";
	options();
}
void options() {
	int choice;
	cin >> choice;
	switch(choice) {
	case 1:
		add_node();
		break;
	case 2:
		delete_node();
		break;
	case 3:
		modify_node();
		break;
	case 4:
		display_node();
		break;
	case 5:
		display_list();
		break;
	case 6:
		purge();
		break;
	case 7:
		cout << "\nExiting program.\n";
		exit(0);
	default:
		cout << "\nInvalid input.\n";
		menu();
	}
}
void check_empty() {
	if (start_ptr == NULL) {
		cout << "The list is empty.\n";
		menu();
	}
}
void add_node() {
	node *new_node = new node;
	cout << "Enter student name: ";
	cin.ignore(200, '\n');
	getline(cin, new_node->student_name);
	cout << "Enter 4-digit student ID (1000-9999): ";
	cin >> new_node->student_ID;
	while (new_node->student_ID < 1000 || new_node->student_ID > 9999) { // check range
		cout << "Invalid ID. Enter ID between 1000 and 9999: ";
		cin >> new_node->student_ID;
	}
	cout << "Enter GPA : ";
	cin >> new_node->student_gpa;
	new_node->next = NULL;
	node *temp = start_ptr; // check for duplicate
	while (temp != NULL) {
		if (temp->student_ID == new_node->student_ID) {
			cout << "ID already exists. Please enter a different ID.";
			delete new_node;
			menu();
			return;
		}
		temp = temp->next;
	}
	if (start_ptr == NULL || new_node->student_ID < start_ptr->student_ID) { // add node at beginning
		new_node->next = start_ptr;
		start_ptr = new_node;
	} else { //add at middle or at end
		node *temp = start_ptr;
		while (temp->next != NULL && temp->next->student_ID < new_node->student_ID) {
			temp = temp->next;
		}
		new_node->next = temp->next;
		temp->next = new_node;
	}
	menu();
}
void delete_node() {
	check_empty();
	int deleteID;
	cout << "Enter the student ID you want to delete: ";
	cin >> deleteID;
	node *temp1 = start_ptr;
	node *temp2 = NULL;
	while (temp1 != NULL && temp1->student_ID != deleteID) {
		temp2 = temp1; // temp2 points to same node as temp 1
		temp1 = temp1->next; // temp1 goes through all nodes
	}
	if (temp1 == NULL) {
		menu();
// id not found
		cout << "Student ID: " << deleteID << " does not exist. \n";
	}
	if (temp2 == NULL) { } else {
// id found, delete node
		start_ptr = temp1->next; // delete from beginning
		temp2->next = temp1->next; // delete from middle or end
	}
	delete temp1;
	menu();
}
void modify_node() {
	check_empty();
	int searchID;
	cout << "Enter the student ID you want to modify: ";
	cin >> searchID;
	node *temp = start_ptr;
	while (temp != NULL) { // search for the node until null
		if (temp->student_ID == searchID) {
			cout<< "\nBefore modification:\n"; //print the node before modification
			cout << "Name: " << temp->student_name << "\n";
			cout << "ID: " << temp->student_ID << "\n";
			cout << "GPA: " << temp->student_gpa << "\n";
			cout << "\nEnter new student name: ";
			cin.ignore(200, '\n');
			getline(cin, temp->student_name); //new name
			cout << "Enter new GPA : ";
			cin >> temp->student_gpa; //new gpa
			cout << "\nAfter modification:\n"; // node after modification
			cout << "Name: " << temp->student_name << "\n";
			cout << "ID: " << temp->student_ID << "\n";
			cout << "GPA: " << fixed << setprecision(1) << temp->student_gpa
			     <<"\n";
			menu();
			return;
		}
		temp = temp->next; // move on to next until null
	}
	menu();
	cout << "Student ID " << searchID << " does not exist.\n"; //node not found
}
void display_node() {
	check_empty();
	int searchID;
	cout << "Enter the student ID you want to display: ";
	cin >> searchID;
	node* temp = start_ptr;
	while (temp != NULL) {
		if (temp->student_ID == searchID) {
			cout << "Name: " << temp->student_name;
			cout << " ID: " << temp->student_ID;
			cout << " GPA: "<< fixed << setprecision(1) << temp->student_gpa
			     << "\n";
			menu();
			return;
		}
		temp = temp->next; //move on to next
	}
	menu();
	cout << "Student ID: " << searchID << " does not exist.\n"; //not found
}
void display_list() {
	check_empty();
	node* temp = start_ptr;
	cout << "\nLinked List: \n";
	while (temp != NULL) {
		cout << "Name: " << temp->student_name;
		cout << " ID: " << temp->student_ID;
		cout << " GPA: "<< fixed << setprecision(1) << temp->student_gpa <<
		     "\n";
		temp = temp->next;
	}
	menu();
}
void purge() {
	check_empty();
	node* temp;
	while (start_ptr != NULL) {
		temp = start_ptr;
		start_ptr = start_ptr->next;
		delete temp;
	}
	cout << "List has been purged\n";
	menu();
}
