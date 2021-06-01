//
// Various sorting routines
//

#include <iostream>
#include <vector>
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
        int toCheck = i-1;
        while (true) {
            if (toCheck == -1)
                break;
            if (array[i] < array[toCheck])
                toCheck--;
            else
                break;
        }
        int temp = array[i];
        for (int j=i-1; j>toCheck; j--) {
            array[j+1] = array[j];
        }
        array[toCheck+1] = temp;
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

    std::cout << "MergeSort" << std::endl;
    Array merge = randomArray();
    displayArray(merge);
    mergeSort(merge);
    displayArray(merge);
    std::cout << std::endl;
}
