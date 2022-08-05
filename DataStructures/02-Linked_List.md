### Linked Lists - Concepts

*A linked list is a sequence of data structures, which are connected together via links.*    

Linked List is a sequence of links which contains items. Each link contains a connection to another link. Linked list is the second most-used data structure after array. Following are the important terms to understand the concept of Linked List.    
- **Head :** First node is head contain a link to second link useful to find linked list first node with data.
- **Link :** Each link of a linked list can store a data called an element.
- **Next :** Each link of a linked list contains a link to the next link called Next.
- **LinkedList :** A Linked List contains the connection link to the first link called First.

#### Linked List Representation

Linked list can be visualized as a chain of nodes, where every node points to the next node.   

![Linked List Representation](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/DataStructures/assets/LinkedList_Single.png?raw=true)

*As per the above illustration, following are the important points to be considered.*
- Linked List contains a link element called first.
- Each link carries a data field(s) and a link field called next.
- Each link is linked with its next link using its next link.
- Last link carries a link as null to mark the end of the list.

### Advantage and Disadavantage of using Linked List

**Advantages of Linked Lists:**
- Insertion and deletion in linked lists are very efficient.
- Linked list can be expanded in constant time.
- For implementation of stacks and queues and for representation of trees and graphs.
- Linked lists are used for dynamic memory allocation which means effective memory utilization hence, no memory wastage.

**Disadvantages of Linked Lists:**
- Use of pointers is more in linked lists hence, complex and requires more memory.
- Searching an element is costly and requires O(n) time complexity.
- Traversing is more time consuming and reverse traversing is not possible in singly linked lists.
- Random access is not possible due to dynamic memory allocation.

### Types of Linked List

Following are the various types of linked list.
- **Simple Linked List** - Item navigation is forward only.
- **Doubly Linked List** - Items can be navigated forward and backward.
- **Circular Linked List** − Last item contains link of the first element as next and the first element has a link to the last element as previous.
- **Skip List** - Create multiple layers so that we can skip some nodes faster searching.
- **Doubly Circular Linked List** - Two consecutive elements are linked or connected by previous and next pointer and the last node points to first node by next pointer and also the first node points to last node by the previous pointer.
- **Unrolled Linked List** - Storing multiple elements at each node and it also has the advantage of fast insertion and deletion as that of a linked list.
- **Multilevel Linked List** - 2D data structure that comprises several linked lists and each node in a multilevel linked list has a next and child pointer.

### Simple Linked List

### Doubly Linked List

### Circular Linked List

### Skip List

### Doubly Circular Linked List 

### Unrolled Linked List

### Multilevel Linked List



**More Details on this Topic:**
> [Linked List on Tutorialspoint](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm)    
> [Linked List on JavaTpoint](https://www.javatpoint.com/ds-linked-list)    
> [Linked List on GeeksforGeeks](https://www.geeksforgeeks.org/linked-list-set-1-introduction/)    
> [Linked List Different Articles & Programs](https://www.geeksforgeeks.org/data-structures/linked-list/)    