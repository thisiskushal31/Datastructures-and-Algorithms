### Segment Tree

A **Segment Tree** is a tree data structure used for storing information about intervals (segments). It allows efficient range queries and range updates in O(log n) time.

**Key Properties:**
- **Range Queries:** Query sum/min/max/gcd over any range in O(log n)
- **Range Updates:** Update a range of elements in O(log n)
- **Point Updates:** Update a single element in O(log n)
- **Flexible:** Supports various operations (sum, min, max, gcd, etc.)

### Segment Tree Representation

Segment Tree is a binary tree where:
- Each leaf node represents a single element
- Each internal node represents a range (segment)
- Root represents the entire array
- Left child represents left half, right child represents right half

**Example:** Array `[1, 3, 5, 7, 9, 11]` represented as Segment Tree for sum

```
                    [0-5: 36]
                   /          \
            [0-2: 9]          [3-5: 27]
           /        \          /        \
      [0-1: 4]   [2: 5]   [3-4: 16]  [5: 11]
      /      \            /       \
  [0: 1]  [1: 3]    [3: 7]   [4: 9]
```

![Segment Tree Structure](./assets/Segment_Tree_Structure.png)

*Image Credit: [GeeksforGeeks - Segment Tree Data Structure](https://www.geeksforgeeks.org/segment-tree-data-structure/)*

### Basic Segment Tree Implementation (Range Sum)

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    void buildTree(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            // Leaf node
            tree[node] = arr[start];
        }
        else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            
            // Build left and right subtrees
            buildTree(arr, leftChild, start, mid);
            buildTree(arr, rightChild, mid + 1, end);
            
            // Merge results
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }
    
    void updateUtil(int node, int start, int end, int index, int delta) {
        if (start == end) {
            // Leaf node
            tree[node] += delta;
        }
        else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            
            if (index <= mid) {
                updateUtil(leftChild, start, mid, index, delta);
            }
            else {
                updateUtil(rightChild, mid + 1, end, index, delta);
            }
            
            // Update parent
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }
    
    int queryUtil(int node, int start, int end, int l, int r) {
        // No overlap
        if (r < start || l > end) {
            return 0;
        }
        
        // Complete overlap
        if (l <= start && end <= r) {
            return tree[node];
        }
        
        // Partial overlap
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        
        int leftSum = queryUtil(leftChild, start, mid, l, r);
        int rightSum = queryUtil(rightChild, mid + 1, end, l, r);
        
        return leftSum + rightSum;
    }
    
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        // Size of segment tree is 4 * n (safe upper bound)
        int treeSize = 4 * n;
        tree.resize(treeSize, 0);
        buildTree(arr, 0, 0, n - 1);
    }
    
    // Update: Add delta to element at index
    void update(int index, int delta) {
        updateUtil(0, 0, n - 1, index, delta);
    }
    
    // Query: Get sum from index l to r
    int rangeSum(int l, int r) {
        return queryUtil(0, 0, n - 1, l, r);
    }
    
    // Get value at index
    int getValue(int index) {
        return rangeSum(index, index);
    }
};
```

- **Time Complexity:** 
  - Build: O(n)
  - Update: O(log n)
  - Query: O(log n)
- **Space Complexity:** O(4n) ≈ O(n)

### Range Update with Lazy Propagation

For range updates, we use **Lazy Propagation** to update ranges efficiently:

```cpp
class SegmentTreeLazy {
private:
    vector<int> tree;
    vector<int> lazy;
    int n;
    
    void buildTree(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        }
        else {
            int mid = (start + end) / 2;
            buildTree(arr, 2*node + 1, start, mid);
            buildTree(arr, 2*node + 2, mid + 1, end);
            tree[node] = tree[2*node + 1] + tree[2*node + 2];
        }
    }
    
    void updateLazy(int node, int start, int end) {
        if (lazy[node] != 0) {
            // Update current node
            tree[node] += lazy[node] * (end - start + 1);
            
            // If not leaf, mark children for lazy update
            if (start != end) {
                lazy[2*node + 1] += lazy[node];
                lazy[2*node + 2] += lazy[node];
            }
            
            lazy[node] = 0; // Reset lazy value
        }
    }
    
    void rangeUpdateUtil(int node, int start, int end, int l, int r, int delta) {
        updateLazy(node, start, end);
        
        // No overlap
        if (start > r || end < l) {
            return;
        }
        
        // Complete overlap
        if (l <= start && end <= r) {
            tree[node] += delta * (end - start + 1);
            if (start != end) {
                lazy[2*node + 1] += delta;
                lazy[2*node + 2] += delta;
            }
            return;
        }
        
        // Partial overlap
        int mid = (start + end) / 2;
        rangeUpdateUtil(2*node + 1, start, mid, l, r, delta);
        rangeUpdateUtil(2*node + 2, mid + 1, end, l, r, delta);
        
        updateLazy(2*node + 1, start, mid);
        updateLazy(2*node + 2, mid + 1, end);
        
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }
    
    int queryUtil(int node, int start, int end, int l, int r) {
        updateLazy(node, start, end);
        
        // No overlap
        if (start > r || end < l) {
            return 0;
        }
        
        // Complete overlap
        if (l <= start && end <= r) {
            return tree[node];
        }
        
        // Partial overlap
        int mid = (start + end) / 2;
        int leftSum = queryUtil(2*node + 1, start, mid, l, r);
        int rightSum = queryUtil(2*node + 2, mid + 1, end, l, r);
        
        return leftSum + rightSum;
    }
    
public:
    SegmentTreeLazy(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        buildTree(arr, 0, 0, n - 1);
    }
    
    // Range Update: Add delta to all elements from l to r
    void rangeUpdate(int l, int r, int delta) {
        rangeUpdateUtil(0, 0, n - 1, l, r, delta);
    }
    
    // Query: Get sum from l to r
    int rangeSum(int l, int r) {
        return queryUtil(0, 0, n - 1, l, r);
    }
};
```

- **Time Complexity:** O(log n) for both range update and query
- **Space Complexity:** O(4n) for tree + O(4n) for lazy = O(n)

### Segment Tree for Minimum/Maximum

```cpp
class SegmentTreeMin {
private:
    vector<int> tree;
    int n;
    const int INF = 1e9;
    
    void buildTree(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        }
        else {
            int mid = (start + end) / 2;
            buildTree(arr, 2*node + 1, start, mid);
            buildTree(arr, 2*node + 2, mid + 1, end);
            tree[node] = min(tree[2*node + 1], tree[2*node + 2]);
        }
    }
    
    void updateUtil(int node, int start, int end, int index, int newVal) {
        if (start == end) {
            tree[node] = newVal;
        }
        else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                updateUtil(2*node + 1, start, mid, index, newVal);
            }
            else {
                updateUtil(2*node + 2, mid + 1, end, index, newVal);
            }
            tree[node] = min(tree[2*node + 1], tree[2*node + 2]);
        }
    }
    
    int queryUtil(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return INF;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        
        int mid = (start + end) / 2;
        int leftMin = queryUtil(2*node + 1, start, mid, l, r);
        int rightMin = queryUtil(2*node + 2, mid + 1, end, l, r);
        
        return min(leftMin, rightMin);
    }
    
public:
    SegmentTreeMin(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, INF);
        buildTree(arr, 0, 0, n - 1);
    }
    
    void update(int index, int newVal) {
        updateUtil(0, 0, n - 1, index, newVal);
    }
    
    int rangeMin(int l, int r) {
        return queryUtil(0, 0, n - 1, l, r);
    }
};
```

### Applications of Segment Tree

1. **Range Sum Queries:** Sum of elements in range
2. **Range Min/Max Queries:** Minimum/maximum in range
3. **Range GCD Queries:** GCD of elements in range
4. **Range Updates:** Update all elements in a range
5. **Inversion Count:** Count inversions in array
6. **Longest Increasing Subsequence:** With range queries
7. **Competitive Programming:** Many range query problems

### Example: Range Sum with Point Update

```cpp
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);
    
    cout << "Sum [0-2]: " << st.rangeSum(0, 2) << endl; // 9
    cout << "Sum [2-5]: " << st.rangeSum(2, 5) << endl; // 32
    
    st.update(2, 10); // Add 10 to element at index 2
    cout << "After update, Sum [0-2]: " << st.rangeSum(0, 2) << endl; // 19
    
    return 0;
}
```

### Advantages of Segment Tree

1. **Flexible:** Supports various operations (sum, min, max, gcd)
2. **Range Updates:** Can update ranges efficiently with lazy propagation
3. **Fast Queries:** O(log n) for range queries
4. **Versatile:** Can be customized for different operations

### Disadvantages of Segment Tree

1. **Memory:** Uses O(4n) space (more than BIT)
2. **Complexity:** More complex to implement than BIT
3. **Overhead:** More code for lazy propagation

### Comparison: Segment Tree vs Binary Indexed Tree

| Feature | Segment Tree | Binary Indexed Tree |
|---------|--------------|---------------------|
| Space | O(4n) | O(n) |
| Update | O(log n) | O(log n) |
| Query | O(log n) | O(log n) |
| Range Update | Yes (with lazy) | No |
| Operations | Sum, Min, Max, GCD | Sum only |
| Complexity | Higher | Lower |

### Time Complexity Summary

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Build | O(n) | O(4n) |
| Point Update | O(log n) | O(1) |
| Range Update | O(log n) with lazy | O(1) |
| Range Query | O(log n) | O(1) |

**More Details on this Topic:**
> [Segment Tree on GeeksforGeeks](https://www.geeksforgeeks.org/segment-tree-data-structure/)
> [Segment Tree on CP Algorithms](https://cp-algorithms.com/data_structures/segment_tree.html)
> [Segment Tree Tutorial on HackerEarth](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/)
> [Lazy Propagation on GeeksforGeeks](https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/)