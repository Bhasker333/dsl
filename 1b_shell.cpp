// Assignment No. 1b
//shell sort

#include <iostream>
using namespace std;

// Class 'student' to store and manage student details
class student {
    int rno;            // Roll number of the student
    string name;        // Name of the student
    float sgpa;         // SGPA (Semester Grade Point Average)

public:
    // Method to read student details from the user
    void read() {
        cout << "Enter the name: ";
        cin.ignore();               // Clear the input buffer
        getline(cin, name);         // Read a full line for the name
        cout << "Enter the roll no: ";
        cin >> rno;                 // Input roll number
        cout << "Enter the SGPA: ";
        cin >> sgpa;                // Input SGPA
    }

    // Method to display student details
    void display() {
        cout << "Name: " << name << endl;     // Print name
        cout << "Roll no: " << rno << endl;   // Print roll number
        cout << "SGPA: " << sgpa << endl;     // Print SGPA
    }

    // Declare a friend function to allow it access to private members
    friend void shellsort(student s[], int n);
};

// Function to sort an array of 'student' objects using Shell Sort
void shellsort(student s[], int n) {
    int interval = n / 2; // Start with an initial gap equal to half the array size

    // Continue until the gap becomes 0
    while (interval >= 1) {
        // Traverse the array starting from 'interval' to the end
        for (int i = interval; i < n; i++) {
            student temp = s[i]; // Store the current element for comparison
            int j = i - interval;

            // Compare and shift elements in the current gap sequence
            for (; j >= 0; j -= interval) {
                if (s[j].rno > temp.rno) { // Compare roll numbers
                    s[j + interval] = s[j]; // Shift the larger element forward
                } else {
                    break; // Stop when the correct position is found
                }
            }
            s[j + interval] = temp; // Insert the element at the correct position
        }

        // Reduce the gap for the next pass
        interval /= 2;
    }
}

int main() {
    student sobj[10]; // Array to store details of up to 10 students
    int n;

    // Input the number of students
    cout << "Enter the number of students: ";
    cin >> n;

    // Input details of each student
    for (int i = 0; i < n; i++) {
        sobj[i].read();
    }

    // Sort the students based on their roll numbers using Shell Sort
    shellsort(sobj, n);

    // Display the sorted student details
    cout << endl;
    cout << "After sorting, student details are: " << endl;
    for (int i = 0; i < n; i++) {
        sobj[i].display();
    }

    return 0;
}
