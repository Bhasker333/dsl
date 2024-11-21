/*
CIRCULAR LL
*/

#include <iostream>
using namespace std;

// Structure to represent a node in the circular linked list
struct node {
    string r;     // Route name
    node* next;   // Pointer to the next node
};

// Class to manage the circular linked list
class Circular {
public:
    node* head;   // Pointer to the head of the list
    node* tail;   // Pointer to the tail of the list

    // Constructor to initialize an empty list
    Circular() {
        head = NULL;
        tail = NULL;
    }

    // Function to add a node at the beginning of the list
    void add_beg(string s) {
        node* nn = new node;
        if (!nn) return; // Check for memory allocation failure
        nn->r = s;

        if (!head) { // If the list is empty
            head = nn;
            tail = nn;
            nn->next = head; // Point the next of the new node to itself
            return;
        }

        nn->next = head;
        tail->next = nn;
        head = nn;
    }

    // Function to add a node at the nth position in the list
    void add_nth(string s, int n) {
        node* nn = new node;
        if (!nn) return; // Check for memory allocation failure
        nn->r = s;

        if (n == 1) { // If position is 1, add at the beginning
            add_beg(s);
            return;
        }

        node* p = head;
        int count = 1;

        while (count < n - 1 && p->next != head) {
            p = p->next;
            count++;
        }

        if (count != n - 1) {
            cout << "Position out of bounds" << endl;
            delete nn;
            return;
        }

        nn->next = p->next;
        p->next = nn;

        if (p == tail) {
            tail = nn;
        }
    }

    // Function to remove a node by route name
    void remove(string val) {
        if (!head) {
            cout << "Nothing to delete" << endl;
            return;
        }

        if (head->next == head && head->r == val) { // Single node case
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        node* p = head;
        node* q = NULL;

        if (head->r == val) { // Deleting head node
            tail->next = head->next;
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        do {
            q = p->next;
            if (q->r == val) {
                p->next = q->next;
                if (q == tail) {
                    tail = p;
                }
                delete q;
                return;
            }
            p = p->next;
        } while (p != head);

        cout << "Node not found to delete" << endl;
    }

    // Function to search for a route by name
    void search(string key) {
        if (!head) {
            cout << "Nothing to search" << endl;
            return;
        }

        node* p = head;
        do {
            if (p->r == key) {
                cout << "Route found: " << key << endl;
                return;
            }
            p = p->next;
        } while (p != head);

        cout << "Route not found" << endl;
    }

    // Function to display all nodes in the list
    void display() {
        if (!head) {
            cout << "No routes to display" << endl;
            return;
        }

        node* p = head;
        do {
            cout << p->r << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }
};

int main() {
    Circular obj;
    int choice;
    string route;
    int position;

    do {
        cout << "\n=== Navigation System Menu ===\n";
        cout << "1. Add Route at Beginning\n";
        cout << "2. Add Route at Nth Position\n";
        cout << "3. Remove Route\n";
        cout << "4. Search Route\n";
        cout << "5. Display All Routes\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter route name to add: ";
                cin >> route;
                obj.add_beg(route);
                break;

            case 2:
                cout << "Enter route name to add: ";
                cin >> route;
                cout << "Enter position to add: ";
                cin >> position;
                obj.add_nth(route, position);
                break;

            case 3:
                cout << "Enter route name to remove: ";
                cin >> route;
                obj.remove(route);
                break;

            case 4:
                cout << "Enter route name to search: ";
                cin >> route;
                obj.search(route);
                break;

            case 5:
                obj.display();
                break;

            case 6:
                cout << "Exiting Navigation System.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
