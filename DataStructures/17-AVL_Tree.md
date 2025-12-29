### AVL Tree

An **AVL Tree** (named after inventors Adelson-Velsky and Landis) is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes.

**Key Properties:**
- It is a Binary Search Tree
- For every node, the height difference between left and right subtrees is at most 1
- Height-balanced property ensures O(log n) time complexity for all operations
- Automatically maintains balance through rotations

**Balance Factor:** Balance Factor = Height(Left Subtree) - Height(Right Subtree)
- Valid values: -1, 0, or 1
- If balance factor > 1: Left-heavy (needs right rotation)
- If balance factor < -1: Right-heavy (needs left rotation)

### AVL Tree Representation

```
       30 (BF: 0)
      /  \
    20    40 (BF: 0)
   /  \   / \
  10  25 35  50
```

**Example:** All nodes have balance factor in range [-1, 1]

### AVL Tree Rotations

To maintain balance, AVL trees use four types of rotations:

#### 1. Right Rotation (RR)
When left subtree is taller (Left-Left case):

```
Before:        After:
    y              x
   / \            / \
  x   T3    →    T1  y
 / \                 / \
T1  T2             T2  T3
```

#### 2. Left Rotation (LL)
When right subtree is taller (Right-Right case):

```
Before:        After:
  x                y
 / \              / \
T1  y      →     x   T3
   / \          / \
  T2  T3       T1  T2
```

#### 3. Left-Right Rotation (LR)
When left child is right-heavy (Left-Right case):

```
First: Left rotate x, then Right rotate y
```

#### 4. Right-Left Rotation (RL)
When right child is left-heavy (Right-Left case):

```
First: Right rotate y, then Left rotate x
```

### Basic Operations on AVL Tree

#### 1. AVL Tree - Inserting Element

Insert a node and rebalance if necessary:

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree {
private:
    Node* root;
    
    // Get height of node
    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }
    
    // Get balance factor
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    
    // Right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        
        // Perform rotation
        x->right = y;
        y->left = T2;
        
        // Update heights
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        
        return x; // New root
    }
    
    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        
        // Perform rotation
        y->left = x;
        x->right = T2;
        
        // Update heights
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        
        return y; // New root
    }
    
    // Insert utility function
    Node* insertUtil(Node* node, int val) {
        // 1. Perform normal BST insert
        if (node == nullptr) {
            return new Node(val);
        }
        
        if (val < node->data) {
            node->left = insertUtil(node->left, val);
        }
        else if (val > node->data) {
            node->right = insertUtil(node->right, val);
        }
        else {
            return node; // Duplicate values not allowed
        }
        
        // 2. Update height of ancestor node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        
        // 3. Get balance factor
        int balance = getBalance(node);
        
        // 4. If unbalanced, perform rotations
        
        // Left Left Case
        if (balance > 1 && val < node->left->data) {
            return rightRotate(node);
        }
        
        // Right Right Case
        if (balance < -1 && val > node->right->data) {
            return leftRotate(node);
        }
        
        // Left Right Case
        if (balance > 1 && val > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        // Right Left Case
        if (balance < -1 && val < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node; // Return unchanged node
    }
    
public:
    AVLTree() : root(nullptr) {}
    
    void insert(int val) {
        root = insertUtil(root, val);
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
    AVLTree tree;
    
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    
    cout << "Inorder traversal: ";
    tree.inorder();
    
    return 0;
}
```

#### 2. AVL Tree - Deleting Element

Delete a node and rebalance:

```cpp
// Find node with minimum value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Delete utility function
Node* deleteUtil(Node* root, int val) {
    // 1. Perform standard BST delete
    if (root == nullptr) return root;
    
    if (val < root->data) {
        root->left = deleteUtil(root->left, val);
    }
    else if (val > root->data) {
        root->right = deleteUtil(root->right, val);
    }
    else {
        // Node to be deleted found
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;
            
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else {
                *root = *temp;
            }
            delete temp;
        }
        else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteUtil(root->right, temp->data);
        }
    }
    
    if (root == nullptr) return root;
    
    // 2. Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    
    // 3. Get balance factor
    int balance = getBalance(root);
    
    // 4. Rebalance if needed (same rotations as insert)
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}
```

#### 3. AVL Tree - Searching Element

Search is same as BST (O(log n)):

```cpp
bool search(Node* root, int val) {
    if (root == nullptr) return false;
    
    if (val == root->data) return true;
    else if (val < root->data) return search(root->left, val);
    else return search(root->right, val);
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
- **Auxiliary Space:** O(log n) for recursion stack

### Advantages of AVL Tree

1. **Guaranteed O(log n) time complexity** for all operations
2. **Height-balanced** - prevents worst-case O(n) operations
3. **Better than regular BST** for frequently updated data
4. **Predictable performance** - no worst-case scenarios

### Disadvantages of AVL Tree

1. **More complex implementation** - requires rotation logic
2. **Extra memory** - needs to store height for each node
3. **More rotations** - may require multiple rotations per operation
4. **Slower than BST** for read-heavy workloads

### Applications of AVL Tree

1. **Database indexing** - maintaining sorted indexes
2. **In-memory sorting** - when frequent insertions/deletions needed
3. **Priority queues** - when order matters
4. **File systems** - directory structures
5. **Compiler design** - symbol tables
6. **Networking** - routing tables

### Comparison with Other Trees

| Feature | AVL Tree | Red-Black Tree | BST |
|---------|----------|----------------|-----|
| Balance | Strict (height diff ≤ 1) | Relaxed (black height) | No balance |
| Rotations | More frequent | Less frequent | None |
| Insert/Delete | O(log n) | O(log n) | O(n) worst case |
| Search | O(log n) | O(log n) | O(n) worst case |
| Memory | Height per node | Color bit per node | Minimal |

### References

- [GeeksforGeeks - AVL Tree](https://www.geeksforgeeks.org/avl-tree-set-1-insertion/)
- [GeeksforGeeks - AVL Tree Deletion](https://www.geeksforgeeks.org/avl-tree-set-2-deletion/)
