### Heap

A **Heap** is a special tree-based data structure that satisfies the **heap property**. It is a complete binary tree where:
- **Max Heap:** Parent nodes are always greater than or equal to their child nodes. The root node is the largest element.
- **Min Heap:** Parent nodes are always smaller than or equal to their child nodes. The root node is the smallest element.

**Key Properties:**
- **Complete Binary Tree:** All levels are completely filled except possibly the last level, which is filled from left to right
- **Heap Property:** Parent-child relationship maintains heap order (max or min)
- **Height:** O(log n) where n is the number of elements

### Types of Heap

#### 1. Max Heap
In a Max Heap, the value of each node is greater than or equal to the values of its children.

```
        50
       /  \
     30    20
    /  \   / \
   10  15 5   8
```

![Max and Min Heap Structure](./assets/Heap_Max.png)

*Image Credit: [GeeksforGeeks - Heap Data Structure](https://www.geeksforgeeks.org/heap-data-structure/)*

#### 2. Min Heap
In a Min Heap, the value of each node is smaller than or equal to the values of its children.

```
        5
       /  \
     10    15
    /  \   / \
   20  25 30  40
```

*The image above shows both Max Heap (left) and Min Heap (right) structures.*

### Heap Representation

Heaps are typically represented using arrays. For a node at index `i`:
- **Parent:** `(i - 1) / 2`
- **Left Child:** `2 * i + 1`
- **Right Child:** `2 * i + 2`

**Example:** Max Heap `[50, 30, 20, 10, 15, 5, 8]`
```
Index:  0   1   2   3   4   5   6
Value: 50  30  20  10  15   5   8
```

### Basic Operations on Heap

#### 1. Insert (Heapify Up)

Insert a new element and maintain heap property by moving it up:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        
        // Keep swapping with parent until heap property is satisfied
        while (index > 0 && heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }
    
public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    
    void display() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};
```

- **Time Complexity:** O(log n)
- **Space Complexity:** O(1)

#### 2. Delete/Extract Max (Heapify Down)

Remove the root element (max in max heap) and maintain heap property:

```cpp
class MaxHeap {
private:
    vector<int> heap;
    
    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int n = heap.size();
        
        // Find largest among node and its children
        if (left < n && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < n && heap[right] > heap[largest]) {
            largest = right;
        }
        
        // If largest is not root, swap and continue heapifying
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
    
public:
    int extractMax() {
        if (heap.empty()) {
            return -1; // or throw exception
        }
        
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
        
        return max;
    }
    
    int getMax() {
        return heap.empty() ? -1 : heap[0];
    }
};
```

- **Time Complexity:** O(log n)
- **Space Complexity:** O(1)

#### 3. Build Heap from Array

Convert an unsorted array into a heap:

```cpp
class MaxHeap {
private:
    vector<int> heap;
    
    void heapifyDown(int index, int n) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if (left < n && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < n && heap[right] > heap[largest]) {
            largest = right;
        }
        
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest, n);
        }
    }
    
public:
    // Build heap from array - O(n) time
    void buildHeap(vector<int>& arr) {
        heap = arr;
        int n = heap.size();
        
        // Start from last non-leaf node and heapify down
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapifyDown(i, n);
        }
    }
};
```

- **Time Complexity:** O(n) - Surprisingly, building heap from array is O(n), not O(n log n)
- **Space Complexity:** O(1)

### Heap Sort

Heap Sort uses heap to sort an array:

```cpp
void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    // Build max heap
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapifyDown(arr, i, n);
    }
    
    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move root to end
        heapifyDown(arr, 0, i); // Heapify reduced heap
    }
}

void heapifyDown(vector<int>& arr, int index, int n) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapifyDown(arr, largest, n);
    }
}
```

- **Time Complexity:** O(n log n)
- **Space Complexity:** O(1)

### Priority Queue using Heap

Priority Queue is typically implemented using heap. C++ STL provides `priority_queue`:

```cpp
#include <queue>
#include <iostream>
using namespace std;

int main() {
    // Max Heap (default)
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(5);
    
    cout << "Max element: " << maxHeap.top() << endl; // 30
    maxHeap.pop();
    cout << "Max element after pop: " << maxHeap.top() << endl; // 20
    
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(5);
    
    cout << "Min element: " << minHeap.top() << endl; // 5
    
    return 0;
}
```

### Applications of Heap

1. **Priority Queue:** Implement priority queues efficiently
2. **Heap Sort:** Sorting algorithm with O(n log n) time complexity
3. **Kth Largest/Smallest Element:** Find kth largest element in O(n log k)
4. **Merge K Sorted Arrays:** Efficiently merge multiple sorted arrays
5. **Dijkstra's Algorithm:** Find shortest paths in graphs
6. **Median Maintenance:** Maintain running median efficiently
7. **Scheduling:** CPU scheduling, task scheduling

### Example: Find Kth Largest Element

```cpp
int findKthLargest(vector<int>& nums, int k) {
    // Min heap of size k
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop(); // Remove smallest
        }
    }
    
    return minHeap.top();
}
```

- **Time Complexity:** O(n log k)
- **Space Complexity:** O(k)

### Example: Merge K Sorted Arrays

```cpp
vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> minHeap;
    
    // Push first element of each array
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], {i, 0}});
        }
    }
    
    vector<int> result;
    
    while (!minHeap.empty()) {
        auto [value, pos] = minHeap.top();
        auto [arrayIndex, elementIndex] = pos;
        minHeap.pop();
        
        result.push_back(value);
        
        // Push next element from same array
        if (elementIndex + 1 < arrays[arrayIndex].size()) {
            minHeap.push({arrays[arrayIndex][elementIndex + 1], 
                         {arrayIndex, elementIndex + 1}});
        }
    }
    
    return result;
}
```

- **Time Complexity:** O(n log k) where n is total elements, k is number of arrays
- **Space Complexity:** O(k)

### Time Complexity Summary

| Operation | Time Complexity |
|-----------|----------------|
| Insert | O(log n) |
| Delete Max/Min | O(log n) |
| Get Max/Min | O(1) |
| Build Heap | O(n) |
| Heap Sort | O(n log n) |
| Find Kth Largest | O(n log k) |

### Space Complexity

- **Array Representation:** O(n) where n is number of elements
- **Operations:** O(1) extra space (except recursive heapify which is O(log n) stack space)

**More Details on this Topic:**       
> [Heap on Programiz](https://www.programiz.com/dsa/heap-data-structure)      
> [Heap on Tutorialspoint](https://www.tutorialspoint.com/data_structures_algorithms/heap_data_structure.htm)      
> [Heap on JavaTpoint](https://www.javatpoint.com/heap-data-structure)       
> [Heap on HackerEarth](https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/)
> [Heap on GeeksforGeeks](https://www.geeksforgeeks.org/heap-data-structure/)           