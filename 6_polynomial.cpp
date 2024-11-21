//POLYNOMIAL


#include <iostream>
using namespace std;

// Define a structure to represent a term in the polynomial
struct node {
    int coeff;   // Coefficient of the term
    int pow;     // Power of the term
    node* next;  // Pointer to the next term
};

// Define a class to represent a Polynomial
class Polynomial {
public:
    node* head;  // Pointer to the head of the linked list representing the polynomial

    // Constructor to initialize an empty polynomial
    Polynomial() {
        head = NULL;
    }

    // Function to add a term to the polynomial
    void add_term(int coeff, int pow) {
        node* nn = new node;
        nn->coeff = coeff;
        nn->pow = pow;
        nn->next = NULL;

        if (!head) {
            head = nn;
            return;
        }

        if (pow > head->pow) {
            nn->next = head;
            head = nn;
            return;
        }

        node* temp = head;
        while (temp->next && temp->next->pow > pow) {
            temp = temp->next;
        }

        if (temp->pow == pow) {
            temp->coeff += coeff;
        } else {
            nn->next = temp->next;
            temp->next = nn;
        }
    }

    // Function to display the polynomial
    void display() {
        if (!head) {
            cout << "0" << endl;
            return;
        }

        node* temp = head;
        while (temp) {
            cout << temp->coeff << "x^" << temp->pow;
            if (temp->next && temp->next->coeff >= 0) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to add two polynomials and return the resultant polynomial
    Polynomial add(Polynomial& p) {
        Polynomial result;
        node* p1 = head;
        node* p2 = p.head;

        while (p1 && p2) {
            if (p1->pow == p2->pow) {
                result.add_term(p1->coeff + p2->coeff, p1->pow);
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->pow > p2->pow) {
                result.add_term(p1->coeff, p1->pow);
                p1 = p1->next;
            } else {
                result.add_term(p2->coeff, p2->pow);
                p2 = p2->next;
            }
        }

        while (p1) {
            result.add_term(p1->coeff, p1->pow);
            p1 = p1->next;
        }

        while (p2) {
            result.add_term(p2->coeff, p2->pow);
            p2 = p2->next;
        }

        return result;
    }
};

int main() {
    Polynomial poly1, poly2, result;
    int choice, coeff, pow;

    do {
        cout << "\n=== Polynomial Operations Menu ===\n";
        cout << "1. Add term to Polynomial 1\n";
        cout << "2. Add term to Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomial 1 and Polynomial 2\n";
        cout << "6. Display Resultant Polynomial\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter coefficient and power for Polynomial 1: ";
                cin >> coeff >> pow;
                poly1.add_term(coeff, pow);
                break;

            case 2:
                cout << "Enter coefficient and power for Polynomial 2: ";
                cin >> coeff >> pow;
                poly2.add_term(coeff, pow);
                break;

            case 3:
                cout << "Polynomial 1: ";
                poly1.display();
                break;

            case 4:
                cout << "Polynomial 2: ";
                poly2.display();
                break;

            case 5:
                result = poly1.add(poly2);
                cout << "Polynomials added successfully.\n";
                break;

            case 6:
                cout << "Resultant Polynomial: ";
                result.display();
                break;

            case 7:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
