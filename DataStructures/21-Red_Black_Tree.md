### Red-Black Tree

A **Red-Black Tree** is a self-balancing Binary Search Tree (BST) where each node has an extra bit for denoting the color of the node, either red or black. It ensures that the tree remains approximately balanced during insertions and deletions.

**Key Properties (Red-Black Tree Rules):**
1. Every node is either **red** or **black**
2. The **root is always black**
3. **No two consecutive red nodes** (red node cannot have red parent or red child)
4. Every path from a node (including root) to any of its descendant NULL nodes has the **same number of black nodes** (black height)
5. All **leaf nodes (NULL) are black**

**Black Height:** Number of black nodes from a node to any leaf in its subtree (excluding the node itself).

### Red-Black Tree Representation

```
       13 (Black)
      /  \
    8(B)  17(R)
   /  \   /  \
  1(R) 11(B) 15(B) 25(R)
              /  \
           22(B)  27(B)
```

**Example:** All paths from root to NULL have same black height (2 in this case).

### Why Red-Black Trees?

- **Balanced:** Ensures O(log n) height
- **Less strict than AVL:** Fewer rotations needed
- **Widely used:** Used in C++ STL (std::map, std::set), Java TreeMap, TreeSet
- **Good for frequent updates:** Better than AVL for insert/delete heavy workloads

### Basic Operations on Red-Black Tree

#### 1. Red-Black Tree - Inserting Element

Insert a node and fix violations:

```cpp
#include <iostream>
using namespace std;

enum Color { RED, BLACK };

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Color color;
    
    Node(int val) {
        data = val;
        left = right = parent = nullptr;
        color = RED; // New nodes are always red
    }
};

class RedBlackTree {
private:
    Node* root;
    Node* nil; // Sentinel node (black)
    
    // Left rotation
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        
        if (y->left != nil) {
            y->left->parent = x;
        }
        
        y->parent = x->parent;
        
        if (x->parent == nil) {
            root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        
        y->left = x;
        x->parent = y;
    }
    
    // Right rotation
    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        
        if (x->right != nil) {
            x->right->parent = y;
        }
        
        x->parent = y->parent;
        
        if (y->parent == nil) {
            root = x;
        }
        else if (y == y->parent->left) {
            y->parent->left = x;
        }
        else {
            y->parent->right = x;
        }
        
        x->right = y;
        y->parent = x;
    }
    
    // Fix violations after insertion
    void insertFix(Node* z) {
        while (z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right; // Uncle
                
                // Case 1: Uncle is red
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    // Case 2: z is right child
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    // Case 3: z is left child
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else {
                // Symmetric case (parent is right child)
                Node* y = z->parent->parent->left;
                
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK; // Root is always black
    }
    
    // Insert utility
    void insertUtil(Node* z) {
        Node* y = nil;
        Node* x = root;
        
        // Find position to insert
        while (x != nil) {
            y = x;
            if (z->data < x->data) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }
        
        z->parent = y;
        
        if (y == nil) {
            root = z;
        }
        else if (z->data < y->data) {
            y->left = z;
        }
        else {
            y->right = z;
        }
        
        z->left = nil;
        z->right = nil;
        z->color = RED;
        
        insertFix(z);
    }
    
public:
    RedBlackTree() {
        nil = new Node(0);
        nil->color = BLACK;
        root = nil;
    }
    
    void insert(int val) {
        Node* z = new Node(val);
        insertUtil(z);
    }
    
    void inorder() {
        inorderUtil(root);
        cout << endl;
    }
    
private:
    void inorderUtil(Node* node) {
        if (node != nil) {
            inorderUtil(node->left);
            cout << node->data << "(" << (node->color == RED ? "R" : "B") << ") ";
            inorderUtil(node->right);
        }
    }
};

int main() {
    RedBlackTree tree;
    
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    
    cout << "Inorder traversal: ";
    tree.inorder();
    
    return 0;
}
```

#### 2. Red-Black Tree - Deleting Element

Delete a node and fix violations:

```cpp
// Find minimum node
Node* minimum(Node* node) {
    while (node->left != nil) {
        node = node->left;
    }
    return node;
}

// Transplant: Replace subtree rooted at u with subtree rooted at v
void transplant(Node* u, Node* v) {
    if (u->parent == nil) {
        root = v;
    }
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

// Delete fix
void deleteFix(Node* x) {
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            Node* w = x->parent->right; // Sibling
            
            // Case 1: Sibling is red
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            
            // Case 2: Both children of sibling are black
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
                // Case 3: Sibling's right child is black
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                
                // Case 4: Sibling's right child is red
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        }
        else {
            // Symmetric case
            Node* w = x->parent->left;
            
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

// Delete node
void deleteNode(int val) {
    Node* z = root;
    
    // Find node to delete
    while (z != nil) {
        if (z->data == val) break;
        else if (val < z->data) z = z->left;
        else z = z->right;
    }
    
    if (z == nil) return; // Node not found
    
    Node* y = z;
    Color yOriginalColor = y->color;
    Node* x;
    
    if (z->left == nil) {
        x = z->right;
        transplant(z, z->right);
    }
    else if (z->right == nil) {
        x = z->left;
        transplant(z, z->left);
    }
    else {
        y = minimum(z->right);
        yOriginalColor = y->color;
        x = y->right;
        
        if (y->parent == z) {
            x->parent = y;
        }
        else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    
    if (yOriginalColor == BLACK) {
        deleteFix(x);
    }
}
```

#### 3. Red-Black Tree - Searching Element

Search is same as BST (O(log n)):

```cpp
bool search(Node* root, int val) {
    Node* current = root;
    while (current != nil) {
        if (val == current->data) return true;
        else if (val < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}
```

### Time Complexity

| Operation | Time Complexity |
|-----------|----------------|
| Search    | O(log n)       |
| Insert    | O(log n)       |
| Delete    | O(log n)       |
| Space     | O(n)           |

### Space Complexity

- **Space Complexity:** O(n) for storing n nodes
- **Auxiliary Space:** O(1) for rotations (iterative) or O(log n) for recursion

### Advantages of Red-Black Tree

1. **Guaranteed O(log n) operations** - always balanced
2. **Fewer rotations** - less strict than AVL, fewer rebalancing operations
3. **Widely used** - standard in many libraries (C++ STL, Java Collections)
4. **Good for mixed workloads** - efficient for both reads and writes
5. **Memory efficient** - only one color bit per node

### Disadvantages of Red-Black Tree

1. **Complex implementation** - requires careful handling of cases
2. **Less balanced than AVL** - can have slightly taller trees
3. **More complex than BST** - additional overhead for balancing
4. **Harder to understand** - more cases to handle than AVL

### Applications of Red-Black Tree

1. **C++ STL:** std::map, std::set, std::multimap, std::multiset
2. **Java Collections:** TreeMap, TreeSet
3. **Linux Kernel:** Completely Fair Scheduler (CFS)
4. **Database systems:** Index structures
5. **Event schedulers:** Priority queues
6. **Network routing:** Routing tables

### Comparison: AVL vs Red-Black Tree

| Feature | AVL Tree | Red-Black Tree |
|---------|----------|----------------|
| **Balance** | Strict (height diff ≤ 1) | Relaxed (black height) |
| **Height** | More balanced | Slightly less balanced |
| **Rotations** | More frequent | Less frequent |
| **Insert/Delete** | More rotations | Fewer rotations |
| **Search** | Faster (more balanced) | Slightly slower |
| **Use Case** | Read-heavy workloads | Mixed workloads |
| **Memory** | Height per node | Color bit per node |

### When to Use Red-Black Tree?

- **Frequent insertions/deletions** with occasional searches
- **Mixed workloads** (both reads and writes)
- **Standard library implementations** (C++ STL, Java Collections)
- **When you need guaranteed O(log n)** but fewer rotations than AVL

### References

- [GeeksforGeeks - Red-Black Tree](https://www.geeksforgeeks.org/introduction-to-red-black-tree/)
- [GeeksforGeeks - Red-Black Tree Insertion](https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/)
- [GeeksforGeeks - Red-Black Tree Deletion](https://www.geeksforgeeks.org/red-black-tree-set-2-insert/)
