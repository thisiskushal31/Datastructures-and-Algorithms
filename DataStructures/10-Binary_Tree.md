### Binary Tree -Concept

In a binary tree, every node or every vertex has two child nodes or single child nodes, or no child node. Basically, a binary tree is a very important class in a data structure in which nodes of a binary tree have at most two children nodes. In the binary tree, the left side is called the left child node and the right side of the binary tree is called the right child node.

### Binary Tree Representation

A tree is represented by a pointer to the topmost node of the tree. If the tree is empty, then the value of the root is NULL.
A Tree node contains the following parts:

1. Data
2. Pointer to the left child
3. Pointer to the right child

```java
// Class containing left and right child
// of current node and key value
class Node
{
    int key;
    Node left, right;
 
    public Node(int item)
    {
        key = item;
        left = right = null;
    }
}
```

![Tree_BinaryTree](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/DataStructures/assets/Tree_BinaryTree.png?raw=true)

### Basic Operation On Binary Tree

**These are basic operation on binary tree:**

- Inserting an element.
- Removing an element.
- Searching for an element.
- Traversing an element. There are three types of traversals in a binary tree which will be discussed ahead.

#### Binary Tree Inserting Element

Given a binary tree and a key, insert the key into the binary tree at the first position available in [level order](https://www.geeksforgeeks.org/level-order-tree-traversal/).

![Binary Tree Insertion](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/DataStructures/assets/Binary_Tree_Insertion.png?raw=true)

The idea is to do an iterative level order traversal of the given tree using queue. If we find a node whose left child is empty, we make a new key as the left child of the node. Else if we find a node whose right child is empty, we make the new key as the right child. We keep traversing the tree until we find a node whose either left or right child is empty.

```cpp
// Function to insert element in binary tree
Node* InsertNode(Node* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }

    // Else, do level order traversal until we find an empty place, i.e. either left child or right child of some node is pointing to NULL.
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}
```

- **Time Complexity:** $O(V)$ where $V$ is the number of nodes.  
- **Space Complexity:** $O(B)$, where $B$ is the width of the tree and in the worst case we need to hold all vertices of a level in the queue.  

> [More Details in this Topic](https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/)

#### Binary Tree Removing Element

Given a binary tree, delete a node from it by making sure that the tree shrinks from the bottom (i.e. the deleted node is replaced by the bottom-most and rightmost node). This is different from BST deletion. Here we do not have any order among elements, so we replace them with the last element.

![Binary Tree Deletion](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/DataStructures/assets/Binary_Tree_Deletion.png?raw=true)

**Algorithm:**

1. *Starting at the root, find the deepest and rightmost node in the binary tree and the node which we want to delete.*
2. *Replace the deepest rightmost node’s data with the node to be deleted.*
3. *Then delete the deepest rightmost node.*

```cpp
// function to delete the given deepest node (d_node) in binary tree
void deletDeepest(struct Node* root, struct Node* d_node)
{
    queue<struct Node*> q;
    q.push(root);
 
    // Do level order traversal until last node
    struct Node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

// Function to delete given element
// in binary tree
static void delete(Node root, int key)
{
    if (root == null)
        return;
         
    if (root.left == null &&
       root.right == null)
    {
        if (root.key == key)
        {
              root=null;
              return;
        }
        else
            return;
    }
     
    Queue<Node> q = new LinkedList<Node>();
    q.add(root);
    Node temp = null, keyNode = null;
     
    // Do level order traversal until
    // we find key and last node.
    while (!q.isEmpty())
    {
        temp = q.peek();
        q.remove();
         
        if (temp.key == key)
            keyNode = temp;
 
        if (temp.left != null)
            q.add(temp.left);
 
        if (temp.right != null)
            q.add(temp.right);
    }
 
    if (keyNode != null)
    {
        int x = temp.key;
        deleteDeepest(root, temp);
        keyNode.key = x;
    }
}
```

- **Time complexity:** *O(n) where n is no number of nodes*
- **Auxiliary Space:** *O(n) size of queue*

> [More Details in this Topic](https://www.geeksforgeeks.org/deletion-binary-tree/)

#### Binary Tree Searching Element

For Binary Tree Searching Element idea is to use any of the tree traversals to traverse the tree and while traversing check if the current node matches with the given node. If any node matches with the given node and stop traversing further and if the tree is completely traversed and none of the node matches with the given node then print element not found.

```cpp
// Function to traverse the tree in preorder
// and check if the given node exists in it
static boolean ifNodeExists( Node node, int key)
{
    if (node == null)
        return false;
 
    if (node.data == key)
        return true;
 
    // then recur on left subtree /
    boolean res1 = ifNodeExists(node.left, key);
   
    // node found, no need to look further
    if(res1) return true;
 
    // node is not found in left,
    // so recur on right subtree /
    boolean res2 = ifNodeExists(node.right, key);
 
    return res2;
}
```  

- **Time Complexity:** *O(N), as we are using recursion to traverse N nodes of the tree.*
- **Auxiliary Space:** *O(N), we are not using any explicit extra space but as we are using recursion there will be extra space allocated for recursive stack.*

> [More Details in this Topic](https://www.geeksforgeeks.org/search-a-node-in-binary-tree/)

#### Binary Tree Traversal of Element

Unlike linear data structures (Array, Linked List, Queues, Stacks, etc) which have only one logical way to traverse them, trees can be traversed in different ways. Following are the generally used ways for traversing trees.

There are three types of Depth-First Traversals:
(a) Inorder (Left, Root, Right) : 4 2 5 1 3
(b) Preorder (Root, Left, Right) : 1 2 4 5 3
(c) Postorder (Left, Right, Root) : 4 5 2 3 1

```cpp
       1
     /   \         
    2     3
   /\      
  4  5    
```

##### Inorder Traversal

*Uses of Inorder*
In the case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order. To get nodes of BST in non-increasing order, a variation of Inorder traversal where Inorder traversal s reversed can be used.
*Example: In order traversal for the above-given figure is 4 2 5 1 3.*

*Algorithm: Inorder(tree)*

1. Traverse the left subtree, i.e., call Inorder(left-subtree)
2. Visit the root.
3. Traverse the right subtree, i.e., call Inorder(right-subtree)

> For InOrder Traversal see : [Inorder_Tree_Traversal_without_Recursion](https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/)  & [Inorder_Tree Traversal_without_recursion_and_without_stack!](https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/)

##### Preorder Traversal

*Uses of Preorder*

Preorder traversal is used to create a copy of the tree. Preorder traversal is also used to get prefix expression on an expression tree.
*Example: Preorder traversal for the above-given figure is 1 2 4 5 3.*

*Algorithm Preorder(tree)*

1. Visit the root.
2. Traverse the left subtree, i.e., call Preorder(left-subtree)
3. Traverse the right subtree, i.e., call Preorder(right-subtree)

> For Preorder Traversal see : [Iterative_Preorder_Traversal](https://www.geeksforgeeks.org/iterative-preorder-traversal/) & [Morris_traversal_for_Preorder](https://www.geeksforgeeks.org/morris-traversal-for-preorder/)

##### Postorder Traversal

*Uses of Postorder*

Postorder traversal is used to delete the tree. Please see the question for the deletion of a tree for details. Postorder traversal is also useful to get the postfix expression of an expression tree.
*Example: Postorder traversal for the above-given figure is 4 5 2 3 1.*

*Algorithm Postorder(tree)*

1. Traverse the left subtree, i.e., call Postorder(left-subtree)
2. Traverse the right subtree, i.e., call Postorder(right-subtree)
3. Visit the root.

> For Postorder Traversal see : [Iterative_Postorder_Traversal](https://www.geeksforgeeks.org/iterative-postorder-traversal/)

> [More Details in Traversal](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/)

### Binary Tree Properties

**These are properties of a binary tree:**

- A binary tree is either an empty tree or consists of a node called the root node, a left subtree, and a right subtree. The subtrees will also act as a binary tree once.
- The top-most node is called the root.
- A node without children is called a leaf node or terminal node.
- The maximum number of nodes at each level of i is 2i.
- Height of the tree = the longest path from the root node to the leaf node.
- Depth of a node = the length of the path to its root.

### Types of Binary Tree

**The following are common types of Binary Trees.**

#### Full Binary Tree

A Binary Tree is a full binary tree if every node has 0 or 2 children. A full Binary tree is a special type of binary tree in which every parent node/internal node has either two or no children. It is also known as a proper binary tree or strict binary tree.

**Properties of Full Binary Tree:**  

- The number of leaf nodes is equal to the number of internal nodes plus 1, i.e. Number of Leaf nodes = Number of Internal nodes + 1.
- The maximum number of nodes is the same as the number of nodes in the binary tree, i.e., $(2h+1) -1$.
- The minimum number of nodes in the full binary tree is $2*h-1$.
- The minimum height of the full binary tree is $log{_2}{(n+1) - 1}$.
- The maximum height of the full binary tree can be computed as: $(n= 2*h - 1)$ | $(n+1 = 2*h)$ | $(h = n+1/2)$.

```cpp
This is example of Full Binary Tree:
             18
           /    \  
         15      30  
        /  \     /  \
      40    50 100   40
```

#### Complete Binary Tree

In Complete Binary Tree has all levels completely filled with nodes except the last level and in the last level, all the nodes are as left side as possible. It is also called as 

A complete binary tree is just like a full binary tree, but with two major differences:  
- Every level must be completely filled
- All the leaf elements must lean towards the left.
- The last leaf element might not have a right sibling i.e. a complete binary tree doesn’t have to be a full binary tree.

*Properties of Complete Binary Tree:*
- The maximum number of nodes in complete binary tree is $(2h+1) - 1$.
- The minimum number of nodes in complete binary tree is $2h$.
- The minimum height of a complete binary tree is $log{_2}{(n+1) - 1}$.

```cpp
The following are examples of Complete Binary Trees.  
               18                      18
           /       \                /      \  
         15         30            15        30  
        /  \        /  \         /  \      /  \
      40    50    100   40     40    50  100   40
                              /  \   /
                             8    7  9 
```

*Note:* Binary Heap is an important use case of Complete Binary tree. 
#### Perfect Binary Tree

A Perfect Binary Tree in which all the internal nodes have two children and all leaf nodes are at the same level. A perfect binary tree is a type of binary tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level.    

```cpp
The following are the examples of Perfect Binary Trees.
              18
           /     \  
         15       30  
        /  \     /  \
      40    50 100   40


             18
           /    \  
         15      30  
```

In a Perfect Binary Tree, the number of leaf nodes is the number of internal nodes plus 1.  
*L = I + 1 Where L = Number of leaf nodes, I = Number of internal nodes.*

A Perfect Binary Tree of height h (where the height of the binary tree is the number of edges in the longest path from the root node to any leaf node in the tree, height of root node is 0) has $(2h+1)–1$ node. 
#### Balanced Binary Tree

A binary tree is balanced if the height of the tree is O(Log n) where n is the number of nodes. For Example, the AVL tree maintains O(Log n) height by making sure that the difference between the heights of the left and right subtrees is at most 1. Red-Black trees maintain O(Log n) height by making sure that the number of Black nodes on every root to leaf paths is the same and there are no adjacent red nodes. Balanced Binary Search trees are performance-wise good as they provide O(log n) time for search, insert and delete.   

#### A degenerate (or pathological) tree

#### Skewed Binary Tree

### Handshaking Lemma and Interesting Tree Properties

### Diameter of a Binary Tree

### Enumeration of Binary Trees

### Binary Tree (Array implementation)

### Foldable Binary Trees

**More Details on this Topic:**
> [Binary Tree on Javatpoint](https://www.javatpoint.com/binary-tree)
> [Binary Tree on Programiz](https://www.programiz.com/dsa/binary-tree)
> [Binary Tree on Scaler](https://www.scaler.com/topics/data-structures/binary-tree-in-data-structure/)
> [Binary Tree on GeeksforGeeks](https://www.geeksforgeeks.org/binary-tree-set-1-introduction/)
