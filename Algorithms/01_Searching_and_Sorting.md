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

[More Detail on Binary Search](https://www.geeksforgeeks.org/binary-search/)    
#### Jump Search

Let’s consider the following array: (0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610). The length of the array is 16. The Jump search will find the value of 55 with the following steps assuming that the block size to be jumped is 4. 
- Step 1: Jump from index 0 to index 4; 
- Step 2: Jump from index 4 to index 8; 
- Step 3: Jump from index 8 to index 12; 
- Step 4: Since the element at index 12 is greater than 55, we will jump back a step to come to index 8. 
- Step 5: Perform a linear search from index 8 to get the element 55.

![Jump Search](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/Algorithms/assets/Jump_Search.jpg?raw=true)

[More Detail on Jump Search](https://www.geeksforgeeks.org/jump-search/)

#### Interpolation Search

Interpolation similar to binary search but it uses better way to find mid element and *Interpolation search works better than Binary Search for a Sorted and Uniformly Distributed array.*

Interpolation constructs new data points within the range of a discrete set of known data points. Binary Search always goes to the middle element to check. On the other hand, interpolation search may go to different locations according to the value of the key being searched. For example, if the value of the key is closer to the last element, interpolation search is likely to start search toward the end side.       

The idea of formula is to return higher value of pos when element to be searched is closer to arr[hi] and smaller value when closer to arr[lo]. 

##### What is Uniformly Distributed Array?

*Here is simple Explanation of Uniformly Distributed Array.*     

Usually an array is considered as uniformly distributed when the difference between the elements are equal or almost same. Example 1: 1,2,3,4,5,6 (Difference is 1)     

Example 2: 10,20,31,40,55,60,73,80(Here the difference between the two adjacent elements are almost close to 10).    

Interpolation search is to be used when the given array is both sorted and uniformly distributed to have log(log n) time complexity.    

```cpp
To find the position to be searched, it uses the following formula: 
pos = lo + (x - arr[lo]) *(hi - lo)/(arr[hi] - arr[lo])

arr[] ==> Array where elements need to be searched
x     ==> Element to be searched
lo    ==> Starting index in arr[]
hi    ==> Ending index in arr[]
```      

![Interpolation Search](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/Algorithms/assets/Interpolation_Search_Formula.png?raw=true)        

*The formula for pos can be derived as follows.*      

```cpp
General equation of line : y = m*x + c.
y is the value in the array and x is its index.

Now putting value of lo,hi and x in the equation
arr[hi] = m*hi+c ----(1)
arr[lo] = m*lo+c ----(2)
x = m*pos + c     ----(3)

m = (arr[hi] - arr[lo] )/ (hi - lo)

subtracting eqxn (2) from (3)
x - arr[lo] = m * (pos - lo)
lo + (x - arr[lo])/m = pos
pos = lo + (x - arr[lo]) *(hi - lo)/(arr[hi] - arr[lo])
```

##### Algorithm 
*The rest of the Interpolation algorithm is the same except for the above partition logic.* 
- **Step1:** In a loop, calculate the value of “pos” using the probe position formula. 
- **Step2:** If it is a match, return the index of the item, and exit. 
- **Step3:** If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise, calculate the same in the right sub-array. 
- **Step4:** Repeat until a match is found or the sub-array reduces to zero.       

*Below is the implementation of the algorithm.*

```cpp
// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;
  
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
  
        // Probing the position with keeping
        // uniform distribution in mind.
        pos = lo
              + (((double)(hi - lo) / (arr[hi] - arr[lo]))
                 * (x - arr[lo]));
  
        // Condition of target found
        if (arr[pos] == x)
            return pos;
  
        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);
  
        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}
```    

[More Details On Interpolation Search](https://www.geeksforgeeks.org/interpolation-search/)
#### Exponential Search

**Exponential search involves two steps:**     
- Find range where element is present   
- Do Binary Search in above found range.   

##### How to find the range where element may be present? 

The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until last element of a subarray is not greater.       

Once we find an index i (after repeated doubling of i), we know that the element must be present between i/2 and i (Why i/2? because we could not find a greater value in previous iteration)       

*Given below are the implementations of above steps.*

```cpp
// Returns position of first occurrence of
// x in array
int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at first location itself
    if (arr[0] == x)
        return 0;
  
    // Find range for binary search by repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
  
    //  Call binary search for the found range.
    return binarySearch(arr, i/2, 
                            min(i, n-1), x);
}
  
// A recursive binary search function. It returns
// location of x in  given array arr[l..r] is
// present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;
  
        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then it
        // can only be present n left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid+1, r, x);
    }
  
    // We reach here when element is not present in array
    return -1;
}
```

- **Time Complexity :** O(Log n) 
- **Auxiliary Space :** The above implementation of Binary Search is recursive and requires O(Log n) space. With iterative Binary Search, we need only O(1) space.


**Applications of Exponential Search:**     

- Exponential Binary Search is particularly useful for unbounded searches, where size of array is infinite.
- It works better than Binary Search for bounded arrays, and also when the element to be searched is closer to the first element.

[More Details on Exponential Search](https://www.geeksforgeeks.org/exponential-search/)
#### Ternary Search

*Ternary search* is a decrease(by constant) and conquer algorithm that can be used to find an element in an array. It is similar to binary search where we divide the array into two parts but in this algorithm, we divide the given array into three parts and determine which has the key (searched element). We can divide the array into three parts by taking mid1 and mid2 which can be calculated as shown below. Initially, l and r will be equal to 0 and n-1 respectively, where n is the length of the array.     

It is same as the binary search. The only difference is that, it reduces the time complexity a bit more. Its time complexity 
is O(log n base 3) and that of binary search is O(log n base 2).         

    mid1 = l + (r-l)/3 
    mid2 = r – (r-l)/3     

**Steps to perform Ternary Search:**     
    
    Note: Array needs to be sorted to perform ternary search on it.

**1.** First, we compare the key with the element at mid1. If found equal, we return mid1.    
**2.** If not, then we compare the key with the element at mid2. If found equal, we return mid2.    
**3.** If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.   
**4.** If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.   
**5.** If not, then we recur to the second (middle) part.    

**Recursive Implementation of Ternary Search**

```cpp
int ternarySearch(int l, int r, int key, int ar[])
{
    if (r >= l) {
 
        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
 
        // Check if key is present at any mid
        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }
 
        // Since key is not present at mid,
        // check in which region it is present
        // then repeat the Search operation
        // in that region
        if (key < ar[mid1]) {
 
            // The key lies in between l and mid1
            return ternarySearch(l, mid1 - 1, key, ar);
        }
        else if (key > ar[mid2]) {
 
            // The key lies in between mid2 and r
            return ternarySearch(mid2 + 1, r, key, ar);
        }
        else {
 
            // The key lies in between mid1 and mid2
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
        }
    }
 
    // Key not found
    return -1;
}
```    

- Time Complexity:  O(log<sub>3</sub>n)     
- Auxiliary Space: O(log<sub>3</sub>n)    

**Iterative Approach of Ternary Search**    

```cpp
int ternarySearch(int l, int r, int key, int ar[])
 
{
    while (r >= l) {

        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
 
        // Check if key is present at any mid
        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }
 
        // Since key is not present at mid,
        // check in which region it is present
        // then repeat the Search operation
        // in that region
 
        if (key < ar[mid1]) {
 
            // The key lies in between l and mid1
            r = mid1 - 1;
        }
        else if (key > ar[mid2]) {
 
            // The key lies in between mid2 and r
            l = mid2 + 1;
        }
        else {
 
            // The key lies in between mid1 and mid2
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
 
    // Key not found
    return -1;
}
```

- Time Complexity:  O(log<sub>3</sub>n), where n is the size of the array.     
- Auxiliary Space: O(1)    

**Binary search Vs Ternary Search:** [https://www.geeksforgeeks.org/binary-search-preferred-ternary-search/](https://www.geeksforgeeks.org/binary-search-preferred-ternary-search/)

[More Details on the Ternary Search](https://www.geeksforgeeks.org/ternary-search/)

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
