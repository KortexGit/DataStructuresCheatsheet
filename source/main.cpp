// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "main.h"
#include "ArrayOperations.h"
#include "LinkedListOperations.h"
#include "StackOperations.h"
#include "QueueOperations.h"
#include "HashTableOperations.h"
#include "TreeOperations.h"
#include "HeapOperations.h"
#include "GraphOperations.h"

void displayMainMenu() {
    // Class objects
    ArrayOperations arrayOps;
    LinkedListOperations linkedListOps;
    //StackOperations stackOps;
    //QueueOperations queueOps;
    //HashTableOperations  hashTableOps;
    //TreeOperations treeOps;
    //HeapOperations heapOps;
    //GraphOperations graphOps;

    // Variables
    int choice;

    std::cout << "----- Main Menu -----" << std::endl;
    std::cout << "1. Array" << std::endl;
    std::cout << "2. Linked List" << std::endl;
    std::cout << "3. Stack" << std::endl;
    std::cout << "4. Queue" << std::endl;
    std::cout << "5. Hash Table" << std::endl;
    std::cout << "6. Tree" << std::endl;
    std::cout << "7. Heap" << std::endl;
    std::cout << "8. Graph" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        arrayOps.displayArrayMenu();
        break;
    case 2:
        linkedListOps.displayLinkedListMenu();
        break;
    case 3:
        std::cout << "In Development..." << std::endl;
        break;
    case 4:
        std::cout << "In Development..." << std::endl;
        break;
    case 5:
        std::cout << "In Development..." << std::endl;
        break;
    case 6:
        std::cout << "In Development..." << std::endl;
        break;
    case 7:
        std::cout << "In Development..." << std::endl;
        break;
    case 8:
        std::cout << "In Development..." << std::endl;
        break;
    case 9:
        std::cout << "Exiting..." << std::endl;
        return;
    default:
        std::cout << "Invalid choice." << std::endl;
    }
    displayMainMenu(); // Recursive call to show menu again
}

int main()
{
    displayMainMenu();
    return 0;
}