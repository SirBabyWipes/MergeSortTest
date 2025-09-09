#include <iostream>
#include <chrono>
#include <cmath>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    srand(time(NULL));
    
    
    for (int i = 0; i < 10; i++) {
        auto start_time = std::chrono::high_resolution_clock::now();
        int arrSize = pow(10, i);
        int arr[arrSize];

        std::cout<<"array size = 10^"<<i<<"\n";
        for (int i = 0; i < arrSize; i++) {
            arr[i] = rand() % 1000;
        }

        /*
        std::cout <<"---Unsorted---\n";
        for (int i = 0; i < arrSize; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout <<"\n";

        std::cout <<"---Sorted---\n";
        mergeSort(arr, 0, arrSize - 1);
        for (int i = 0; i < arrSize; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        */

        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;
        std::cout << "\n";
    }

    return 0;
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
        
    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

