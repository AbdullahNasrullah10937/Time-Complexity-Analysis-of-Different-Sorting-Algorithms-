#include <iostream>
#include <chrono> // For high-resolution timing
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()

using namespace std;

void populateArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }
}

void heapify(int arr[], int size, int root) {
    int largest = root;        // Assume root is the largest
    int left = 2 * root + 1;   // Left child index
    int right = 2 * root + 2;  // Right child index

    // If left child is larger than the root
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than the current largest
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root
    if (largest != root) {
        swap(arr[root], arr[largest]);
        // Recursively heapify the affected subtree
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    // Build the max heap
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(arr, size, i);
    }

    // Extract elements from the heap one by one
    for (int i = size - 1; i >= 0; --i) {
        // Move current root to the end
        swap(arr[0], arr[i]);
        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Seed the random number generator once

    int size;

    while (true) {
        cout << "\nEnter the size of the array (or 0 to exit): ";
        cin >> size;

        if (size == 0) {
            cout << "Exiting program." << endl;
            break;
        }

        int* arr = new int[size]; // Dynamically allocate array

        populateArray(arr, size);

        cout << "Unsorted array: ";
        printArray(arr, size);

        // Measure start time
        auto start = chrono::high_resolution_clock::now();

        // Perform heap sort
        heapSort(arr, size);

        // Measure end time
        auto end = chrono::high_resolution_clock::now();

        // Calculate execution time
        chrono::duration<double> duration = end - start;

        cout << "Sorted array: ";
        printArray(arr, size);

        // Output runtime
        cout << "Time taken by heap sort: " << duration.count() << " seconds" << endl;

        delete[] arr; // Free dynamically allocated memory
    }

    return 0;
}
