//
// Heap data structure
//

#include <iostream>
#include <stdexcept>

class Heap
{
public:
    enum HeapType {
        Max,
        Min
    };

    int* storage;
    int storageSize;
    int size;
    HeapType type;

public:
    Heap(int storageSize_in, HeapType in_type) : size(0), storageSize(storageSize_in), type(in_type) {
        storage = new int[storageSize];
    }

    ~Heap() {
        delete[] storage;
    }

    void clear() {
        size = 0;
    };

    int parentIndex(int index) {
        if (index == 0)
            return 0;
        return (index-1)/2;
    }

    int leftIndex(int index) {
        return 2*index + 1;
    }

    int rightIndex(int index) {
        return 2*index + 2;
    }


    // Display the validation in brackets
    // Display the storage and the parent in parens afterwards to
    // confirm heap property is valid
    void display() {
        std::cout << "[" << validate() << "] ";
        for (int i=0; i<size; i++)
            std::cout << storage[i] << "(" << storage[parentIndex(i)]<< ") ";
        std::cout << std::endl;
    }


    // Add a value to the heap and reheapify the storage
    int add(int value) {
        if (size == storageSize)
            throw std::out_of_range("Storage full");
        storage[size++] = value;
        heapifyUp(size-1);
        return 0;
    }

    // Return top of heap without modifying the heap
    int front() {
        return storage[0];
    }

     // Return top of heap, reducing size by 1 and the heapify the remainder
    int pop() {
        if (size <= 0)
            return -1;
        int value = storage[0];
        storage[0] = storage[--size];
        heapifyDown(0);
        return value;
    }

    // Bubble an index down to support heap property
    // Used in heapify
    void heapifyDown(int index) {
        int left = leftIndex(index);
        int right = rightIndex(index);

        switch (type) {
        case Max: {
            int largest = index;
            if ((size > left) && (storage[left] > storage[largest]))
                largest = left;
            if ((size > right) && (storage[right] > storage[largest]))
                largest = right;
            if (largest != index) {
                std::swap(storage[index], storage[largest]);
                heapifyDown(largest);
            }
            break;
        }

        case Min: {
            int smallest = index;
            if ((size > left) && (storage[left] < storage[smallest]))
                smallest = left;
            if ((size > right) && (storage[right] < storage[smallest]))
                smallest = right;
            if (smallest != index) {
                std::swap(storage[index], storage[smallest]);
                heapifyDown(smallest);
            }
            break;
        }
        }
    }

    // Bubble an index up to support heap property
    void heapifyUp(int index) {
        if (index == 0)
            return;

        int parent = parentIndex(index);

        switch (type) {
        case Max:
            if (storage[index] > storage[parent]) {
                std::swap(storage[parent], storage[index]);
                heapifyUp(parent);
            }
            break;

        case Min:
            if (storage[index] < storage[parent]) {
                std::swap(storage[parent], storage[index]);
                heapifyUp(parent);
            }
            break;
        }
    }

    // Heapify an invalid heap
    void heapify() {
        for (int i=size/2; i>=0; i--) {
            heapifyDown(i);
        }
    }

    // return invalid index or 0 if valid
    int validate() {
        for (int index=1; index<size; index++) {
            switch (type) {
            case Max:
                if (storage[parentIndex(index)] < storage[index])
                    return index;
                break;

            case Min:
                if (storage[parentIndex(index)] > storage[index])
                    return index;
                break;
            }
        }
        return 0;
    }
};


int main() {
    const int SIZE = 20;
    Heap h(SIZE, Heap::Max);

    srand(time(NULL));
    for (int i=0; i<SIZE; i++)
        h.add(rand() % 100);

    h.display();
    std::cout << std::endl;

    // Randomize storage
    h.clear();
    h.size = SIZE;
    for (int i=0; i<SIZE; i++)
        h.storage[i] = rand() % 100;
    h.display();
    h.heapify();
    h.display();
    std::cout << std::endl;

    for (int i=0; i<5; i++) {
        int value = h.pop();
        std::cout << "Pop: " << value << std::endl;
        h.display();
    }
    for (int i=0; i<5; i++) {
        int value = rand() % 100;
        h.add(value);
        std::cout << "Add: " << value << std::endl;
        h.display();
    }
}




