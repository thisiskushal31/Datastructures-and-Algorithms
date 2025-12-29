### Others

This section covers additional data structures that are important but don't fit into the main categories. These include specialized structures for specific use cases.

### 1. Disjoint Set (Union-Find)

A **Disjoint Set** data structure keeps track of a set of elements partitioned into disjoint (non-overlapping) subsets. It supports two main operations: **Find** (which subset an element belongs to) and **Union** (merge two subsets).

**Key Properties:**
- Each element belongs to exactly one set
- Supports union and find operations efficiently
- Used in Kruskal's algorithm, network connectivity, image processing

**Operations:**
- `makeSet(x)`: Create a new set containing x
- `find(x)`: Find the representative of the set containing x
- `union(x, y)`: Merge sets containing x and y

```cpp
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each element is its own parent
        }
    }
    
    // Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    // Union by rank
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return; // Already in same set
        
        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
```

**Time Complexity:** O(α(n)) per operation (almost constant, α is inverse Ackermann function)

### 2. Bloom Filter

A **Bloom Filter** is a probabilistic data structure that tests whether an element is a member of a set. It may return false positives but never false negatives.

**Key Properties:**
- Space-efficient probabilistic data structure
- Fast membership testing
- No false negatives (if says "not in set", it's definitely not)
- May have false positives (if says "in set", might not be)

```cpp
#include <iostream>
#include <vector>
#include <bitset>
#include <functional>
using namespace std;

class BloomFilter {
private:
    vector<bool> bitArray;
    int size;
    int numHashFunctions;
    
    // Hash functions
    int hash1(string key) {
        hash<string> hasher;
        return hasher(key) % size;
    }
    
    int hash2(string key) {
        hash<string> hasher;
        return (hasher(key) * 31) % size;
    }
    
public:
    BloomFilter(int size, int numHashFunctions) 
        : size(size), numHashFunctions(numHashFunctions) {
        bitArray.resize(size, false);
    }
    
    void insert(string key) {
        bitArray[hash1(key)] = true;
        bitArray[hash2(key)] = true;
    }
    
    bool contains(string key) {
        return bitArray[hash1(key)] && bitArray[hash2(key)];
    }
};
```

**Time Complexity:** O(k) where k is number of hash functions (typically constant)

### 3. Fenwick Tree (Binary Indexed Tree)

A **Fenwick Tree** or **Binary Indexed Tree (BIT)** is a data structure that supports point updates and range sum queries efficiently.

**See:** [Binary Indexed Tree](./14-Binary_Indexed_Tree.md)

### 4. Skip List

A **Skip List** is a probabilistic data structure that allows O(log n) search, insertion, and deletion operations.

**Key Properties:**
- Probabilistic alternative to balanced trees
- Multiple levels of linked lists
- Simpler than balanced trees
- Used in Redis, LevelDB

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class SkipListNode {
public:
    int data;
    vector<SkipListNode*> next;
    
    SkipListNode(int val, int level) : data(val) {
        next.resize(level + 1, nullptr);
    }
};

class SkipList {
private:
    SkipListNode* head;
    int maxLevel;
    float probability;
    
    int randomLevel() {
        int level = 0;
        while ((rand() % 100) < (probability * 100) && level < maxLevel) {
            level++;
        }
        return level;
    }
    
public:
    SkipList(int maxLevel, float probability) 
        : maxLevel(maxLevel), probability(probability) {
        head = new SkipListNode(INT_MIN, maxLevel);
        srand(time(0));
    }
    
    void insert(int val) {
        vector<SkipListNode*> update(maxLevel + 1);
        SkipListNode* current = head;
        
        for (int i = maxLevel; i >= 0; i--) {
            while (current->next[i] != nullptr && 
                   current->next[i]->data < val) {
                current = current->next[i];
            }
            update[i] = current;
        }
        
        current = current->next[0];
        
        if (current == nullptr || current->data != val) {
            int newLevel = randomLevel();
            SkipListNode* newNode = new SkipListNode(val, newLevel);
            
            for (int i = 0; i <= newLevel; i++) {
                newNode->next[i] = update[i]->next[i];
                update[i]->next[i] = newNode;
            }
        }
    }
    
    bool search(int val) {
        SkipListNode* current = head;
        
        for (int i = maxLevel; i >= 0; i--) {
            while (current->next[i] != nullptr && 
                   current->next[i]->data < val) {
                current = current->next[i];
            }
        }
        
        current = current->next[0];
        return (current != nullptr && current->data == val);
    }
};
```

**Time Complexity:** O(log n) average case, O(n) worst case

### 5. Deque (Double-Ended Queue)

A **Deque** allows insertion and deletion from both ends efficiently.

**Key Properties:**
- Insert/delete from both front and back
- O(1) operations for both ends
- Used in sliding window problems, palindrome checking

```cpp
#include <iostream>
#include <deque>
using namespace std;

// Using STL deque
void dequeExample() {
    deque<int> dq;
    
    dq.push_front(10);  // Add to front
    dq.push_back(20);   // Add to back
    dq.push_front(5);   // Add to front
    
    cout << "Front: " << dq.front() << endl;  // 5
    cout << "Back: " << dq.back() << endl;     // 20
    
    dq.pop_front();     // Remove from front
    dq.pop_back();      // Remove from back
}
```

**Time Complexity:** O(1) for all operations

### 6. Circular Buffer (Ring Buffer)

A **Circular Buffer** is a fixed-size buffer that overwrites oldest data when full.

**Key Properties:**
- Fixed size
- Overwrites oldest data
- Used in audio processing, network buffers, producer-consumer problems

```cpp
class CircularBuffer {
private:
    vector<int> buffer;
    int size;
    int head;
    int tail;
    int count;
    
public:
    CircularBuffer(int size) : size(size), head(0), tail(0), count(0) {
        buffer.resize(size);
    }
    
    void enqueue(int val) {
        buffer[tail] = val;
        tail = (tail + 1) % size;
        if (count < size) {
            count++;
        }
        else {
            head = (head + 1) % size; // Overwrite oldest
        }
    }
    
    int dequeue() {
        if (count == 0) return -1;
        int val = buffer[head];
        head = (head + 1) % size;
        count--;
        return val;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};
```

**Time Complexity:** O(1) for all operations

### 7. Interval Tree

An **Interval Tree** stores intervals and allows efficient querying of overlapping intervals.

**Key Properties:**
- Stores intervals [low, high]
- Efficient overlap queries
- Used in scheduling, computational geometry

### 8. Rope Data Structure

A **Rope** is a binary tree data structure for efficiently storing and manipulating very long strings.

**Key Properties:**
- Efficient concatenation and splitting
- Used in text editors for large documents
- Better than string for large text operations

### Summary Table

| Data Structure | Primary Use | Time Complexity |
|----------------|-------------|----------------|
| Disjoint Set | Union-Find operations | O(α(n)) |
| Bloom Filter | Probabilistic membership | O(k) |
| Skip List | Probabilistic sorted list | O(log n) avg |
| Deque | Double-ended queue | O(1) |
| Circular Buffer | Fixed-size buffer | O(1) |
| Interval Tree | Interval queries | O(log n) |
| Rope | Large string operations | O(log n) |

### References

- [GeeksforGeeks - Disjoint Set](https://www.geeksforgeeks.org/disjoint-set-data-structures/)
- [GeeksforGeeks - Bloom Filter](https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/)
- [GeeksforGeeks - Skip List](https://www.geeksforgeeks.org/skip-list/)
- [GeeksforGeeks - Deque](https://www.geeksforgeeks.org/deque-set-1-introduction-applications/)
