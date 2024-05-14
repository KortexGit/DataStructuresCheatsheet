#include "StackOperations.h"
#include <iostream>

// TODO: Implement a linked list version of this to allow dynamic size stack
// TODO: Error handling for incorrect user inputs
// TODO: Improve output messages and guide for what is happening behind the code
// TODO: Add comments to explain functionality and algorithms used
// TODO: Refactor print code into traversal and print functions
// TODO: Refactor code so print is called outside of function in menu display

StackOperations::StackOperations() { // Constructor
    topIndex = -1;
}

// Function to create a stack - Complexity: O(n)
void StackOperations::createStack(int elements[], int len) {
    for (int i = 0; i < len; i++) {
        stack[i] = elements[i];
        topIndex++;
        // TODO: Use push here after refactor
    }
    printStack(); // TODO: Move to displayMenu
}

// Function to add value at top of stack - Complexity: O(1)
void StackOperations::push(int element) {
    if (topIndex >= maxSize - 1) {
        std::cout << "Stack is full. Cannot push element: " << element << "." << std::endl;
        return;
    }
    stack[++topIndex] = element;
    std::cout << "Pushed element: " << element << " onto the  stack." << std::endl;
    printStack(); // TODO: Move to displayMenu
}

// Function to delete value at top of stack - Complexity: O(1)
void StackOperations::pop() {
    if (topIndex < 0) {
        std::cout << "Stack is empty. Cannot pop from an empty stack." << std::endl;
        return;
    }
    
    std::cout << "Popped element: " << stack[topIndex] << " from the stack." << std::endl;
    stack[topIndex] = -1;
    topIndex--;
    printStack(); // TODO: Move to displayMenu
}

// Function to
void StackOperations::peek() {
    if (topIndex < 0) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    else {
        std::cout << "Top value: " << stack[topIndex] << std::endl;
        return;
    }
}

// Function to traverse and print the stack (top to bottom) - Complexity: O(n)
void StackOperations::printStack() {
    if (topIndex < 0) {
        std::cout << "Stack is empty, add elements first." << std::endl;
        return;
    }
    else {
        std::cout << "Stack contents (top to bottom):" << std::endl;
        for (int i = topIndex; i >= 0; i--) {
            std::cout << stack[i] << std::endl; // TODO: Use peek here?
        }
    }
}

// Function to check if stack is full
bool StackOperations::isFull() { // TODO: Make the logic work and include in functions
    return (topIndex == maxSize - 1);
}

// Function to check if stack is empty
bool StackOperations::isEmpty() { // TODO: Make the logic work and include in functions
    return (topIndex == 0);
}

// Function to display menu and call stack operations
void StackOperations::displayStackMenu() {
    int choice;
    int newValue;
    std::cout << "----- Stack Menu -----" << std::endl;
    std::cout << "1. Create Stack" << std::endl;
    std::cout << "2. Push value to Stack" << std::endl;
    std::cout << "3. Pop value from Stack" << std::endl;
    std::cout << "4. Peek top value" << std::endl;
    std::cout << "5. Print Stack" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: { // Create stack
        int elements[] = { 5, 3, 1, 4, 2 }; // TODO: Could make random values in future
        int len = sizeof(elements) / sizeof(elements[0]);
        createStack(elements, len);
        break;
    }
    case 2: { // Insert new value at top of the stack
        std::cout << "Enter new value: ";
        std::cin >> newValue;
        push(newValue);
        break;
    }
    case 3: { // Return and delete value at top of stack
        pop();
        break;
    }
    case 4: { // Return the top value in the stack
        peek();
        break;
    }
    case 5: // Print array
        printStack();
        break;
    case 6: // Exit to main menu
        std::cout << "Exiting..." << std::endl;
        return;
    default: // Wrong value entered
        std::cout << "Invalid choice." << std::endl;
    }

    // Recursive call to display menu again
    displayStackMenu();
}