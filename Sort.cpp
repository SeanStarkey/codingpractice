//
// Various sorting routines
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

const int SIZE=40;
const int MAX=1000;

typedef std::vector<int> Array;

void displayArray(Array array) {
    for (int i=0; i<SIZE; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}



void insertionSort(Array& array) {
    for (int i=1; i<SIZE; i++) {
        int valueToInsert = array[i];
        int toCheck = i-1;
        while (true) {
            if (toCheck == -1)
                break;
            if (valueToInsert < array[toCheck])
                toCheck--;
            else
                break;
        }
        for (int shift=i-1; shift>toCheck; shift--) {
            array[shift+1] = array[shift];
        }
        array[toCheck+1] = valueToInsert;
    }
}



void maxHeapify(Array& array, int i, int size) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;

    if ((l < size) && (array[l] > array[largest]))
        largest = l;

    if ((r < size) && (array[r] > array[largest]))
        largest = r;

    if (largest != i) {
        std::swap(array[i], array[largest]);
        maxHeapify(array, largest, size);
    }
}

void heapSort(Array& array) {
    for (int size=SIZE; size>1; size--) {
        for (int i=size/2; i>=0; i--)
            maxHeapify(array, i, size);
        std::swap(array[0], array[size-1]);
    }
}



void mergeArrays(Array& array, Array& temp, int leftStart, int rightEnd) {
    int size = rightEnd - leftStart;
    int leftEnd = leftStart + size/2;
    int rightStart = leftStart + size/2 + 1;
    int leftPtr = leftStart;
    int rightPtr = rightStart;
    int tempPtr = leftPtr;

    while ((leftPtr <= leftEnd) && (rightPtr <= rightEnd)) {
        if (array[leftPtr] < array[rightPtr])
            temp[tempPtr++] = array[leftPtr++];
        else
            temp[tempPtr++] = array[rightPtr++];
    }
    while (leftPtr <= leftEnd)
        temp[tempPtr++] = array[leftPtr++];
    while (rightPtr <= rightEnd)
        temp[tempPtr++] = array[rightPtr++];
    for (int i=leftStart; i<=rightEnd; i++)
        array[i] = temp[i];
}

void mergeSort(Array& array, Array& temp, int leftStart, int rightEnd) {
    if (leftStart >= rightEnd)
        return;

    int size = rightEnd - leftStart;
    int leftEnd = leftStart + size/2;
    int rightStart = leftStart + size/2 + 1;

    mergeSort(array, temp, leftStart, leftEnd);
    mergeSort(array, temp, rightStart, rightEnd);
    mergeArrays(array, temp, leftStart, rightEnd);
}

Array mergeSort(Array& array) {
    Array temp(SIZE);
    mergeSort(array, temp, 0, SIZE-1);
    return array;
}



int partitionHigh(Array& array, int low, int high) {
    int pivot = array[high];
    int i = low;
    for (int j=low; j<high; j++) {
        if (array[j] < pivot) {
            std::swap(array[i], array[j]);
            i++;
        }
    }
    std::swap(array[i], array[high]);
    return i;
}

int partitionLow(Array& array, int low, int high) {
    int pivot = array[low];
    int i = low+1;
    for (int j=low+1; j<=high; j++) {
        if (array[j] < pivot) {
            std::swap(array[i], array[j]);
            i++;
        }
    }
    std::swap(array[i-1], array[low]);
    return i-1;
}

void quickSort(Array& array, int low, int high) {
    if (low < high) {
        int pivot = partitionLow(array, low, high);
        quickSort(array, low, pivot-1);
        quickSort(array, pivot+1, high);
    }
}

void quickSort(Array& array) {
    quickSort(array, 0, SIZE-1);
}


Array randomArray() {
    Array ret(SIZE);

    srand(time(NULL));
    for (int i=0; i<SIZE; i++) {
        ret[i] = rand()%MAX;
    }
    return ret;
}

int main() {
    std::cout << "InsertionSort" << std::endl;
    Array insertion = randomArray();
    displayArray(insertion);
    insertionSort(insertion);
    displayArray(insertion);
    std::cout << std::endl;

    std::cout << "HeapSort" << std::endl;
    Array heap = randomArray();
    displayArray(heap);
    heapSort(heap);
    displayArray(heap);
    std::cout << std::endl;

    std::cout << "MergeSort" << std::endl;
    Array merge = randomArray();
    displayArray(merge);
    mergeSort(merge);
    displayArray(merge);
    std::cout << std::endl;

    std::cout << "QuickSort" << std::endl;
    Array quick = randomArray();
    displayArray(quick);
    quickSort(quick);
    displayArray(quick);
    std::cout << std::endl;
}
