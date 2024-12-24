#include <iostream>
#include <chrono> 
#include <cstdlib> 
#include <ctime>   

using namespace std;

void populateArray(int arr[], int size) {
    srand(time(0)); 
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000;
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;

    while (true) {
        cout << "\nEnter the size of the array (or 0 to exit): ";
        cin >> size;

        if (size == 0) {
            cout << "Exiting program." << endl;
            break;
        }

        int *arr = new int[size]; 

        
        populateArray(arr, size);

        cout << "Unsorted array: ";
        printArray(arr, size);

        // Measure start time
        auto start = chrono::high_resolution_clock::now();
        // Perform selection sort
        selectionSort(arr, size);
        // Measure end time
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;

        cout << "Sorted array: ";
        printArray(arr, size);

        // Output runtime
        cout << "Time taken by selection sort: " << duration.count() << " seconds" << endl;

        delete[] arr; 
    }

    return 0;
}
