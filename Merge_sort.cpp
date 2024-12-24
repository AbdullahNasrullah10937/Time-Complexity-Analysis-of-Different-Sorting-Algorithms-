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

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free temporary arrays
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

        // Perform merge sort
        mergeSort(arr, 0, size - 1);

        // Measure end time
        auto end = chrono::high_resolution_clock::now();

        // Calculate execution time
        chrono::duration<double> duration = end - start;

        cout << "Sorted array: ";
        printArray(arr, size);

        // Output runtime
        cout << "Time taken by merge sort: " << duration.count() << " seconds" << endl;

        delete[] arr; // Free dynamically allocated memory
    }

    return 0;
}
