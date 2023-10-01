#include <iostream>
#include <ctime>

using namespace std;

class SortingAlgorithms {
public:
    void selectionSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    // Bubble Sort
    void bubbleSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Merge Sort
    void merge(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int leftArr[n1], rightArr[n2];
        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int i = 0; i < n2; i++) {
            rightArr[i] = arr[mid + 1 + i];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
};

int main() {
    SortingAlgorithms sorter;
    const int dataSize = 10000; // Adjust the size of the dataset as needed

    int arr1[dataSize], arr2[dataSize], arr3[dataSize];

    // Initialize arrays with random values
    srand(time(0));
    for (int i = 0; i < dataSize; i++) {
        arr1[i] = arr2[i] = arr3[i] = rand() % 1000; // Adjust the range as needed
    }

   clock_t start, end;

   start = clock();//0
    sorter.mergeSort(arr3, 0, dataSize - 1);
    end = clock();//12
    double mergeSortTime = double(end - start) / CLOCKS_PER_SEC;


    start = clock();
    sorter.selectionSort(arr1, dataSize);
    end = clock();
    double selectionSortTime = double(end - start) / CLOCKS_PER_SEC;


    start = clock();
    sorter.bubbleSort(arr2, dataSize);
    end = clock();
    double bubbleSortTime = double(end - start) / CLOCKS_PER_SEC;
    
   
   
    cout << "Selection Sort Time: " << selectionSortTime << " seconds" << endl;
        cout << "Merge Sort Time: " << mergeSortTime << " seconds" << endl;
     cout << "Bubble Sort Time: " << bubbleSortTime << " seconds" << endl;
  

    return 0;
}
