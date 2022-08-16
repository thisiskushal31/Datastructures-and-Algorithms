### Tree -Concept

Other data structures such as arrays, linked list, stack, and queue are linear data structures that store data sequentially. In order to perform any operation in a linear data structure, the time complexity increases with the increase in the data size. But, it is not acceptable in today's computational world.   

Different tree data structures allow quicker and easier access to the data as it is a non-linear data structure.   

- A tree data structure is defined as a collection of objects or entities known as nodes that are linked together to represent a hierarchy.
- It's a non linear data structure as it does not store data in a sequential manner, but stores in a hierarchical fashion.
- In the Tree data structure, the first node is known as a root node i.e. from which the tree originates. Each node contains some data and also contains references to child nodes. A root node can never have a parent node.

### Tree Terminologies

![Tree_Terminologies](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/DataStructures/assets/Tree_Terminology.png?raw=true)   

Tree is a hierarchical data structure that is defined as a collection of nodes. In a tree nodes represent the values and are connected by edges. Following are the terminologies and properties of a tree:   

| Terminology | Description | Diagram |
| --- | --- | --- |
| **Root** | Root node is a node from which the entire tree originates. It does not have a parent | *Node A* |
| **Parent Node** | An immediate predecessor of any node is its parent node. | *B is parent of E & F* |
| **Child Node** | All immediate successors of a node are its children. The relationship between the parent and child is considered as the parent-child relationship. | *F & E are children of B* |
| **Leaf** | Node which does not have any child is a leaf. Usually the boundary nodes of a tree or last nodes of the tree are the leaf or collectively called leaves of the tree. | *E, F, J, K, H, I are the leaf nodes.* |
| **Edge** | Edge is the connection represented by a line between one node to another. In a tree with n nodes, there will be ‘n-1’ edges in a tree. | *Connecting line between A&B OR A&C OR B&F OR any other nodes connecting each other.* |
| **Siblings** | Siblings in real life means people with the same parents, similarly in the case of trees, nodes with common parents are considered to be siblings. | *H&I are siblings* |
| **Path** | Path is a number of successive edges from source node to destination node. | *A ,C, G, K is path from node A to K* |
| **Height of Node** | Height of a node represents the number of edges on the longest path between that node and a leaf. | *A, C, G, K form a height. Height of A is no. of edges between A and K,, which is 3. Similarly the height of G is 1 as it has just one edge until the next leaf node* |
| **Levels of node** | Level of a node represents the generation of a node. If the root node is at level 0, then its next child node is at level 1, its grandchild is at level 2, and so on | *Level of H, I & J is 3. Level of D, E, F & G is 2* |
| **Degree of Node** | Degree of a node implies the number of child nodes a node has. | *Degree of D is 2 and of C is 3* |
| **Visiting** | When you’ve iterated or traversed to a specific node programmatically, accessing value or checking value of the current node is called visiting. | *Not Applicable* |
| **Internal Node** | A node that has at least one child is known as an internal node. | *All the nodes except E, F, J, K, H, I are internal.* |
| **Traversing** | Traversing is a process of visiting each node in a specific order in a tree data structure. | *There are three types of traversals: inorder, preorder, postorder traversal.* |
| **Ancestor node** | An ancestor or ancestors to a node are all the predecessor nodes from root until that node. I.e. any parent or grandparent and so on of a specific node are its ancestors. | *A, C & G are ancestor to K and J nodes* |
| **Descendant** | Immediate successor of a node is its descendent. | *K is descendent of G* |
| **Sub tree** | Descendants of a node represent subtree. Tree being a recursive data structure can contain many subtrees inside of it. | *Nodes B, E, F represent one subtree.* |

### Properties of Trees in Data Structure

**Recursive Data Structure:** a recursive method is the one that calls itself. Similarly a recursive data structure is the one that contains itself. A tree can be viewed as a recursive data structure, as even though a tree has only one root node, each node acts as a root node to another sub-tree. For example:    

Following is a tree that has ‘A’ as the root node. Similarly if we look at ‘C’ node, that is another tree in itself. And the tree no 3 i.e. that starts with ‘D’ node is also a tree in itself.    

![Tree_Properties.png](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/DataStructures/assets/Tree_Properties.png?raw=true)    

And that is how a tree contains multiple trees in itself, and this proves that it's a recursive data structure as a recursive data structure contains itself.    
***Note:*** *Even the leaf nodes are a tree in itself i.e. they can be seen from a perspective as trees without any child nodes.*    
- **Number of edges:** If there are $‘n’$ nodes in a tree then there would be $‘n-1’$ edges. Each edge is the line-arrow connecting two nodes.
- **Depth of node x:** Depth of a specific node $x$ is defined as the length from root till this $x$ node. One edge contributes to one unit in the length. Hence depth of a node $x$ can also be considered as the number of nodes from root node till this $x$ node. Or depth of a node $x$ can also be considered as the level $L$ at which this node is, and adding $1$ to it i.e. $depth = L + 1$. It is because the first level starts with $0$.
- **Height of node x:** Height of a node represents the number of edges on the longest path between that node and a leaf.
### Basic Operation Of Tree

### Types of Tree data structures

### Implementation of Tree in Data Structure

### Applications of Tree data structure

**More Details on this Topic:**
> [Tree on JavaTpoint](https://www.javatpoint.com/tree)   
> [Tree on Programiz](https://www.programiz.com/dsa/trees)   
> [Tree on Scaler](https://www.scaler.com/topics/data-structures/tree-data-structure/)   
> [Tree on Tutorialspoint](https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm)   
> [Tree on GeeksforGeeks](https://www.geeksforgeeks.org/introduction-to-tree-data-structure/)   