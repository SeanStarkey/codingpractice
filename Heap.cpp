#include <iostream>

// Heap data structure
class Heap
{
public:
    int storage[1024];
    int size;

public:
    Heap() {
        size = 0;
    }

    // Display the storage and the parent in parens afterwards to
    // confirm heap property is valid
    void display() {
        for (int i=0; i<size; i++)
            std::cout << storage[i] << "(" << storage[(i-1)/2]<< ") ";
        std::cout << std::endl;
    }

    void maxHeapify(int i) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;
        std::cout << "MH: i: " << i << " l: " << l << " r: " << r << std::endl;
        display();

        if ((l < size) && (storage[l] > storage[largest]))
            largest = l;

        if ((r < size) && (storage[r] > storage[largest]))
            largest = r;

        if (largest != i) {
            int swap = storage[i];
            storage[i] = storage[largest];
            storage[largest] = swap;
            maxHeapify(largest);
        }
    }
};


int main() {
    Heap h;

    // put some random integers into the heap
    const int size = 30;
    srand(time(NULL));
    for (int i=0; i<size; i++)
        h.storage[i] = rand() % 100;
    h.size = size;

    h.display();
    std::cout << std::endl;

    for (int i=size/2; i>=0; i--) {
        h.maxHeapify(i);
        h.display();
        std::cout << std::endl;
    }

    std::cout << std::endl;
    h.display();
}




