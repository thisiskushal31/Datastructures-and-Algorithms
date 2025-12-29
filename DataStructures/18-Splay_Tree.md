### Splay Tree

A **Splay Tree** is a self-adjusting binary search tree with the additional property that recently accessed elements are quick to access again. It performs basic operations such as insertion, look-up and removal in O(log n) amortized time.

**Key Properties:**
- Self-adjusting: Recently accessed nodes move to root
- Amortized O(log n) performance: Average case is O(log n)
- No explicit balance factor: Simpler than AVL or Red-Black trees
- Splay operation: Moves accessed node to root through rotations

**Splay Operation:** When a node is accessed, it is moved to the root through a series of rotations called "splaying".

### Splay Tree Representation

```
Before access(20):        After splay(20):
       50                      20
      /  \                    /  \
    30    70          →       10   50
   /  \   / \                    /  \
  20  40 60  80                30   70
 /                              \   / \
10                              40 60  80
```

**Example:** After accessing 20, it becomes the root through splaying.

### Splay Operations

#### 1. Zig (Single Rotation)
When node is child of root:

```
    y (root)              x
   /          →         / \
  x                     T1  y
 / \                        / \
T1  T2                     T2  T3
```

#### 2. Zig-Zig (Two Same-Side Rotations)
When node and parent are both left or both right children:

```
      z                  x
     / \                / \
    y   T4    →        T1  y
   / \                    / \
  x   T3                 T2  z
 / \                        / \
T1  T2                     T3  T4
```

#### 3. Zig-Zag (Two Opposite Rotations)
When node is left child and parent is right child (or vice versa):

```
    z                x
   / \              / \
  y   T4    →     /   \
 / \             y     z
T1  x           / \   / \
   / \         T1  T2 T3  T4
  T2  T3
```

### Basic Operations on Splay Tree

#### 1. Splay Tree - Splaying

Move a node to root:

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
    
    Node(int val) {
        data = val;
        left = right = parent = nullptr;
    }
};

class SplayTree {
private:
    Node* root;
    
    // Right rotation
    Node* rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
        return y;
    }
    
    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
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
        return y;
    }
    
    // Splay operation
    void splay(Node* x) {
        while (x->parent != nullptr) {
            if (x->parent->parent == nullptr) {
                // Zig case
                if (x == x->parent->left) {
                    rightRotate(x->parent);
                }
                else {
                    leftRotate(x->parent);
                }
            }
            else if (x == x->parent->left && 
                     x->parent == x->parent->parent->left) {
                // Zig-Zig (left-left)
                rightRotate(x->parent->parent);
                rightRotate(x->parent);
            }
            else if (x == x->parent->right && 
                     x->parent == x->parent->parent->right) {
                // Zig-Zig (right-right)
                leftRotate(x->parent->parent);
                leftRotate(x->parent);
            }
            else if (x == x->parent->right && 
                     x->parent == x->parent->parent->left) {
                // Zig-Zag (left-right)
                leftRotate(x->parent);
                rightRotate(x->parent);
            }
            else {
                // Zig-Zag (right-left)
                rightRotate(x->parent);
                leftRotate(x->parent);
            }
        }
    }
    
    // Find node
    Node* findNode(int val) {
        Node* current = root;
        while (current != nullptr) {
            if (val < current->data) {
                if (current->left == nullptr) break;
                current = current->left;
            }
            else if (val > current->data) {
                if (current->right == nullptr) break;
                current = current->right;
            }
            else {
                break;
            }
        }
        return current;
    }
    
public:
    SplayTree() : root(nullptr) {}
    
    // Search and splay
    bool search(int val) {
        Node* node = findNode(val);
        if (node != nullptr) {
            splay(node);
            return node->data == val;
        }
        return false;
    }
    
    // Insert
    void insert(int val) {
        if (root == nullptr) {
            root = new Node(val);
            return;
        }
        
        Node* node = findNode(val);
        
        if (node->data == val) {
            splay(node);
            return; // Already exists
        }
        
        Node* newNode = new Node(val);
        if (val < node->data) {
            node->left = newNode;
        }
        else {
            node->right = newNode;
        }
        newNode->parent = node;
        
        splay(newNode);
    }
    
    // Delete
    void remove(int val) {
        if (root == nullptr) return;
        
        Node* node = findNode(val);
        splay(node);
        
        if (node->data != val) return; // Not found
        
        Node* leftSubtree = node->left;
        Node* rightSubtree = node->right;
        
        if (leftSubtree != nullptr) {
            leftSubtree->parent = nullptr;
        }
        if (rightSubtree != nullptr) {
            rightSubtree->parent = nullptr;
        }
        
        delete node;
        
        if (leftSubtree == nullptr) {
            root = rightSubtree;
        }
        else if (rightSubtree == nullptr) {
            root = leftSubtree;
        }
        else {
            // Find max in left subtree
            Node* maxLeft = leftSubtree;
            while (maxLeft->right != nullptr) {
                maxLeft = maxLeft->right;
            }
            splay(maxLeft);
            maxLeft->right = rightSubtree;
            rightSubtree->parent = maxLeft;
            root = maxLeft;
        }
    }
    
    void inorder() {
        inorderUtil(root);
        cout << endl;
    }
    
private:
    void inorderUtil(Node* node) {
        if (node != nullptr) {
            inorderUtil(node->left);
            cout << node->data << " ";
            inorderUtil(node->right);
        }
    }
};

int main() {
    SplayTree tree;
    
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    
    cout << "Inorder: ";
    tree.inorder();
    
    tree.search(20); // Splay 20 to root
    cout << "After searching 20: ";
    tree.inorder();
    
    return 0;
}
```

### Time Complexity

| Operation | Amortized | Worst Case |
|-----------|-----------|------------|
| Search    | O(log n)  | O(n)       |
| Insert    | O(log n)  | O(n)       |
| Delete    | O(log n)  | O(n)       |
| Space     | O(n)      | O(n)       |

**Note:** Amortized analysis shows that over a sequence of operations, average time is O(log n), but individual operations can be O(n).

### Space Complexity

- **Space Complexity:** O(n) for storing n nodes
- **Auxiliary Space:** O(1) for rotations (no recursion stack needed)

### Advantages of Splay Tree

1. **Simple implementation** - no balance factors or colors
2. **Locality of reference** - frequently accessed items are fast
3. **Self-adjusting** - adapts to access patterns
4. **Cache-friendly** - hot data moves to top
5. **Amortized efficiency** - good average performance

### Disadvantages of Splay Tree

1. **Worst case O(n)** - can degrade to linear time
2. **No guarantee** - individual operations can be slow
3. **Not suitable for real-time** - unpredictable worst-case
4. **Less balanced** - can become skewed

### Applications of Splay Tree

1. **Caching:** Frequently accessed data moves to root
2. **Network routing:** Hot routes accessed faster
3. **Garbage collection:** Mark frequently used objects
4. **Data compression:** Move-to-front coding
5. **File systems:** Recently accessed files

### When to Use Splay Tree?

- **Locality of reference** - same items accessed repeatedly
- **Cache optimization** - hot data should be fast
- **Simple implementation** - easier than AVL/Red-Black
- **Amortized performance** acceptable - worst case O(n) is okay

### References

- [GeeksforGeeks - Splay Tree](https://www.geeksforgeeks.org/splay-tree-set-1-insert/)
- [GeeksforGeeks - Splay Tree Deletion](https://www.geeksforgeeks.org/splay-tree-set-2-insert-delete/)
