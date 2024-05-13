#include "LinkedListOperations.h"
#include <iostream>
#include <algorithm> // for sorting method

// TODO: Error handling for incorrect user inputs
// TODO: Improve output messages and guide for what is happening behind the code
// TODO: Add comments to explain functionality and algorithms used
// TODO: Add additional Linked Lists (Doubly linked lists, circular, double linked circular)
// TODO: Refactor print code into traversal and print functions

Node::Node(int value) : data(value), next(nullptr) {}

LinkedListOperations::LinkedListOperations() : head(nullptr) {} // Constructor

// Function to create a linked list - Complexity: O(n)
void LinkedListOperations::createLinkedList(int elements[], int len) {
    head = nullptr;

    for (int i = len - 1; i >= 0; --i) {
        Node* newNode = new Node(elements[i]);
        newNode->next = head;
        head = newNode;
    }

    std::cout << "Created linked list: ";
    printLinkedList(); // Print the linked list created
}

// Function to update value at index - Complexity: O(n)
void LinkedListOperations::updateValueAtIndex(int index, int newValue) {
    std::cout << "Original linked list: ";
    printLinkedList(); // Print original linked list

    Node* temp = head;
    int currentIndex = 0;

    while (temp != nullptr && currentIndex != index) {
        temp = temp->next;
        currentIndex++;
    }

    if (temp != nullptr) {
        temp->data = newValue;
    }
    else {
        std::cout << "Index out of range." << std::endl;
    }

    std::cout << "Updated linked list: ";
    printLinkedList(); // Print new linked list
}

// Function to delete value at index - Complexity: O(n)
void LinkedListOperations::deleteValueAtIndex(int index) {
    std::cout << "Original linked list: "; // Print original linked list
    printLinkedList();

    if (index == 0) {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            std::cout << "Index out of range." << std::endl;
        }
    }
    else {
        Node* temp = head;
        Node* prev = nullptr;
        int currentIndex = 0;

        while (temp != nullptr && currentIndex != index) {
            prev = temp;
            temp = temp->next;
            currentIndex++;
        }

        if (temp != nullptr) {
            prev->next = temp->next;
            delete temp;
        }
        else {
            std::cout << "Index out of range." << std::endl;
        }
    }

    std::cout << "Updated linked list: "; // Print updated linked list
    printLinkedList();
}

// Function to insert a value at specific index - Complexity: O(n)
void LinkedListOperations::insertValueAtIndex(int index, int value)
{
    if (index == 0) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* temp = head;
        Node* prev = nullptr;
        int currentIndex = 0;

        while (temp != nullptr && currentIndex != index) {
            prev = temp;
            temp = temp->next;
            currentIndex++;
        }

        if (temp != nullptr) {
            Node* newNode = new Node(value);
            prev->next = newNode;
            newNode->next = temp;
        }
        else {
            std::cout << "Index out of range." << std::endl;
        }
    }

    std::cout << "Value " << value << " inserted at index " << index << std::endl;
    std::cout << "Updated linked list: ";
    printLinkedList();
}

// Function to sort the linked list - Complexity: O(n^2) (can be improved based on sorting algorithm)
void LinkedListOperations::sortLinkedList() {
    std::cout << "Original linked list: "; // Print original linked list
    printLinkedList();

    // Bubble sort for simplicity, can use more efficient algorithms
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                std::swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    std::cout << "Sorted linked list: "; // Print sorted linked list
    printLinkedList();
}

// Function to traverse and print the linked list - Complexity: O(n)
void LinkedListOperations::printLinkedList() const {
    Node* temp = head;

    if (temp == nullptr) {
        std::cout << "Linked list not in scope, create linked list first." << std::endl;
        return;
    }
    else {
        std::cout << "Linked list traversal: ";
        while (temp != nullptr) {
            std::cout << temp->data;
            if (temp->next != nullptr) {
                std::cout << " -> ";
            }
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

// Function to display menu and call linked list operations
void LinkedListOperations::displayLinkedListMenu() {
    int choice;
    int index, newValue;
    std::cout << "----- Linked List Menu -----" << std::endl;
    std::cout << "1. Create Linked List" << std::endl;
    std::cout << "2. Update Value at Index" << std::endl;
    std::cout << "3. Delete Value at Index" << std::endl;
    std::cout << "4. Insert Value at Index" << std::endl;
    std::cout << "5. Sort Linked List" << std::endl;
    std::cout << "6. Print Linked List" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: { // Create linked list
        int elements[] = { 5, 3, 1, 4, 2 }; // TODO: Could make random values in future
        int len = sizeof(elements) / sizeof(elements[0]);
        createLinkedList(elements, len);
        break;
    }
    case 2: { // Update linked list index with new value
        std::cout << "Enter index and new value: ";
        std::cin >> index >> newValue;
        updateValueAtIndex(index, newValue);
        break;
    }
    case 3: { // Delete linked list index
        std::cout << "Enter index to delete: ";
        std::cin >> index;
        deleteValueAtIndex(index);
        break;
    }
    case 4: { // Insert linked list index with new value
        std::cout << "Enter index and new value: ";
        std::cin >> index >> newValue;
        insertValueAtIndex(index, newValue);
        break;
    }
    case 5: // Sort linked list
        sortLinkedList();
        break;
    case 6: // Print linked list
        printLinkedList();
        break;
    case 7: // Exit to main menu
        std::cout << "Exiting..." << std::endl;
        return;
    default: // Wrong value entered
        std::cout << "Invalid choice." << std::endl;
    }

    // Recursive call to display menu again
    displayLinkedListMenu();
}
