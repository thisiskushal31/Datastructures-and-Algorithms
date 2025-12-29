### Self Balancing Binary Search Trees

A **Self-Balancing Binary Search Tree** is a BST that automatically keeps its height small (O(log n)) after every insertion and deletion. This ensures that operations like search, insert, and delete always take O(log n) time, even in the worst case.

**Why Self-Balancing?**
- Regular BST can become **skewed** (degenerate to linked list) → O(n) worst case
- Self-balancing trees **guarantee O(log n)** operations
- Automatically **maintain balance** through rotations/rebalancing

### Types of Self-Balancing BSTs

#### 1. AVL Tree
- **Balance Factor:** Height difference between left and right subtrees ≤ 1
- **Strictest balance:** Most balanced among all self-balancing trees
- **More rotations:** Requires more frequent rebalancing
- **Best for:** Read-heavy workloads, when search performance is critical
- **See:** [AVL Tree](./17-AVL_Tree.md)

#### 2. Red-Black Tree
- **Color property:** Each node is red or black with specific rules
- **Relaxed balance:** Less strict than AVL, but still O(log n)
- **Fewer rotations:** More efficient for frequent insertions/deletions
- **Best for:** Mixed workloads, standard library implementations
- **See:** [Red-Black Tree](./21-Red_Black_Tree.md)

#### 3. Splay Tree
- **Splay operation:** Recently accessed nodes move to root
- **Amortized O(log n):** Average case O(log n), worst case O(n)
- **Self-adjusting:** No explicit balance factor or color
- **Best for:** Locality of reference, frequently accessed elements
- **See:** [Splay Tree](./18-Splay_Tree.md)

#### 4. B-Tree / B+ Tree
- **Multi-way tree:** More than 2 children per node
- **Disk-based:** Optimized for disk I/O operations
- **Used in:** Databases, file systems
- **See:** [B Tree](./19-B_Tree.md)

### Comparison Table

| Feature | AVL Tree | Red-Black Tree | Splay Tree | B-Tree |
|---------|----------|----------------|------------|--------|
| **Balance** | Strict (height diff ≤ 1) | Relaxed (black height) | Self-adjusting | Multi-way |
| **Height** | Most balanced | Slightly less | Variable | O(log n) |
| **Rotations** | More frequent | Less frequent | Splay operations | Split/Merge |
| **Search** | O(log n) | O(log n) | O(log n) amortized | O(log n) |
| **Insert** | O(log n) | O(log n) | O(log n) amortized | O(log n) |
| **Delete** | O(log n) | O(log n) | O(log n) amortized | O(log n) |
| **Worst Case** | O(log n) | O(log n) | O(n) | O(log n) |
| **Memory** | Height per node | Color bit | Minimal | Variable |
| **Use Case** | Read-heavy | Mixed workloads | Locality of reference | Disk-based |

### When to Use Which?

#### Use AVL Tree when:
- **Search operations are frequent** and critical
- **Read-heavy workload** (more searches than insertions/deletions)
- **Need strict balance** for predictable performance
- **Memory is not a concern**

#### Use Red-Black Tree when:
- **Mixed workload** (balanced reads and writes)
- **Frequent insertions/deletions**
- **Standard library implementation** (C++ STL, Java Collections)
- **Need guaranteed O(log n)** with fewer rotations

#### Use Splay Tree when:
- **Locality of reference** (recently accessed items accessed again)
- **Cache-friendly** operations needed
- **Amortized performance** is acceptable
- **Simple implementation** preferred

#### Use B-Tree when:
- **Disk-based storage** (databases, file systems)
- **Large datasets** that don't fit in memory
- **Range queries** are common
- **Multi-way branching** needed

### Advantages of Self-Balancing BSTs

1. **Guaranteed O(log n) operations** - no worst-case O(n) scenarios
2. **Automatic balancing** - no manual rebalancing needed
3. **Predictable performance** - consistent time complexity
4. **Better than regular BST** - prevents tree degradation

### Disadvantages of Self-Balancing BSTs

1. **More complex implementation** - requires rotation/rebalancing logic
2. **Extra memory overhead** - balance factors, colors, or other metadata
3. **Slower than regular BST** - additional overhead for balancing
4. **More operations** - rotations/rebalancing add overhead

### Implementation Considerations

#### Common Operations:
1. **Rotations:**
   - Left Rotation
   - Right Rotation
   - Left-Right Rotation (Double)
   - Right-Left Rotation (Double)

2. **Rebalancing:**
   - Check balance after insert/delete
   - Perform rotations if needed
   - Update metadata (height, color, etc.)

3. **Maintenance:**
   - Update parent pointers
   - Maintain tree properties
   - Handle edge cases (root, leaves)

### Code Example: Generic Self-Balancing BST Interface

```cpp
template<typename T>
class SelfBalancingBST {
protected:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node* parent;
        
        Node(T val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
    };
    
    Node* root;
    
    // Virtual functions for balancing
    virtual Node* balanceAfterInsert(Node* node) = 0;
    virtual Node* balanceAfterDelete(Node* node) = 0;
    
public:
    SelfBalancingBST() : root(nullptr) {}
    
    virtual void insert(T val) = 0;
    virtual void remove(T val) = 0;
    virtual bool search(T val) = 0;
    
    // Common utility functions
    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }
    
    Node* findMax(Node* node) {
        while (node->right) node = node->right;
        return node;
    }
};
```

### Applications

1. **Database Systems:** Index structures (B-trees, B+ trees)
2. **Standard Libraries:** C++ STL (std::map, std::set), Java Collections (TreeMap, TreeSet)
3. **File Systems:** Directory structures, metadata management
4. **Networking:** Routing tables, priority queues
5. **Compiler Design:** Symbol tables, abstract syntax trees
6. **Operating Systems:** Process schedulers, memory management

### References

- [GeeksforGeeks - Self-Balancing Binary Search Trees](https://www.geeksforgeeks.org/self-balancing-binary-search-trees/)
- [AVL Tree](./17-AVL_Tree.md)
- [Red-Black Tree](./21-Red_Black_Tree.md)
- [Splay Tree](./18-Splay_Tree.md)
- [B Tree](./19-B_Tree.md)
