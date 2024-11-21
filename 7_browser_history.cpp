//BROWSER HISTORY


#include<iostream>
using namespace std;

// Define a structure for a linked list node to store URL and a pointer to the next node
struct node {
    string url;    // URL of the webpage
    node* next;    // Pointer to the next node
};

// Define a stack class for managing the browser history
class stack {
    node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    stack() {
        top = NULL;
    }

    // Push function to add a new URL to the stack
    void push(string data) {
        node* nn = new node; // Create a new node
        if (!nn) return;     // Check if memory allocation failed
        nn->url = data;      // Store the URL in the new node
        nn->next = NULL;     // Initialize next pointer to NULL

        if (top == NULL) {   // If stack is empty, make the new node the top
            top = nn;
            return;
        }

        nn->next = top;      // Link the new node to the current top
        top = nn;            // Update top to the new node
    }

    // Pop function to remove and return the top URL from the stack
    string pop() {
        string u;
        if (top == NULL) {   // If stack is empty, return "no page"
            return "no page";
        }
        u = top->url;        // Store the URL of the top node
        node* p = top;       // Temporary pointer to the top node
        top = top->next;     // Update top to the next node
        delete p;            // Delete the old top node
        return u;            // Return the URL
    }

    // Check if the stack is empty
    int isEmpty() {
        return top == NULL;
    }

    // Peek function to return the top URL without removing it
    string peek() {
        if (top == NULL) {   // If stack is empty, return "no page"
            return "no page";
        }
        return top->url;     // Return the URL of the top node
    }
};

// Define a web browser class to manage history and navigation
class webBrowser {
    stack s1, s2; // Two stacks for back and forward history

public:
    // Function to open a new URL and add it to the browsing history
    void openURL(string s) {
        s1.push(s);
    }

    // Function to navigate back to the previous page
    void back() {
        if (!s1.isEmpty()) {
            s2.push(s1.pop()); // Move the current page from s1 to s2
        }
    }

    // Function to navigate forward to the next page
    void forward() {
        if (!s2.isEmpty()) {
            s1.push(s2.pop()); // Move the top page from s2 back to s1
        }
    }

    // Function to check if both back and forward histories are empty
    bool checkHistory() {
        return s1.isEmpty() && s2.isEmpty();
    }

    // Function to display the current page
    void current() {
        string page = s1.peek(); // Get the top URL from the back stack
        if (page == "no page") {
            cout << "No current page" << endl;
        } else {
            cout << "Current page: " << page << endl;
        }
    }
};

// Main function to demonstrate the browser history management system
int main() {
    webBrowser w1; // Create a web browser instance
    int choice;
    string url;

    do {
        // Menu-driven interface for browser history management system
        cout << "\n=== Browser History Management ===\n";
        cout << "1. Open URL\n";
        cout << "2. Go Back\n";
        cout << "3. Go Forward\n";
        cout << "4. View Current Page\n";
        cout << "5. Check if History is Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter URL to open: ";
                cin >> url;
                w1.openURL(url);
                break;

            case 2:
                w1.back();
                break;

            case 3:
                w1.forward();
                break;

            case 4:
                w1.current();
                break;

            case 5:
                if (w1.checkHistory()) {
                    cout << "No history available (both back and forward history are empty)." << endl;
                } else {
                    cout << "History is not empty." << endl;
                }
                break;

            case 6:
                cout << "Exiting the browser history management system.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
