### B Tree

A **B-Tree** is a self-balancing search tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time. Unlike binary search trees, B-trees can have more than two children per node.

**Key Properties:**
- All leaves are at the same level
- Every node (except root) has at least ⌈m/2⌉ - 1 keys and at most m - 1 keys
- Root has at least 1 key (if not a leaf)
- Internal nodes have at least ⌈m/2⌉ children
- A node with k keys has k+1 children
- Keys in a node are stored in sorted order

**Order (m):** Maximum number of children a node can have.

### B-Tree Representation

**B-Tree of order 3 (minimum degree t = 2):**

```
        [50]
       /    \
   [10,30]  [70,90]
   /  |  \   /  |  \
  [5] [20] [40] [60] [80,100]
```

**Example:** Each node can have up to 2 keys (order 3), and internal nodes have at least 1 key.

### Why B-Tree?

- **Disk-based storage:** Optimized for systems that read/write large blocks of data
- **Reduced height:** Lower tree height means fewer disk accesses
- **Wide branching:** More children per node reduces tree height
- **Used in databases:** Standard structure for database indexes

### Basic Operations on B-Tree

#### 1. B-Tree - Searching Element

Search for a key in B-Tree:

```cpp
#include <iostream>
#include <vector>
using namespace std;

class BTreeNode {
public:
    vector<int> keys;
    vector<BTreeNode*> children;
    bool leaf;
    int t; // Minimum degree
    
    BTreeNode(int _t, bool _leaf) : t(_t), leaf(_leaf) {
        keys.reserve(2*t - 1);
        children.reserve(2*t);
    }
    
    // Search for key in subtree rooted with this node
    BTreeNode* search(int k) {
        int i = 0;
        while (i < keys.size() && k > keys[i]) {
            i++;
        }
        
        if (i < keys.size() && keys[i] == k) {
            return this;
        }
        
        if (leaf) {
            return nullptr;
        }
        
        return children[i]->search(k);
    }
    
    friend class BTree;
};

class BTree {
private:
    BTreeNode* root;
    int t; // Minimum degree
    
    void splitChild(BTreeNode* x, int i) {
        BTreeNode* y = x->children[i];
        BTreeNode* z = new BTreeNode(y->t, y->leaf);
        
        // Move last (t-1) keys of y to z
        for (int j = 0; j < t - 1; j++) {
            z->keys.push_back(y->keys[j + t]);
        }
        
        // Move last t children of y to z
        if (!y->leaf) {
            for (int j = 0; j < t; j++) {
                z->children.push_back(y->children[j + t]);
            }
        }
        
        // Reduce number of keys in y
        y->keys.resize(t - 1);
        if (!y->leaf) {
            y->children.resize(t);
        }
        
        // Create space for new child
        x->children.insert(x->children.begin() + i + 1, z);
        
        // Move middle key of y to x
        x->keys.insert(x->keys.begin() + i, y->keys[t - 1]);
    }
    
    void insertNonFull(BTreeNode* x, int k) {
        int i = x->keys.size() - 1;
        
        if (x->leaf) {
            // Insert key in sorted order
            x->keys.push_back(0);
            while (i >= 0 && x->keys[i] > k) {
                x->keys[i + 1] = x->keys[i];
                i--;
            }
            x->keys[i + 1] = k;
        }
        else {
            // Find child to insert
            while (i >= 0 && x->keys[i] > k) {
                i--;
            }
            i++;
            
            // If child is full, split it
            if (x->children[i]->keys.size() == 2*t - 1) {
                splitChild(x, i);
                if (x->keys[i] < k) {
                    i++;
                }
            }
            insertNonFull(x->children[i], k);
        }
    }
    
public:
    BTree(int _t) : t(_t), root(nullptr) {}
    
    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }
    
    void insert(int k) {
        if (root == nullptr) {
            root = new BTreeNode(t, true);
            root->keys.push_back(k);
        }
        else {
            // If root is full, split it
            if (root->keys.size() == 2*t - 1) {
                BTreeNode* s = new BTreeNode(t, false);
                s->children.push_back(root);
                splitChild(s, 0);
                
                int i = 0;
                if (s->keys[0] < k) {
                    i++;
                }
                insertNonFull(s->children[i], k);
                root = s;
            }
            else {
                insertNonFull(root, k);
            }
        }
    }
    
    void traverse() {
        if (root != nullptr) {
            traverseUtil(root);
            cout << endl;
        }
    }
    
private:
    void traverseUtil(BTreeNode* node) {
        int i;
        for (i = 0; i < node->keys.size(); i++) {
            if (!node->leaf) {
                traverseUtil(node->children[i]);
            }
            cout << node->keys[i] << " ";
        }
        if (!node->leaf) {
            traverseUtil(node->children[i]);
        }
    }
};

int main() {
    BTree tree(3); // B-Tree of order 3
    
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);
    
    cout << "Traversal: ";
    tree.traverse();
    
    int key = 6;
    if (tree.search(key) != nullptr) {
        cout << key << " found" << endl;
    }
    else {
        cout << key << " not found" << endl;
    }
    
    return 0;
}
```

#### 2. B-Tree - Inserting Element

Insert operation involves:
1. **Search** for the correct leaf node
2. **Insert** key in sorted order
3. **Split** node if it becomes full (2t-1 keys)
4. **Propagate** split upward if needed

#### 3. B-Tree - Deleting Element

Delete operation is more complex:
1. **Search** for the key
2. **Case 1:** Key in leaf node → Remove directly
3. **Case 2:** Key in internal node → Replace with predecessor/successor
4. **Case 3:** Key in node with minimum keys → Merge with sibling
5. **Propagate** merge upward if needed

### B+ Tree

**B+ Tree** is a variant of B-Tree where:
- All keys are stored in **leaf nodes**
- Internal nodes only store **keys for navigation**
- Leaf nodes are **linked** for sequential access
- **Better for range queries** and database indexing

### Time Complexity

| Operation | Time Complexity |
|-----------|----------------|
| Search    | O(log n)       |
| Insert    | O(log n)       |
| Delete    | O(log n)       |
| Space     | O(n)           |

**Note:** In practice, B-Tree operations are much faster than O(log n) because:
- Tree height is very small (typically 3-4 levels for millions of keys)
- Each node fits in a disk block
- Fewer disk I/O operations

### Space Complexity

- **Space Complexity:** O(n) for storing n keys
- **Node size:** Typically matches disk block size (4KB, 8KB, etc.)

### Advantages of B-Tree

1. **Optimized for disk I/O** - reduces number of disk accesses
2. **Wide branching** - lower tree height
3. **Self-balancing** - maintains balance automatically
4. **Efficient range queries** - especially B+ Tree
5. **Used in databases** - standard for indexing

### Disadvantages of B-Tree

1. **Complex implementation** - especially deletion
2. **Memory overhead** - nodes store multiple keys and pointers
3. **Not optimal for in-memory** - designed for disk-based systems
4. **Fixed node size** - may waste space

### Applications of B-Tree

1. **Database Systems:** Index structures (MySQL, PostgreSQL, Oracle)
2. **File Systems:** NTFS, HFS+, ext4 (directory structures)
3. **Database Management:** B+ Trees for table indexes
4. **Large-scale storage:** Distributed file systems
5. **Search Engines:** Inverted indexes

### B-Tree vs Binary Search Tree

| Feature | B-Tree | BST |
|---------|--------|-----|
| **Children per node** | Multiple (m) | 2 |
| **Height** | Lower | Higher |
| **Disk I/O** | Optimized | Not optimized |
| **Use case** | Disk-based | Memory-based |
| **Range queries** | Efficient (B+ Tree) | Less efficient |

### References

- [GeeksforGeeks - B Tree](https://www.geeksforgeeks.org/introduction-of-b-tree-2/)
- [GeeksforGeeks - B Tree Insertion](https://www.geeksforgeeks.org/b-tree-set-1-introduction-2/)
- [GeeksforGeeks - B+ Tree](https://www.geeksforgeeks.org/introduction-of-b-tree/)
