//HASHING

#include <iostream>
#include <cstring> // For strncpy (used for safely copying strings)

using namespace std;

// Define the Employee class
class Employee {
public:
    int id; // Employee ID
    char name[50]; // Fixed size character array to store employee name

    // Constructor to initialize an Employee object
    Employee(int id, const char* name) : id(id) {
        // Copy the name into the `name` array safely
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0'; // Ensure null termination
    }
};

// Define a Node structure for the linked list
struct Node {
    Employee emp; // Each node stores an Employee object
    Node* next; // Pointer to the next node in the list

    // Constructor to initialize a Node with employee data
    Node(int id, const char* name) : emp(id, name), next(nullptr) {}
};

// Define a HashTable class for storing employee data
class HashTable {
private:
    static const int hashSize = 10; // Size of the hash table
    Node** table; // Array of pointers to linked lists (buckets)

    // Hash function to compute index based on employee ID
    int hashFunction(int id) {
        return id % hashSize; // Simple modulo operation
    }

public:
    // Constructor to initialize the hash table
    HashTable() {
        table = new Node*[hashSize]; // Allocate memory for table
        for (int i = 0; i < hashSize; ++i) {
            table[i] = nullptr; // Initialize each bucket to nullptr
        }
    }

    // Destructor to clean up allocated memory
    ~HashTable() {
        for (int i = 0; i < hashSize; ++i) {
            Node* current = table[i];
            while (current) {
                Node* temp = current; // Store current node
                current = current->next; // Move to the next node
                delete temp; // Delete the stored node
            }
        }
        delete[] table; // Free the table array
    }

    // Function to insert an employee into the hash table
    void insert(int id, const char* name) {
        int index = hashFunction(id); // Compute the index using hash function
        Node* newNode = new Node(id, name); // Create a new node
        newNode->next = table[index]; // Insert at the beginning of the list
        table[index] = newNode; // Update the table pointer
    }

    // Function to search for an employee by ID
    Employee* search(int id) {
        int index = hashFunction(id); // Compute the index
        Node* current = table[index]; // Get the linked list at the index
        while (current) {
            if (current->emp.id == id) { // Check if IDs match
                return &current->emp; // Return pointer to the employee
            }
            current = current->next; // Move to the next node
        }
        return nullptr; // Return nullptr if not found
    }

    // Function to display all employees in the hash table
    void display() {
        for (int i = 0; i < hashSize; ++i) {
            if (table[i] != nullptr) { // If the bucket is not empty
                cout << "Index " << i << ": ";
                Node* current = table[i];
                while (current) {
                    // Print the ID and name of the employee
                    cout << "[ID: " << current->emp.id << ", Name: " << current->emp.name << "] ";
                    current = current->next; // Move to the next node
                }
                cout << endl;
            }
        }
    }
};

int main() {
    HashTable ht; // Create a HashTable object
    int choice, id; // Variables for user input
    char name[50]; // Array to store employee name
    Employee* emp = nullptr; // Pointer to store search results

    do {
        // Display menu options
        cout << "\nMenu:\n";
        cout << "1. Insert Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Display Employees\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Insert an employee
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Employee Name: ";
                cin.ignore(); // Ignore newline left in the input buffer
                cin.getline(name, sizeof(name)); // Get the full name
                ht.insert(id, name); // Insert the employee into the hash table
                cout << "Employee inserted successfully.\n";
                break;

            case 2: // Search for an employee
                cout << "Enter Employee ID to search: ";
                cin >> id;
                emp = ht.search(id); // Search for the employee
                if (emp) {
                    // If found, display employee details
                    cout << "Employee found: ID = " << emp->id << ", Name = " << emp->name << endl;
                } else {
                    // If not found, display message
                    cout << "Employee with ID " << id << " not found.\n";
                }
                break;

            case 3: // Display all employees
                ht.display();
                break;

            case 4: // Exit
                cout << "Exiting...\n";
                break;

            default: // Handle invalid choices
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4); // Continue until user chooses to exit

    return 0;
}
