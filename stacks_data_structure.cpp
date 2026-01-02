#include <iostream>
#include <cctype>
#include<cstdlib>
using namespace std;
void menu(); // function prototypes
void options();
void push();
void pop();
void top();
void purge();
void display();
const int SIZE = 15; // maximum stack size
int array[SIZE];
int index = -1; // empty stack
int main() { //main
	menu();
}
void menu() { // menu prompt
	cout << "\nStack Menu:\n";
	cout << "Type A to push a number to the stack\n";
	cout << "Type B to pop a number from the stack\n";
	cout << "Type C to output the top of the stack\n";
	cout << "Type D to purge the stack\n";
	cout << "Type E to exit\n";
	options(); // get user choice
}
void options() { // choice switch
	char choice;
	cin >> choice;
	choice = toupper(choice); // converts input to upper case
	switch(choice) {
	case 'A':
		push();
		break;
	case 'B':
		pop();
		break;
	case 'C':
		top();
		break;
	case 'D':
		purge();
		break;
	case 'E':
		cout << "Exiting program." << "\n";
		exit(0);
	default:
		cout << "Invalid input." << "\n";
		menu();
	}
}
void push() { // push number to top of the stack
	int num;
	cout << "Enter a number between 0 and 99: ";
	cin >> num;
	while (!cin || num < 0 || num > 99) {
		if (!cin) { // input not a number
			cout << "Invalid input. Please enter a valid number: ";
			cin.clear(); // reset cin
			cin.ignore(1000, '\n'); // skip the next 1000 characters until enter
		} else { // out of range
			cout << "Invalid input. Enter a number between 0 and 99: ";
		}
		cin >> num;
	}
	if (index == SIZE - 1) { // check for overflow first
		cout << "Error: stack overflow\n";
		menu();
	}
	index++; //update stack
	array[index] = num;
	display();
	menu();
}
void pop() { // pops the top number from the stack
	if (index == -1) {
		cout << "Error: stack underflow\n"; // check for underflow
		menu();
	}
	cout << "Popped element: " << array[index] << "\n"; // show popped element
	index--; // update stack
	display();
	menu();
}
void top() { // show top element of the stack
	if (index == -1) {
		cout << "Error: stack underflow. Stack is empty.\n";
	} else {
		cout << "Top of the stack: " << array[index] << "\n";
	}
	menu();
}
void purge() { // clears all elements from the stack
	index = -1; // reset index
	cout << "The stack has been purged.\n";
	menu();
}
void display() { // display all current elements in the stack
	cout << "Current stack: ";
	if (index == -1) {
		cout << "Stack is empty.\n";
	} else {
		for (int i = 0; i <= index; i++) {
			cout << array[i] << " ";
		}
	}
}
