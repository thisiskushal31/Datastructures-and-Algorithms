### Searching and Sorting - In Algorithms

Here we gonna learn about searching and sorting algorithms. below everything is categorized by type of algorithm. Hope you will find it useful.
### Searching

Searching Algorithms are designed to check for an element or retrieve an element from any data structure where it is used. Given below is explanation of some of the most common searching algorithms.
#### Linear Search

Linear Search sequentially checks each element of the list until a match is found or the whole list has been searched.

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
```

![Linear Search](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/Algorithms/assets/Linear_Search.png?raw=true)         

> Note-But in case we wanna make Linear Search more efficient we can also use Divide_and_Conquer and then we gonna do a linear search.     

[More Detail on Linear Search](https://www.geeksforgeeks.org/linear-search/)     

#### Binary Search

*Binary Search* is a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(Log n).       

**Binary Search Algorithm:** The basic steps to perform Binary Search are:   

- Begin with the mid element of the whole array as search key.
- If the value of the search key is equal to the item then return index of the search key.
- Or if the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
- Otherwise, narrow it to the upper half.
- Repeatedly check from the second point until the value is found or the interval is empty.

![Binary Search](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/Algorithms/assets/Binary_Search.jpg?raw=true)      

**Step-by-step Binary Search Algorithm:** We basically ignore half of the elements just after one comparison.
   
1. Compare x with the middle element.
2. If x matches with the middle element, we return the mid index.
3. Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we recur for the right half.
4. Else (x is smaller) recur for the left half.

There is two *Types of Binary Search* also one is Recursive and other is Iterative both of then uses some process as above but there is just a bit of diferent in code.     

- **Recursive Binary Search:** A recursive binary search function. It returns location of x in given array arr[l..r] is present, otherwise -1.     

```cpp
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
```
    Auxiliary Space : O(log n) | Time Complexity : O(log n)

- **Iterative Binary Search:** A Iterative binary search check covers all cases, so need to check for *mid = low - (high-low)/2*     

```cpp
int binarySearch(vector<int> v, int To_Find)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (v[mid] < To_Find) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if (v[lo] == To_Find) {
        cout << "Found"
             << " At Index " << lo << endl;
    }
    else if (v[hi] == To_Find) {
        cout << "Found"
             << " At Index " << hi << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
}
```

    Time Complexity: O (log n) | Auxiliary Space: O (1)

#### Jump Search

Let’s consider the following array: (0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610). The length of the array is 16. The Jump search will find the value of 55 with the following steps assuming that the block size to be jumped is 4. 
- Step 1: Jump from index 0 to index 4; 
- Step 2: Jump from index 4 to index 8; 
- Step 3: Jump from index 8 to index 12; 
- Step 4: Since the element at index 12 is greater than 55, we will jump back a step to come to index 8. 
- Step 5: Perform a linear search from index 8 to get the element 55.

![Jump Search](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/Algorithms/assets/Jump_Search.jpg?raw=true)

#### Interpolation Search

The Interpolation Search is an improvement over Binary Search for instances, where the values in a sorted array are uniformly distributed. Interpolation constructs new data points within the range of a discrete set of known data points. Binary Search always goes to the middle element to check. On the other hand, interpolation search may go to different locations according to the value of the key being searched. For example, if the value of the key is closer to the last element, interpolation search is likely to start search toward the end side.       
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
