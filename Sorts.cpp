#include <bits/stdc++.h>
using namespace std;
#include <cassert>
#include <stack>
#define FULLCACHE 3588096
#define FULLL1 49152
#define FULLL2 196608


void merge(int array[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
 
int partition(int arr[], int low, int high)
{
    // Choosing the pivot
    int pivot = arr[high];
 
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
 
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
 
            // Increment index of smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void is_sorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        assert(arr[i] <= arr[i + 1]);
}

// for this project, we test the runtimes with n large enough to see the difference
// in runtimes for random, reversed, and sorted arrays

// Driver code

// function that creates an array sorted in descending order
int* reverseArray(int n){
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = n - i;
    }
    return arr;
}

// function that creates an array sorted in ascending order
int* sortedArray(int n){
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = i;
    }
    return arr;
}

// function that creates an array with random values
int* randomArray(int n){
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = rand() % n;
    }
    return arr;
}

int* manyDuplicatesArray(int n){
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 10;
    }
    return arr;
}
void isSorted(int* arr, int n){
    for(int i = 0; i < n - 1; i++){
        assert(arr[i] <= arr[i + 1]);
    }
}


void testMerge(int* arr, int n, string type){
    clock_t start, end;
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    isSorted(arr, n);
    cout << "MergeSort took " <<  time_taken << setprecision(8);
    cout << " seconds to sort " << type << " array of size " << n << endl;
}

void bubbleSort(int* arr, int n){
    clock_t start, end;
    start = clock();

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    isSorted(arr, n);
    cout << "Warmup Bubble Sort took " << fixed << time_taken << setprecision(5);
    cout << " seconds to sort " << "reversed" << " array of size " << n << endl;
}

int main(){
   

    // test insertion sort  on 4 different arrays
    // warm up the processor with bubblesort on a reversed array
    int* arr = reverseArray(5000);
    bubbleSort(arr, 1000);
    delete[] arr;
    int n;
    cout << endl;


    // test merge sort on 4 different arrays
    // of a smaller size, to see the difference in runtimes
    n = FULLL1;
    cout << "array takes up " << n * sizeof(int) << " bytes, uses L1 cache" << endl;
    cout << "equivalent to " << n * sizeof(int) / 1024 << " kilobytes" << endl;
    arr = randomArray(n);
    testMerge(arr, n, "Random");
    delete[] arr;
    arr = reverseArray(n);
    testMerge(arr, n, "Reversed");
    delete[] arr;
    arr = sortedArray(n);
    testMerge(arr, n, "Sorted");
    delete[] arr;
    arr = manyDuplicatesArray(n);
    testMerge(arr, n, "ManyDuplicates");
    delete[] arr;
    cout << endl;

    // test merge sort on 4 different arrays
    // L2 cache is 192 KB
    n = FULLL2;
    cout << "array takes up " << n * sizeof(int) << " bytes, uses L2 cache" << endl;
    cout << "equivalent to " << n * sizeof(int) / 1024 << " kilobytes" << endl;
    arr = randomArray(n);
    testMerge(arr, n, "Random");
    delete[] arr;
    arr = reverseArray(n);
    testMerge(arr, n, "Reversed");
    delete[] arr;
    arr = sortedArray(n);
    testMerge(arr, n, "Sorted");
    delete[] arr;
    arr = manyDuplicatesArray(n);
    testMerge(arr, n, "ManyDuplicates");
    delete[] arr;
    cout << endl;


    // test merge sort on 4 different arrays 
    // that are all larger than the cache

    n = FULLCACHE;
    cout << "array takes up " << n * sizeof(int) << " bytes, uses entire cache" << endl;
    cout << "equivalent to " << n * sizeof(int) / 1024 << " kilobytes" << endl;
    cout << endl;
    arr = randomArray(n);
    testMerge(arr, n, "Random");
    delete[] arr;
    arr = reverseArray(n);
    testMerge(arr, n, "Reversed");
    delete[] arr;
    arr = sortedArray(n);
    testMerge(arr, n, "Sorted");
    delete[] arr;
    arr = manyDuplicatesArray(n);
    testMerge(arr, n, "ManyDuplicates");
    delete[] arr;
    cout << endl;


    n = 100000000;
    cout << "array takes up " << n * sizeof(int) << " bytes, uses more than the combined cache." << endl;
    cout << "equivalent to " << n * sizeof(int) / 1024 << " kilobytes" << endl;
    cout << endl;
    arr = randomArray(n);
    testMerge(arr, n, "Random");
    delete[] arr;
    arr = reverseArray(n);
    testMerge(arr, n, "Reversed");
    delete[] arr;
    arr = sortedArray(n);
    testMerge(arr, n, "Sorted");
    delete[] arr;
    arr = manyDuplicatesArray(n);
    testMerge(arr, n, "ManyDuplicates");
    delete[] arr;

    return 0;
}