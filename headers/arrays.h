#pragma once

class ArrayOperations {
private:
    static const int maxSize = 10; // Maximum size for the array
    int array[maxSize];
    int size;

public:
    ArrayOperations(); // Constructor

    void createArray(int elements[], int len);
    void updateValueAtIndex(int index, int newValue);
    void deleteValueAtIndex(int index);
    void insertValueAtIndex(int index, int value);
    void sortArray();
    void printArray(bool includeStatement) const;
    void displayArrayMenu();
};