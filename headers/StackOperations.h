#pragma once

// Stack is a linear collection where items are inserted and removed in a particular order
// Insertions are stacked
// Removals are LIFO - Last in First out
// Methods:
	// isEmpty - returns true or false if stack is empty
	// Push - adds a value to the top of the stack
	// Peek - shows the value at the top of the stack
	// Pop - return and remove the value at the top of the stack
	// Size - returns current size of the stack

class StackOperations {
private:
	// Variables
	static const int maxSize = 10; // Maximum size for the array
	int stack[maxSize];
	int topIndex;
	//int stackSize;

public:
	StackOperations(); // Constructor

	// Functions
	void createStack(int elements[], int len); // Create the stack using an arrray
	void push(int element); // Push - adds a value to the top of the stack
	void pop(); // Pop - return and remove the value at the top of the stack
	void peek(); // Peek - shows the value at the top of the stack
	bool isFull(); // isFull - returns true or false if stack is full
	bool isEmpty(); // isEmpty - returns true or false if stack is empty
	void printStack(); // Prints the current stack from top to bottom
	void displayStackMenu(); // Displays the menu to call stack operations
};