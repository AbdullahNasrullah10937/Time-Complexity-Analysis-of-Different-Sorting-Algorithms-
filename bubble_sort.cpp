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

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            // Swap if the current element is greater than the next
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
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

        // Perform bubble sort
        bubbleSort(arr, size);

        // Measure end time
        auto end = chrono::high_resolution_clock::now();

        // Calculate execution time
        chrono::duration<double> duration = end - start;

        cout << "Sorted array: ";
        printArray(arr, size);

        // Output runtime
        cout << "Time taken by bubble sort: " << duration.count() << " seconds" << endl;

        delete[] arr; // Free dynamically allocated memory
    }

    return 0;
}
