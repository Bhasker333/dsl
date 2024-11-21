/*
PREFIX POSTIFIX
*/

#include <iostream>
using namespace std;

// Template class for Stack, enabling it to handle multiple data types
template <class T>
class Stack {
    T* a;             // Array to store stack elements
    int top;          // Index of the top element
    int size;         // Maximum size of the stack

public:
    // Constructor to initialize stack
    Stack(int n = 20) {
        a = new T[n]; // Dynamically allocate memory for the stack
        if (!a) return;
        top = -1;     // Initialize top to -1 (stack is empty)
        size = n;     // Set maximum size
    }

    // Function to check if the stack is full
    int isFullStack() {
        return top == size - 1;
    }

    // Function to check if the stack is empty
    int isEmptyStack() {
        return top == -1;
    }

    // Function to push an element onto the stack
    void push(T ele) {
        if (isFullStack()) {
            cout << "Stack is full\n";
            return;
        }
        a[++top] = ele; // Increment top and insert element
    }

    // Function to pop an element from the stack
    T pop() {
        if (isEmptyStack()) {
            cout << "Stack is empty!!\n";
            return '\0'; // Return null character if stack is empty
        }
        return a[top--]; // Return top element and decrement top
    }

    // Function to return the top element without removing it
    T topElement() {
        if (!isEmptyStack()) {
            return a[top];
        }
        return '\0';
    }

    // Function to determine the precedence of operators
    int prec(char c) {
        if (c == '^') return 3;                     // Higher precedence for exponentiation
        else if (c == '/' || c == '*') return 2;    // Moderate precedence for multiplication/division
        else if (c == '+' || c == '-') return 1;    // Lower precedence for addition/subtraction
        else return -1;                             // Invalid operator
    }

    // Function to convert infix expression to postfix
    void infixToPostfix(char exp[], char result[]) {
        int i = 0, j = 0;
        while (exp[i] != '\0') {
            if (exp[i] >= '0' && exp[i] <= '9') { // Handle operand (number)
                while (exp[i] != '\0' && exp[i] >= '0' && exp[i] <= '9') {
                    result[j++] = exp[i++];       // Append operand to result
                }
                result[j++] = ' ';               // Add space for separation
            } else if (exp[i] == '(') {          // Handle opening parenthesis
                push('(');
                i++;
            } else if (exp[i] == ')') {          // Handle closing parenthesis
                while (!isEmptyStack() && topElement() != '(') {
                    result[j++] = topElement();  // Append operators until '(' is found
                    result[j++] = ' ';
                    pop();
                }
                pop(); // Pop the '('
                i++;
            } else {                             // Handle operators
                while (!isEmptyStack() && prec(exp[i]) <= prec(topElement())) {
                    result[j++] = topElement();  // Append operators with higher or equal precedence
                    result[j++] = ' ';
                    pop();
                }
                push(exp[i]); // Push the current operator
                i++;
            }
        }

        // Pop remaining operators from the stack
        while (!isEmptyStack()) {
            result[j++] = topElement();
            result[j++] = ' ';
            pop();
        }
        result[j] = '\0'; // Null-terminate the result
    }

    // Function to evaluate a postfix expression
    int evaluatePostfix(char postfix[]) {
        Stack<int> evalStack(20); // Stack for evaluation
        int i = 0;
        while (postfix[i] != '\0') {
            if (postfix[i] >= '0' && postfix[i] <= '9') { // Handle operand (number)
                int num = 0;
                while (postfix[i] != '\0' && postfix[i] >= '0' && postfix[i] <= '9') {
                    num = num * 10 + (postfix[i] - '0'); // Convert character to integer
                    i++;
                }
                evalStack.push(num); // Push the number onto the evaluation stack
            } else if (postfix[i] == ' ') {       // Ignore spaces
                i++;
            } else {                              // Handle operator
                int val2 = evalStack.pop();       // Pop the second operand
                int val1 = evalStack.pop();       // Pop the first operand
                switch (postfix[i]) {             // Perform the operation
                    case '+': evalStack.push(val1 + val2); break;
                    case '-': evalStack.push(val1 - val2); break;
                    case '*': evalStack.push(val1 * val2); break;
                    case '/': evalStack.push(val1 / val2); break;
                }
                i++;
            }
        }
        return evalStack.pop(); // Final result is at the top of the stack
    }
};

int main() {
    Stack<char> s;
    char exp[100], postfix[100];

    cout << "Enter the infix expression: ";
    cin >> exp; // Input the infix expression

    s.infixToPostfix(exp, postfix); // Convert infix to postfix
    cout << "Postfix expression: " << postfix << endl;

    int result = s.evaluatePostfix(postfix); // Evaluate the postfix expression
    cout << "Result of the postfix evaluation: " << result << endl;

    return 0;
}
