#include "main.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

// Function to check if a specific value exists in the array
int isCheck(int numArray[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (numArray[i] == val) {  // If value is found, return its index
            return i;
        }
    }
    return -1;  // Return -1 if the value isn't found
}

// Function to modify the value at a specified index and return both the old and new values
pair<int, int> oldAndnew(int numArray[], int size, int new_val, int index) {
    try {
        // Ensure index is within bounds
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds.");
        }

        int oldvalue = numArray[index];  // Store the old value
        numArray[index] = new_val;  // Update the value
        return make_pair(oldvalue, new_val);  // Return old and new values

    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return make_pair(-1, -1);  // Return error values if an exception occurs
    }
}

// Function to add a new value at the end of the array, expanding the array if necessary
void addValue(int*& numArray, int& size, int& capacity, int value) {
    try {
        // Check if the array is full, and if so, resize it
        if (size == capacity) {
            capacity *= 2;  // Double the capacity

            // Create a new array with doubled capacity
            int* newArray = new int[capacity];

            // Copy the old array contents to the new array
            for (int i = 0; i < size; ++i) {
                newArray[i] = numArray[i];
            }

            delete[] numArray;  // Delete the old array
            numArray = newArray;  // Point to the new array
        }

        numArray[size] = value;  // Add the new value at the end
        size++;  // Increase the size of the array

    }
    catch (const bad_alloc& e) {
        cout << "Memory allocation failed: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Error occurred: " << e.what() << endl;
    }
}

// Function to remove a value at a specific index and shift the remaining values
void removeValue(int*& numArray, int& size, int index) {
    try {
        // Ensure index is within bounds
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds.");
        }

        // Shift the elements to the left to remove the value at the index
        for (int i = index; i < size - 1; ++i) {
            numArray[i] = numArray[i + 1];
        }

        size--;  // Decrease the size of the array

    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Function to print the current elements in the array
void printArray(int numArray[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << numArray[i] << " ";  // Print each element in the array
    }
    cout << endl;
}

int main() {
    // Open the file containing data
    ifstream file("C:\\Users\\UMKCE\\Desktop\\New folder\\A1input.txt");

    // Check if the file opened successfully
    if (!file.is_open()) {
        cout << "Error occurred opening the file";
        return 1;
    }

    int* numArray = new int[100];  // Create an array with initial size of 100
    int size = 0;  // Initialize the size of the array
    int capacity = 100;  // Set the initial capacity

    // Read data from the file into the array
    for (int i = 0; i < 100 && file >> numArray[i]; ++i) {
        size++;  // Increment the size for each value read
    }

    file.close();  // Close the file after reading

    // Display the current array
    printArray(numArray, size);

    try {
        // Modify an element in the array by index
        int index, newValue;
        cout << "Enter index and new value to modify: ";
        cin >> index >> newValue;

        pair<int, int> modified = oldAndnew(numArray, size, newValue, index);
        if (modified.first != -1) {
            cout << "Replaced " << modified.first << " with " << modified.second << endl;
        }

        // Display the updated array after modification
        printArray(numArray, size);
    }
    catch (const exception& e) {
        cout << "Input error: " << e.what() << endl;
    }

    try {
        // Add a new value to the array
        int val;
        cout << "Enter a value to add: ";
        cin >> val;

        addValue(numArray, size, capacity, val);  // Add the value

        cout << "Value added successfully." << endl;

        // Display the updated array after adding the value
        printArray(numArray, size);
    }
    catch (const exception& e) {
        cout << "Error while adding value: " << e.what() << endl;
    }

    try {
        // Remove a value from the array by index
        int removeIndex;
        cout << "Enter index of value to remove: ";
        cin >> removeIndex;

        removeValue(numArray, size, removeIndex);  // Remove the value

        cout << "Value removed successfully." << endl;

        // Display the updated array after removal
        printArray(numArray, size);
    }
    catch (const exception& e) {
        cout << "Error while removing value: " << e.what() << endl;
    }

    try {
        // Check if a specific value exists in the array
        int searchValue;
        cout << "Enter a value to check if it exists in the array: ";
        cin >> searchValue;

        int foundIndex = isCheck(numArray, size, searchValue);  // Check for the value

        if (foundIndex != -1) {
            cout << "Value " << searchValue << " found at index " << foundIndex << endl;
        }
        else {
            cout << "Value " << searchValue << " not found in the array." << endl;
        }
    }
    catch (const exception& e) {
        cout << "Error while searching for value: " << e.what() << endl;
    }

    delete[] numArray;  // Free the dynamically allocated array
    return 0;
}
