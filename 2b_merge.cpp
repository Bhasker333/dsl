//merge sort
// Assignment 2b

#include<iostream>
using namespace std;

// Define a class 'Employee' to store and manage employee details
class Employee {
    string name;   // Employee name
    int emp_id;    // Employee ID
    float salary;  // Employee salary

public:
    // Method to read employee details
    void read() {
        cout << "Enter the employee name: ";
        cin.ignore();              // Clear input buffer
        getline(cin, name);        // Input full name
        cout << "Enter the employee ID: ";
        cin >> emp_id;             // Input employee ID
        cout << "Enter the salary: ";
        cin >> salary;             // Input employee salary
    }

    // Method to display employee details
    void display() {
        cout << "Name: " << name << "\n";   // Print name
        cout << "ID: " << emp_id << "\n";   // Print ID
        cout << "Salary: " << salary << "\n"; // Print salary
    }

    // Friend functions for Merge Sort
    friend void mergesort(Employee emp[], int left, int right); // Recursive Merge Sort
    friend void merge(Employee emp[], int low, int mid, int high); // Merge function
};

// Function to perform recursive Merge Sort on employee array
void mergesort(Employee emp[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Calculate midpoint to split the array
        mergesort(emp, left, mid);           // Sort the left half
        mergesort(emp, mid + 1, right);      // Sort the right half
        merge(emp, left, mid, right);        // Merge the two sorted halves
    }
}

// Function to merge two sorted halves of the employee array
void merge(Employee emp[], int low, int mid, int high) {
    Employee temp[50]; // Temporary array to store sorted elements
    int left = low;    // Start index of the left sub-array
    int right = mid + 1; // Start index of the right sub-array
    int i = 0;         // Index for the temp array

    // Merge elements based on alphabetical order of names
    while (left <= mid && right <= high) {
        if (emp[left].name <= emp[right].name) { // Compare names lexicographically
            temp[i] = emp[left]; // Add employee from the left sub-array
            left++;
        } else {
            temp[i] = emp[right]; // Add employee from the right sub-array
            right++;
        }
        i++;
    }

    // Add remaining elements from the left sub-array (if any)
    while (left <= mid) {
        temp[i] = emp[left];
        left++;
        i++;
    }

    // Add remaining elements from the right sub-array (if any)
    while (right <= high) {
        temp[i] = emp[right];
        right++;
        i++;
    }

    // Copy the sorted elements back to the original array
    for (int i = low; i <= high; i++) {
        emp[i] = temp[i - low];
    }
}

int main() {
    int n;

    // Input the number of employees
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee obj[n]; // Array to store employee details

    // Input employee details
    for (int i = 0; i < n; i++) {
        obj[i].read();
    }

    // Sort employees by name using Merge Sort
    mergesort(obj, 0, n - 1);

    // Display sorted employee details
    cout << "After sorting employees by name:\n";
    for (int i = 0; i < n; i++) {
        obj[i].display();
    }

    return 0;
}
