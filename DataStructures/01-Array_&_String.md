### Array - Concepts

An array is a linear data structure that collects elements of the same data type and stores them in contiguous and adjacent memory locations.   

For simplicity, we can think of an array as a fleet of stairs where on each step is placed a value (let’s say one of your friends). Here, you can identify the location of any of your friends by simply knowing the count of the step they are on.   
*Remember: “Location of next index depends on the data type we use”.*   

![Array Indexing](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/DataStructures/assets/Array_1.png?raw=true)     

The above image can be looked at as a top-level view of a staircase where you are at the base of the staircase. Each element can be uniquely identified by its index in the array (in a similar way as you could identify your friends by the step on which they were on in the above example). 

**Array’s size:** Arrays work on an index system starting from 0 to (n-1), where n is the size of the array. There is types of indexing of the array as given below.    
**Types of indexing in an array:**     
- **0 (zero-based indexing):** The first element of the array is indexed by a subscript of 0.  
- **1 (one-based indexing):** The first element of the array is indexed by the subscript of 1.  
- **n (N-based indexing):** The base index of an array can be freely chosen. Usually, programming languages allowing n-based indexing also allow negative index values, and other scalar data types like enumerations, or characters may be used as an array index.   
#### Types of Arrays

1. **One dimensional array (1-D arrays):** You can imagine a 1d array as a row, where elements are stored one after another.      
![1D_Array](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/DataStructures/assets/Arrays_1D.png?raw=true)    
2. **Multidimensional array:** These multi-dimensional arrays are again of two types. They are:
    - **Two-Dimensional Arrays:** You can imagine it like a table where each cell contains elements.
    ![2D_Array](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/DataStructures/assets/Arrays_2D.png?raw=true)   
    - **Three-Dimensional Arrays:** You can imagine it like a cuboid made up of smaller cuboids where each cuboid can contain an element.
    ![3D_Array](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/DataStructures/assets/Arrays_3D.png?raw=true)    

### Strings - Concepts 



**We now understand what an array is in a datastructure, but there is a significant difference between arrays in C++ and Java, which is discussed below:**    

Applications of Array in C/C++:

    Arrays are used to implement vectors, and lists in C++ STL.
    Arrays are used as the base of all sorting algorithms.
    Arrays are used to implement other DS like a stack, queue, etc.
    Used for implementing matrices. 
    Data structures like trees also sometimes use the array implementation since arrays are easier to handle than pointers. For example, a segment tree uses array implementation.
    Binary search trees and balanced binary trees are used in data structures such as a heap, map, and set, which can be built using arrays.
    Graphs are also implemented as arrays in the form of an adjacency matrix.

Applications of Array in Java:

    Arrays are good for implementing lists.
    Arrays can be used to determine the flow of the code.
    Arrays are better than pointers for tree implementation.

Applications of Array in C#:

    In C#, arrays are objects not just addressable contiguous regions of memory. 
    Arrays are dynamically allocated in C#.

Advantages of array data structure:

    Arrays store multiple data of similar types with the same name.
    It allows random access to elements.
    As the array is of fixed size and stored in contiguous memory locations there is no memory shortage or overflow.
    It is helpful to store any type of data with a fixed size.
    Since the elements in the array are stored at contiguous memory locations it is easy to iterate in this data structure and unit time is required to access an element if the index is known.



**Credit:**  
> **GeeksforGeeks:** [https://www.geeksforgeeks.org/array-data-structure/](https://www.geeksforgeeks.org/array-data-structure/)  