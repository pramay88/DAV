#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

// Merge Sort implementation
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort implementation
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> sizes;
    for(int i=100000;i<10000000;i+=1000000){
        sizes.push_back(i);
    }
    ofstream file("sorting_times.txt");

    for (int size : sizes) {
        vector<int> data(size);
        for (int& x : data) {
            x = rand() % 10001; // Random values
        }

        // Timing Merge Sort
        vector<int> merge_data = data;
        clock_t start = clock();
        mergeSort(merge_data, 0, size - 1);
        clock_t end = clock();
        double merge_time = double(end - start) / CLOCKS_PER_SEC;

        // Timing Quick Sort
        vector<int> quick_data = data;
        start = clock();
        quickSort(quick_data, 0, size - 1);
        end = clock();
        double quick_time = double(end - start) / CLOCKS_PER_SEC;

        // Write results to file
        file << size << " " << merge_time << " " << quick_time << "\n";    
    }
    file.close();
    cout << "Sorting times written to sorting_times_ctime.txt" << endl;
    return 0;
}
