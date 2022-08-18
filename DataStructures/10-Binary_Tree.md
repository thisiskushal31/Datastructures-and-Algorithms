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

#### Binary Tree Removing Element
#### Binary Tree Searching Element
#### Binary Tree Traversal of Element

### Binary Tree Properties

**These are properties of a binary tree:**

- A binary tree is either an empty tree or consists of a node called the root node, a left subtree, and a right subtree. The subtrees will also act as a binary tree once.
- The top-most node is called the root.
- A node without children is called a leaf node or terminal node.
- The maximum number of nodes at each level of i is 2i.
- Height of the tree = the longest path from the root node to the leaf node.
- Depth of a node = the length of the path to its root.

### Types of Binary Tree

#### Full Binary Tree

#### Complete Binary Tree

#### Perfect Binary Tree

#### Balanced Binary Tree

#### A degenerate (or pathological) tree

#### Skewed Binary Tree

### Handshaking Lemma and Interesting Tree Properties

### Diameter of a Binary Tree

### Enumeration of Binary Trees

### Insertion in a Binary Tree in level order

### Deletion in a Binary Tree

### Binary Tree (Array implementation)

### Foldable Binary Trees

**More Details on this Topic:**
> [Binary Tree on Javatpoint](https://www.javatpoint.com/binary-tree)    
> [Binary Tree on Programiz](https://www.programiz.com/dsa/binary-tree)    
> [Binary Tree on Scaler](https://www.scaler.com/topics/data-structures/binary-tree-in-data-structure/)   
> [Binary Tree on GeeksforGeeks](https://www.geeksforgeeks.org/binary-tree-set-1-introduction/)    
