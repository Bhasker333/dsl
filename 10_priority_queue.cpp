/*
                                                      Assignment No.10
                                                      circular queue

Problem Statement:
Implement a job scheduling system for a manufacturing plant using a double-ended queue. The
system needs to efficiently manage the processing of jobs on various machines throughout the
plant. Each job has a Job_priority.
The system should support the following operations:
a. Add Job
b. Remove Job
c. Display Job
d. Search Job

*/

#include <iostream>
using namespace std;

// Job class to represent each job
class Job {
    string jobname; // Name of the job
    string jobtype; // Type of the job
    int priority;   // Priority of the job
    int times;      // Processing time for the job

public:
    Job *next, *prev; // Pointers for doubly linked list

    // Constructor to initialize pointers
    Job() {
        next = prev = NULL;
    }

    // Function to read job details
    void read() {
        cout << "Enter the job name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, jobname); // Get job name
        cout << "Enter the job type: ";
        getline(cin, jobtype); // Get job type
        cout << "Enter the priority and time: ";
        cin >> priority >> times; // Get priority and processing time
    }

    // Getter for job name
    string getJobname() {
        return jobname;
    }

    // Getter for job priority
    int getPriority() {
        return priority;
    }

    // Function to display job details
    void display() {
        cout << "Job name: " << jobname << endl;
        cout << "Job type: " << jobtype << endl;
        cout << "Priority: " << priority << endl;
        cout << "Times: " << times << endl;
    }
};

// Dequeue class to implement job scheduling
class Dequeue {
    Job *rear, *front; // Pointers to the front and rear of the deque

public:
    // Constructor to initialize deque
    Dequeue() {
        rear = front = NULL;
    }

    // Destructor to clean up memory
    ~Dequeue() {
        while (front != NULL) {
            remove_Job_Front();
        }
    }

    // Add job based on its priority
    void add_Job_Priority() {
        Job *nn = new Job; // Create a new job
        nn->read(); // Read job details

        if (front == NULL) { // If deque is empty
            front = rear = nn;
        } else if (nn->getPriority() < front->getPriority()) { // Add at front if priority is highest
            nn->next = front;
            front->prev = nn;
            front = nn;
        } else {
            Job *temp = front;
            // Traverse to find the correct position based on priority
            while (temp->next != NULL && temp->next->getPriority() <= nn->getPriority()) {
                temp = temp->next;
            }
            nn->next = temp->next; // Insert after temp
            if (temp->next != NULL) {
                temp->next->prev = nn;
            } else {
                rear = nn; // If added at the rear
            }
            temp->next = nn;
            nn->prev = temp;
        }
        cout << "Job added based on priority.\n";
    }

    // Remove a job from the front
    void remove_Job_Front() {
        if (front == NULL) { // If deque is empty
            cout << "No jobs to remove from front.\n";
            return;
        }
        Job *temp = front;
        front = front->next; // Move front pointer
        if (front != NULL) {
            front->prev = NULL;
        } else {
            rear = NULL; // If deque becomes empty
        }
        delete temp; // Free memory of removed job
        cout << "Removed job from front.\n";
    }

    // Remove a job from the rear
    void remove_Job_Back() {
        if (rear == NULL) { // If deque is empty
            cout << "No jobs to remove from back.\n";
            return;
        }
        Job *temp = rear;
        rear = rear->prev; // Move rear pointer
        if (rear != NULL) {
            rear->next = NULL;
        } else {
            front = NULL; // If deque becomes empty
        }
        delete temp; // Free memory of removed job
        cout << "Removed job from back.\n";
    }

    // Display all jobs in the deque
    void displayJob() {
        Job *temp = front; // Start from the front
        if (temp == NULL) { // If deque is empty
            cout << "No jobs in the queue.\n";
            return;
        }
        cout << "Jobs in the queue:\n";
        while (temp != NULL) { // Traverse and display all jobs
            temp->display();
            temp = temp->next;
        }
    }

    // Search for a job by name
    void searchJob(string Jname) {
        Job *temp = front;
        while (temp != NULL) { // Traverse the deque
            if (temp->getJobname() == Jname) { // If job is found
                cout << "Job is found:\n";
                temp->display();
                return;
            }
            temp = temp->next;
        }
        cout << "Job with name '" << Jname << "' not found.\n";
    }
};

int main() {
    Dequeue D; // Create a deque
    int choice;
    while (true) {
        // Display menu
        cout << "1. Add Job Based on Priority\n"
             << "2. Remove Job from Front\n"
             << "3. Remove Job from Back\n"
             << "4. Display Job\n"
             << "5. Search Job\n"
             << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                D.add_Job_Priority(); // Add job
                break;
            case 2:
                D.remove_Job_Front(); // Remove job from front
                break;
            case 3:
                D.remove_Job_Back(); // Remove job from back
                break;
            case 4:
                D.displayJob(); // Display jobs
                break;
            case 5: {
                string s;
                cout << "Enter the job name to search: ";
                cin.ignore(); // Clear input buffer
                getline(cin, s); // Get job name
                D.searchJob(s); // Search for the job
                break;
            }
            case 6:
                cout << "Exiting the program.\n";
                return 0; // Exit the program
            default:
                cout << "Invalid Choice! Try Again.\n";
        }
    }
    return 0;
}
