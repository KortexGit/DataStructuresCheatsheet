#include "QueueOperations.h"
#include <iostream>

// TODO: Add input error checks
// TODO: Add linked list implementation for queue
// TODO: Show queue implementation for stacks

QueueOperations::QueueOperations() { // Constructor
    front = -1;
    rear = -1;
} 

void QueueOperations::createQueue(int elements[], int len) {
    if (!isEmpty()) {
        std::cout << "Queue not empty, use enqueue method to add values." << std::endl;
    }
    else {
        for (int i = 0; i < len; i++) {
            enqueue(elements[i]);
        }
        std::cout << "Created queue: " << std::endl;
    }
}
void QueueOperations::enqueue(int value) {
    if ((rear + 1) % maxSize == front) {
        std::cout << "Queue is full" << std::endl;
    }
    else { 
        if (front == -1)
            front = 0;

        rear = (rear + 1) % maxSize;
        queue[rear] = value;
        std::cout << "Element added: " << queue[rear] << std::endl;
    }
}
void QueueOperations::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    }
    else {
        std::cout << "Element removed: " << queue[front] << std::endl;
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % maxSize;
        }
    }
}
void QueueOperations::peek() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    }
    else {
        std::cout << "Front element is: " << queue[front] << "." << std::endl;
    }
}
void QueueOperations::printQueue() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    }
    else {
        int i;
        std::cout << "Printing queue: " << std::endl;
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
                std::cout << queue[i] << std::endl;
        }
        else
        {
            i = front;
            while (i < maxSize)
            {
                std::cout << queue[i] << std::endl;
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                std::cout << queue[i] << std::endl;
                i++;
            }
        }
    }
}
bool QueueOperations::isEmpty() {
    if (front == -1 && rear == -1) {
        return true;
    }
    else {
        return false;
    }
}

void QueueOperations::displayQueueMenu() {
    int choice;
    int newValue;
    std::cout << "----- Queue Menu -----" << std::endl;
    std::cout << "1. Create Queue" << std::endl;
    std::cout << "2. Enqueue Value" << std::endl;
    std::cout << "3. Dequeue Value" << std::endl;
    std::cout << "4. Peek Value" << std::endl;
    std::cout << "5. Print Queue" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: { // Create array
        int elements[] = { 5, 3, 1, 4, 2 }; // TODO: Could make random values in future
        int len = sizeof(elements) / sizeof(elements[0]);
        createQueue(elements, len);
        printQueue();
        break;
    }
    case 2: { // // Enqueue to queue 
        std::cout << "Enter new value: ";
        std::cin >> newValue;
        enqueue(newValue);
        printQueue();
        break;
    }
    case 3: { // Dequeue from queue 
        dequeue();
        printQueue();
        break;
    }
    case 4: // Peek top value
        peek();
        break;
    case 5: // Print array
        printQueue();
        break;
    case 6: // Exit to main menu
        std::cout << "Exiting..." << std::endl;
        return;
    default: // Wrong value entered
        std::cout << "Invalid choice." << std::endl;
    }

    // Recursive call to display menu again
    displayQueueMenu();
}