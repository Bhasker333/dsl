//insertion sort


#include <iostream>
using namespace std;

// Class to represent a student
class student {
    int rno;           // Roll number of the student
    char name[20];     // Name of the student (character array with fixed size)
    float sgpa;        // SGPA (Semester Grade Point Average)

public:
    // Function to read the student details from the user
    void read() {
        cout << "Enter the roll number: ";
        cin >> rno;
        cout << "Enter the student name: ";
        cin >> name; // Reading a string (no spaces allowed in input)
        cout << "Enter the SGPA: ";
        cin >> sgpa;
    }

    // Function to display the student details
    void display() {
        cout << "Roll.no: " << rno << endl;
        cout << "Student name: " << name << endl;
        cout << "SGPA: " << sgpa << endl;
    }

    // Declare the `insertionsort` function as a friend of the class
    // This allows it to access private members of the class
    friend void insertionsort(int n, student s[]);
};

// Function to sort an array of students by their roll numbers using insertion sort
void insertionsort(int n, student s[]) {
    // Loop over each student starting from the second one
    for (int i = 1; i < n; i++) {
        student x = s[i]; // Take the current student as the key
        int j = i - 1;

        // Move all students with roll numbers greater than `x.rno` one position ahead
        while (j >= 0 && x.rno <= s[j].rno) {
            s[j + 1] = s[j];
            j--;
        }

        // Insert the key in its correct position
        s[j + 1] = x;
    }
}

int main() {
    student sobj[10]; // Array to store up to 10 student objects
    int n;            // Number of students

    // Input the number of students
    cout << "Enter the number of the students: ";
    cin >> n;

    // Input details of each student
    cout << "Enter the details of students:" << endl;
    for (int i = 0; i < n; i++) {
        sobj[i].read(); // Call the `read` function for each student
    }

    // Sort the students by their roll numbers using insertion sort
    insertionsort(n, sobj);

    // Display the sorted list of students
    cout << "After sorting, student details are: " << endl;
    for (int i = 0; i < n; i++) {
        sobj[i].display(); // Call the `display` function for each student
    }

    return 0; // Indicate that the program ended successfully
}
