// Assignment No 1c
//radix sort

#include <iostream>
using namespace std;

// Define a class 'student' to manage student details
class student {
    string name;   // Name of the student
    int rno;       // Roll number of the student
    float sgpa;    // SGPA (Semester Grade Point Average)

public:
    // Method to input student details
    void read() {
        cout << "Enter the roll_no: ";
        cin >> rno;                // Input roll number
        cout << "Enter the name: ";
        cin.ignore();              // Clear input buffer
        getline(cin, name);        // Input full name
        cout << "Enter the SGPA: ";
        cin >> sgpa;               // Input SGPA
    }

    // Method to display student details
    void display() {
        cout << "Roll_No: " << rno << endl;   // Print roll number
        cout << "Name: " << name << endl;     // Print name
        cout << "SGPA: " << sgpa << endl;     // Print SGPA
    }

    // Friend functions to access private members
    friend int getMax(student s[], int n);             // Get the maximum roll number
    friend void countsort(student s[], int n, int EXP); // Perform Counting Sort for a specific digit
};

// Function to find the maximum roll number in the array
int getMax(student s[], int n) {
    int max = s[0].rno; // Assume the first roll number is the largest
    for (int i = 1; i < n; i++) {
        if (s[i].rno > max) { // Update max if a larger roll number is found
            max = s[i].rno;
        }
    }
    return max; // Return the maximum roll number
}

// Counting Sort function to sort students based on the current digit (EXP)
void countsort(student s[], int n, int EXP) {
    student output[10];      // Output array to store sorted students
    int count[10] = {0};     // Count array to store the frequency of digits

    // Count the occurrences of each digit at position EXP
    for (int i = 0; i < n; i++) {
        int digit = (s[i].rno / EXP) % 10; // Extract the digit at EXP
        count[digit]++;
    }

    // Update count[i] to store the cumulative frequency
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array in a stable manner
    for (int i = n - 1; i >= 0; i--) {
        int digit = (s[i].rno / EXP) % 10;  // Extract the digit at EXP
        count[digit]--;                     // Decrement the frequency count
        output[count[digit]] = s[i];        // Place the student in the correct position
    }

    // Copy the sorted output array back to the original array
    for (int i = 0; i < n; i++) {
        s[i] = output[i];
    }
}

int main() {
    int n;

    // Input the number of students
    cout << "Enter the number of students: ";
    cin >> n;

    student s[n]; // Array to store student details

    // Input details for each student
    for (int i = 0; i < n; i++) {
        s[i].read();
    }

    // Display student details before sorting
    cout << "Before sorting, student details are: " << endl;
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    // Get the maximum roll number to determine the number of digits
    int max = getMax(s, n);

    // Perform Radix Sort, starting with the least significant digit (LSD)
    for (int EXP = 1; max / EXP > 0; EXP *= 10) {
        countsort(s, n, EXP); // Sort based on the current digit
    }

    // Display student details after sorting
    cout << "After sorting, student details are: " << endl;
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    return 0;
}
