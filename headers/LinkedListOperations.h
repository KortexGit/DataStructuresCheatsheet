#pragma once


class Node {
public:
	int data;
	Node* next;

	Node(int value);
};

class LinkedListOperations {
private:
	Node* head;

public:
	LinkedListOperations(); // Constructor
	
	// Functions
	void createLinkedList(int elements[], int len);
	void updateValueAtIndex(int index, int newValue);
	void deleteValueAtIndex(int index);
	void insertValueAtIndex(int index, int value);
	void sortLinkedList();
	void printLinkedList() const;
	void displayLinkedListMenu();
};