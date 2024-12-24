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

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Set the pivot element
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; ++j) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap elements
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in the correct position
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort the subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

        // Perform quick sort
        quickSort(arr, 0, size - 1);

        // Measure end time
        auto end = chrono::high_resolution_clock::now();

        // Calculate execution time
        chrono::duration<double> duration = end - start;

        cout << "Sorted array: ";
        printArray(arr, size);

        // Output runtime
        cout << "Time taken by quick sort: " << duration.count() << " seconds" << endl;

        delete[] arr; // Free dynamically allocated memory
    }

    return 0;
}
