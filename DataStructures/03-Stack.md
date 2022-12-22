### Stacks

A Stack is a linear data structure that follows the LIFO (Last-In-First-Out) principle. Stack has one end, whereas the Queue has two ends (front and rear). It contains only *one pointer top pointer pointing to the topmost element of the stack*. Whenever an element is added in the stack, it is added on the top of the stack, and the element can be deleted only from the stack. In other words, a stack can be defined as a container in which insertion and deletion can be done from the one end known as the top of the stack.    s

**Some key points related to stack**    
- It is called as stack because it behaves like a real-world stack, piles of books, etc.
- A Stack is an abstract data type with a pre-defined capacity, which means that it can store the elements of a limited size.
- It is a data structure that follows some order to insert and delete the elements, and that order can be LIFO or FILO.

**You can Implement Stack using Array and Linked_List:** For [Linked_List](https://www.javatpoint.com/ds-linked-list-implementation-of-stack) and [Array](https://www.javatpoint.com/ds-array-implementation-of-stack) view respective blog.  
### Working of Stack

Stack works on the LIFO pattern. In programming terms, putting an item on top of the stack is called push and removing an item is called pop.  

![Stack_Working](./assets/Stack_Working.jpg)

In the above image, although item 3 was kept last, it was removed first. This is exactly how the LIFO (Last In First Out) Principle works.    
### Standard Stack Operations

**The following are some common operations implemented on the stack:**   

- **push(element(s)):** add an element (or several elements) to the top of the stack.
- **pop():** remove the top element of the stack and return the removed element.
- **peek():** return the top element of the stack without modifying the stack itself.
- **isEmpty():** return true if the stack does not contain any elements, false if the stack’s size is greater than 0.
- **clear():** remove all elements from the stack.
- **size():** return the number of elements in the stack (similar to the length property of an array).

**Operations**  

**push(x):** Insert element x at the top of a stack   
```cpp
void push (int stack[ ] , int x , int n) {
 if ( top == n-1 ) {         //If the top position is the last of position in a stack, this means that the stack is full
    cout << “Stack is full.Overflow condition!” ;
    }
    else{
        top = top +1 ;            //Incrementing top position 
        stack[ top ] = x ;       //Inserting element on incremented position  
    }
}
```  

**pop( ):** Removes an element from the top of a stack   
```cpp
   void pop (int stack[ ] ,int n ) 
    {
        if( isEmpty ( ) )
        {
            cout << “Stack is empty. Underflow condition! ” << endl ;
        }
        else    
        {
             top = top - 1 ; //Decrementing top’s position will detach last element from stack            
        }
    }
```   

**topElement( ):** Access the top element of a stack   
```cpp
  int topElement ( )
    {
        return stack[ top ];
    }
```
**isEmpty ( ) :** Check whether a stack is empty    
```cpp
    bool isEmpty ( )
    {
        if ( top == -1 )  //Stack is empty
        return true ; 
        else
        return false;
    }
```
**size ( ):** Determines the current size of a stack   
```cpp
   int size ( )
    {
        return top + 1;
    }
```

### Applications of Stack

**The following are application on the stack:**   
- **Recursion:** The recursion means that the function is calling itself again. To maintain the previous states, the compiler creates a system stack in which all the previous records of the function are maintained.
- **DFS(Depth First Search):** This search is implemented on a Graph, and Graph uses the stack data structure.
- **Backtracking:** Suppose we have to create a path to solve a maze problem. If we are moving in a particular path, and we realize that we come on the wrong way. In order to come at the beginning of the path to create a new path, we have to use the stack data structure.
- **Expression conversion:** Stack can also be used for expression conversion. This is one of the most important applications of stack. The list of the expression conversion is given below:
```cpp
    Infix to prefix
    Infix to postfix
    Prefix to infix
    Prefix to postfix
    Postfix to infix
```  
### Expression Parsing & Operators Precedence

The way to write arithmetic expression is known as a notation. An arithmetic expression can be written in three different but equivalent notations, i.e., without changing the essence or output of an expression. These notations are −
- Infix Notation
- Prefix (Polish) Notation
- Postfix (Reverse-Polish) Notation

These notations are named as how they use operator in expression and Operator precedence specifies the manner in which operands are grouped with operators. For *Precedence in [java](https://introcs.cs.princeton.edu/java/11precedence/) and [cpp](https://www.tutorialspoint.com/cprogramming/c_operators_precedence.htm) see this blog. For *Expression Parsing* see [This Blog](https://www.tutorialspoint.com/data_structures_algorithms/expression_parsing.htm)  

**BONUS TIP: Power(In Level 1), Divide/Multiple(In Level 2), Plus/Minus(In Level 3) First check the precedence then if same precedence is found then check associativity**

**Advantages of Stack:**    

- The linked list implementation of a stack can grow and shrink according to the needs at runtime.
- It is used in many virtual machines like JVM.
- Stacks are more secure and reliable as they do not get corrupted easily.
- Stack cleans up the objects automatically.

**Disadvantages of Stack:**   

- Requires extra memory due to involvement of pointers.
- Random accessing is not possible in stack.
- The total of size of the stack must be defined before.
- If the stack falls outside the memory it can lead to abnormal termination.

**More Details on this Topic:**  
> [Stack on GeeksforGeeks](https://www.geeksforgeeks.org/stack-data-structure/)
> [Stack on JavaTpoint](https://www.javatpoint.com/data-structure-stack)
> [Stack on Tutorialspoint](https://www.tutorialspoint.com/data_structures_algorithms/stack_algorithm.htm)
> [Stack on Hackerearth](https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/tutorial/)
> [Stack on Simplilearn](https://www.simplilearn.com/tutorials/data-structure-tutorial/stacks-in-data-structures)