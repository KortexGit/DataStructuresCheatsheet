#pragma once

class QueueOperations {
private:
	// Variables
	static const int maxSize = 10;
	int queue[maxSize];
	int front;
	int rear;

public:
	QueueOperations(); // Constructor

	// Functions
	void createQueue(int elements[], int len);
	void enqueue(int value);
	void dequeue();
	void peek();
	void printQueue();
	bool isEmpty();
	void displayQueueMenu();
};