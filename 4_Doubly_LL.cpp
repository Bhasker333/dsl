/*

Assignment 4
DOUBLY LL

*/

#include <iostream>
using namespace std;

// Define the structure for word node in doubly linked list
struct word {
    string t;      // To store the word (text)
    word* next;    // Pointer to the next node
    word* prev;    // Pointer to the previous node
};

// Class to manage the text buffer using doubly linked list
class textbuffer {
    word* head;    // Pointer to the first node (head)
    word* tail;    // Pointer to the last node (tail)

public:
    // Constructor to initialize the empty list
    textbuffer() {
        head = NULL;
        tail = NULL;
    }

    // Function to append a new word to the end of the list
    void append(string w) {
        word* nw = new word;  // Create a new word node
        nw->t = w;            // Assign the word to the new node
        nw->next = NULL;      // The next pointer of the new node will be NULL
        nw->prev = NULL;      // The previous pointer of the new node will be NULL
        if (head == NULL) {   // If the list is empty
            head = tail = nw; // The new node becomes both head and tail
        } else {
            tail->next = nw;  // Link the current tail's next to the new node
            nw->prev = tail;  // Link the new node's previous to the current tail
            tail = nw;        // Update the tail pointer to the new node
        }
    }

    // Function to delete the first node of the list
    void deleteFirstNode() {
        if (!head) {  // If the list is empty
            cout << "The text buffer is empty. Nothing to delete!" << endl;
            return;
        }
        word* temp = head;     // Create a temporary pointer to the head
        head = head->next;     // Update the head to the second node
        if (head) {
            head->prev = NULL; // Set the new head's prev to NULL
        } else {
            tail = NULL;       // If the list becomes empty, reset tail to NULL
        }
        delete temp;           // Delete the old head node
        cout << "First word deleted successfully!" << endl;
    }

    // Function to delete the last node of the list
    void deleteLastNode() {
        if (!tail) {  // If the list is empty
            cout << "The text buffer is empty. Nothing to delete!" << endl;
            return;
        }
        word* temp = tail;     // Create a temporary pointer to the tail
        tail = tail->prev;     // Update the tail to the previous node
        if (tail) {
            tail->next = NULL; // Set the new tail's next to NULL
        } else {
            head = NULL;       // If the list becomes empty, reset head to NULL
        }
        delete temp;           // Delete the old tail node
        cout << "Last word deleted successfully!" << endl;
    }

    // Function to display all the words in the text buffer
    void display() {
        if (!head) {
            cout << "The text buffer is empty!" << endl;
            return;
        }
        word* temp = head;  // Start from the head node
        cout << "Text Buffer: ";
        while (temp) {      // Traverse the list until the end
            cout << temp->t << " "; // Print the word in the node
            temp = temp->next;      // Move to the next node
        }
        cout << endl;
    }

    // Function to search for a word in the text buffer
    void search(string w) {
        if (!head) {
            cout << "The text buffer is empty!" << endl;
            return;
        }
        word* temp = head;  // Start from the head node
        while (temp) {      // Traverse the list
            if (temp->t == w) { // If the word matches
                cout << "Word '" << w << "' found in the text buffer." << endl;
                return;
            }
            temp = temp->next;  // Move to the next node
        }
        cout << "Word '" << w << "' not found in the text buffer." << endl;
    }

    // Function to print all words in the text buffer in reverse order
    void printReverse() {
        if (!tail) {
            cout << "The text buffer is empty!" << endl;
            return;
        }
        word* temp = tail;  // Start from the tail node
        cout << "Text Buffer in Reverse: ";
        while (temp) {      // Traverse the list backwards
            cout << temp->t << " "; // Print the word in the node
            temp = temp->prev;      // Move to the previous node
        }
        cout << endl;
    }
};

int main() {
    textbuffer tb; // Create a textbuffer object
    int choice;
    string word;

    do {
        cout << "\n--- Text Editor Menu ---\n";
        cout << "1. Insert Text\n";
        cout << "2. Delete First Word\n";
        cout << "3. Delete Last Word\n";
        cout << "4. Display Text\n";
        cout << "5. Search Text\n";
        cout << "6. Print Text in Reverse\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the word to insert: ";
            cin >> word;
            tb.append(word);
            cout << "Word inserted successfully!" << endl;
            break;

        case 2:
            tb.deleteFirstNode();
            break;

        case 3:
            tb.deleteLastNode();
            break;

        case 4:
            tb.display();
            break;

        case 5:
            cout << "Enter the word to search: ";
            cin >> word;
            tb.search(word);
            break;

        case 6:
            tb.printReverse();
            break;

        case 7:
            cout << "Exiting the text editor. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
