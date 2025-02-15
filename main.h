#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <utility>

using namespace std;

// Function to check if a value exists in the array and return the index
int isCheck(int numArray[], int size, int val);

// Function to modify the value at a specified index and return both old and new values
pair<int, int> oldAndnew(int numArray[], int size, int new_val, int index);

// Function to add a new value at the end of the array (expands if necessary)
void addValue(int*& numArray, int& size, int& capacity, int value);

// Function to remove the value at a specified index and shift the array
void removeValue(int*& numArray, int& size, int index);

// Function to print the current array elements
void printArray(int numArray[], int size);

#endif
