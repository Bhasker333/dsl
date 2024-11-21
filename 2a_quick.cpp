//quick sort
// Assignment 2a
// 1st program

#include <iostream>
using namespace std;

// Function to partition the array around a pivot element
int partition(int arr[], int left, int right) {
    int i = left;           // Pointer starting from the left
    int j = right;          // Pointer starting from the right
    int pivot = arr[left];  // Choosing the first element as the pivot

    // Loop until the pointers meet
    while (i < j) {
        // Increment `i` until an element greater than the pivot is found
        while (arr[i] <= pivot)
            i++;

        // Decrement `j` until an element less than or equal to the pivot is found
        while (arr[j] > pivot)
            j--;

        // Swap the elements at `i` and `j` if they are on the wrong side of the pivot
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element with the element at position `j`
    // This places the pivot in its correct sorted position
    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    return j; // Return the pivot's final position
}

// Recursive function to perform QuickSort
void QS(int arr[], int left, int right) {
    if (left < right) {
        // Partition the array and get the pivot position
        int pos = partition(arr, left, right);

        // Recursively sort the left subarray
        QS(arr, left, pos - 1);

        // Recursively sort the right subarray
        QS(arr, pos + 1, right);
    }
}

int main() {
    int n;

    // Input the size of the array
    cout << "Enter size: ";
    cin >> n;

    int arr[n]; // Create an array of size `n`

    // Input the array elements
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform QuickSort on the entire array
    QS(arr, 0, n - 1);

    // Output the sorted array
    cout << "After sorting: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }

    return 0; // Indicate successful program execution
}
