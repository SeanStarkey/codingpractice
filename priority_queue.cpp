//
// Test C++'s priority_queue (Heap) data structure.
//
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
    cout << "Max Heap" << endl;
    priority_queue<int> maxHeap;
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(5);
    cout << maxHeap.top() << endl;
    maxHeap.pop();
    cout << maxHeap.top() << endl;
    maxHeap.pop();
    cout << maxHeap.top() << endl;
    maxHeap.pop();
    cout << endl;

    cout << "Min Heap" << endl;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(5);
    cout << minHeap.top() << endl;
    minHeap.pop();
    cout << minHeap.top() << endl;
    minHeap.pop();
    cout << minHeap.top() << endl;
    minHeap.pop();
    cout << endl;

    return 0;
}
