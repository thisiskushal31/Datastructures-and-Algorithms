### Searching and Sorting - In Algorithms

Here we gonna learn about searching and sorting algorithms. below everything is categorized by type of algorithm. Hope you will find it useful.
### Searching

Searching Algorithms are designed to check for an element or retrieve an element from any data structure where it is used. Given below is explanation of some of the most common searching algorithms.
#### Linear Search

A simple approach is to do a linear search, i.e       
- Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
- If x matches with an element, return the index.
- If x doesn’t match with any of elements, return -1.      

```cpp
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

Time Complexity: O(n)
```
![Linear Search](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/Algorithms/assets/Linear_Search.jpeg?raw=true)

#### Binary Search

#### Jump Search

#### Interpolation Search

#### Exponential Search

#### Ternary Search


### Sorting

A Sorting Algorithm is used to arranging the data of list or array into some specific order. It can be numerical or lexicographically order. Given below is explanation of some of the most common searching algorithms.   

There are two different categories in sorting. They are: 

- **Internal Sorting:** When all data is placed in memory, then sorting is called internal sorting.   
- **External Sorting:** When all data that needs to be sorted cannot be placed in memory at a time, the sorting is called External Sorting. External Sorting is used for massive amount of data. Merge Sort and its variations are typically used for external sorting. Some external storage like hard-disk, CD, etc is used for external storage.    

#### Selection Sort

#### Bubble Sort

#### Insertion Sort

#### Merge Sort

#### Heap Sort

#### QuickSort

#### Radix Sort

#### Counting Sort

#### Bucket Sort

#### ShellSort

#### Comb Sort

#### Pigeonhole Sort

#### Cycle Sort
#### More Searching and Sorting Algorithms

> **Source:** *GeeksforGeeks*           
> [https://www.geeksforgeeks.org/fundamentals-of-algorithms](https://www.geeksforgeeks.org/fundamentals-of-algorithms/#SearchingandSorting)        
> [https://www.geeksforgeeks.org/difference-between-searching-and-sorting-algorithms/](https://www.geeksforgeeks.org/difference-between-searching-and-sorting-algorithms/)