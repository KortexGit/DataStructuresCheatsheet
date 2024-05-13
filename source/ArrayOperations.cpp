#include "ArrayOperations.h"
#include <iostream>
#include <algorithm> // for sorting method

// TODO: Error handling for incorrect user inputs
// TODO: Improve output messages and guide for what is happening behind the code
// TODO: Add comments to explain functionality and algorithms used
// TODO: Refactor print code into traversal and print functions

ArrayOperations::ArrayOperations() : size(0) {} // Constructor

// Function to create an array - Complexity: O(n)
void ArrayOperations::createArray(int elements[], int len) {
    size = std::min(len, maxSize); 
    for (int i = 0; i < size; i++) {
        array[i] = elements[i];
    }

    std::cout << "Created array: ";
    printArray(false); // Print the array created
}

// Function to update value at index - Complexity: O(1)
void ArrayOperations::updateValueAtIndex(int index, int newValue) {
    std::cout << "Original array: ";
    printArray(false); // Print original array

    if (index >= 0 && index < size) {
        array[index] = newValue;
    }
    else {
        std::cout << "Index out of range." << std::endl;
    }

    std::cout << "Updated array: ";
    printArray(false); // Print new array
}

// Function to delete value at index - Complexity: O(n)
void ArrayOperations::deleteValueAtIndex(int index) {
    std::cout << "Original array: "; // Print original array
    printArray(false);

    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        // Decrease size of array
        size--;
    }
    else {
        std::cout << "Index out of range." << std::endl;
    }

    std::cout << "Updated array: "; // Print updated array
    printArray(false);
}

// Function to insert a value at specific index - Complexity: Best case: O(1) Worst case: O(n)
void ArrayOperations::insertValueAtIndex(int index, int value)
{
    if (size >= maxSize) {
        std::cout << "Error: Array is full. Cannot insert more elements." << std::endl;
        return;
    }

    if (index < 0 || index > size) {
        std::cout << "Error: Invalid index. Please enter an index between 0 and " << size << std::endl;
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = size; i > index; --i) {
        array[i] = array[i - 1];
    }

    // Insert the new value at the specified index
    array[index] = value;

    // Increase the size of the array
    size++;

    std::cout << "Value " << value << " inserted at index " << index << std::endl;
    std::cout << "Updated array: ";
    printArray(false);
}

// Function to sort the array - Complexity: O(n log n)
void ArrayOperations::sortArray() {
    std::cout << "Original array: "; // Print original array
    printArray(false);

    std::sort(array, array + size); // Sort the array using sort function

    std::cout << "Sorted array: "; // Print sorted array
    printArray(false);
}

// Function to traverse and print the array - Complexity: O(n)
void ArrayOperations::printArray(bool includeStatement) const {
    if (size <= 0) {
        std::cout << "Array not in scope, create array first." << std::endl;
        return;
    }
    else {
        if (includeStatement)
        {
            std::cout << "Array traversal: ";
        }

        for (int i = 0; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to display menu and call array operations
void ArrayOperations::displayArrayMenu() { //ArrayOperations& arrayOps
    int choice;
    int index, newValue;
    std::cout << "----- Array Menu -----" << std::endl;
    std::cout << "1. Create Array" << std::endl;
    std::cout << "2. Update Value at Index" << std::endl;
    std::cout << "3. Delete Value at Index" << std::endl;
    std::cout << "4. Insert Value at Index" << std::endl;
    std::cout << "5. Sort Array" << std::endl;
    std::cout << "6. Print Array" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: { // Create array
        int elements[] = { 5, 3, 1, 4, 2 }; // TODO: Could make random values in future
        int len = sizeof(elements) / sizeof(elements[0]);
        createArray(elements, len);
        break;
    }
    case 2: { // Update array index with new value
        std::cout << "Enter index and new value: ";
        std::cin >> index >> newValue;
        updateValueAtIndex(index, newValue);
        break;
    }
    case 3: { // Delete array index
        std::cout << "Enter index to delete: ";
        std::cin >> index;
        deleteValueAtIndex(index);
        break;
    }
    case 4: { // Insert array index with new value
        std::cout << "Enter index and new value: ";
        std::cin >> index >> newValue;
        insertValueAtIndex(index, newValue);
        break;
    }
    case 5: // Sort array
        sortArray();
        break;
    case 6: // Print array
        printArray(true);
        break;
    case 7: // Exit to main menu
        std::cout << "Exiting..." << std::endl;
        return;
    default: // Wrong value entered
        std::cout << "Invalid choice." << std::endl;
    }

    // Recursive call to display menu again
    displayArrayMenu();
}