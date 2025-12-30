# Randomized Algorithms

**Randomized Algorithms** are algorithms that use random numbers to make decisions during execution. They can be faster or simpler than deterministic algorithms and are useful when the problem space is too large.

**Randomization in Algorithms:** Randomized algorithms use randomness as a tool to achieve better average-case performance or simplify algorithm design. They fall into two categories: Las Vegas algorithms (always correct, random running time) and Monte Carlo algorithms (fixed running time, small error probability). Examples include randomized quicksort, hash functions, and probabilistic data structures.

![Randomized Quicksort](./assets/Randomized_Quicksort.png)

> **Image Credit:** [Geek Factorial - Randomized Quick Sort Algorithm](https://geekfactorial.blogspot.com/2016/08/randomized-quick-sort-algorithm.html)

**Key Properties:**
- Use random number generation
- May have probabilistic guarantees
- Often simpler than deterministic alternatives
- Can be faster on average

**Types:**
1. **Las Vegas:** Always correct, running time is random
2. **Monte Carlo:** Running time is fixed, may have small error probability

### Random Number Generation

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

// Using rand() (not recommended for serious use)
int randomInt(int min, int max) {
    srand(time(0));
    return min + rand() % (max - min + 1);
}

// Using modern C++ random library (recommended)
int randomIntModern(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// Random double between 0 and 1
double randomDouble() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}
```

### Randomized Algorithms

#### 1. Randomized Quick Sort

The worst case time complexity of a typical implementation of Quick Sort is O(n²). The worst case occurs when the picked pivot is always an extreme (smallest or largest) element, which happens when the input array is either sorted or reversely sorted and either first or last element is picked as pivot.

**Randomized Quick Sort algorithm (with random pivot):**

In the randomized version of Quick sort we impose a distribution on input by picking the pivot element randomly. Randomized Quick Sort works well even when the array is sorted/reversely sorted and the complexity is more towards O(n log n). (Yet, there is still a possibility that the randomly picked element is always an extreme.)

Here, we will pick a random pivot position with the help of `rand()` function (defined in `stdlib.h` header file). Then we can swap pivot element with the element at the `Left` position (or the `Right` position in some implementations) and Quick Sort the array.

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(vector<int>& A, int x, int y) {
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

int getPivot(int Left, int Right) {
    return (rand() % (Right - Left + 1)) + Left;
}

void quickSort(vector<int>& A, int Left, int Right) {
    if (Left > Right)
        return;
    
    int i, pos, pivot;

    // Choosing pivot element randomly:
    pivot = getPivot(Left, Right);  // Get a random pivot
    swap(A, Left, pivot);           // Take A[pivot] to Left index and then do Quick Sort

    // Quick Sort the array:
    pos = Left;
        
    for (i = Left + 1; i <= Right; i++)
        if (A[i] < A[Left])
            swap(A, ++pos, i);

    swap(A, Left, pos);  // By now, pos must be at proper position for A[Left].
                         // So we swap A[Left] with A[pos]

    quickSort(A, Left, pos - 1);     // Sort left sub-list
    quickSort(A, pos + 1, Right);    // Sort right sub-list
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    srand(time(0));
    quickSort(arr, 0, arr.size() - 1);
    
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
```

**Time Complexity:** O(n log n) average case, O(n log n) expected worst case (rare O(n²) still possible but highly unlikely)  
**Space Complexity:** O(log n)

**Key Advantage:** By randomizing the pivot selection, we avoid the worst-case scenario that occurs with sorted or reverse-sorted arrays, making the algorithm more robust and predictable in practice.

#### 2. Randomized Selection (Quick Select)

Find kth smallest element.

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomPartition(vector<int>& arr, int low, int high) {
    srand(time(0));
    int random = low + rand() % (high - low + 1);
    swap(arr[random], arr[high]);
    
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedSelect(vector<int>& arr, int low, int high, int k) {
    if (low == high) return arr[low];
    
    int pivotIndex = randomPartition(arr, low, high);
    int rank = pivotIndex - low + 1;
    
    if (k == rank) {
        return arr[pivotIndex];
    }
    else if (k < rank) {
        return randomizedSelect(arr, low, pivotIndex - 1, k);
    }
    else {
        return randomizedSelect(arr, pivotIndex + 1, high, k - rank);
    }
}

int findKthSmallest(vector<int>& arr, int k) {
    return randomizedSelect(arr, 0, arr.size() - 1, k);
}
```

**Time Complexity:** O(n) average, O(n²) worst case  
**Space Complexity:** O(log n)

#### 3. Randomized Binary Search Tree

```cpp
// See Splay Tree section for self-adjusting trees
```

#### 4. Monte Carlo Algorithm for Prime Testing

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Miller-Rabin Primality Test (Monte Carlo)
long long modPower(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

bool millerTest(long long n, long long d) {
    srand(time(0));
    long long a = 2 + rand() % (n - 4);
    long long x = modPower(a, d, n);
    
    if (x == 1 || x == n - 1) return true;
    
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    
    return false;
}

bool isPrimeMonteCarlo(long long n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;
    
    long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }
    
    for (int i = 0; i < k; i++) {
        if (!millerTest(n, d)) {
            return false;
        }
    }
    
    return true;
}
```

**Time Complexity:** O(k × log³ n) where k is number of iterations  
**Space Complexity:** O(1)

### Advantages of Randomized Algorithms

1. **Simplicity** - Often simpler than deterministic versions
2. **Average case performance** - Better average time complexity
3. **Avoid worst case** - Randomization helps avoid bad inputs
4. **Parallelization** - Can be easily parallelized

### Disadvantages of Randomized Algorithms

1. **Non-deterministic** - Different runs may give different results
2. **Error probability** - Monte Carlo algorithms may have errors
3. **Random number quality** - Depends on good random number generator
4. **Hard to debug** - Non-deterministic behavior

### When to Use Randomized Algorithms?

✅ **Use Randomized when:**
- Deterministic algorithm is complex
- Average case is more important than worst case
- Small error probability is acceptable
- Need to avoid worst-case inputs

❌ **Don't use Randomized when:**
- Need guaranteed correctness
- Deterministic solution is simple
- Worst-case performance is critical

### Applications

1. **Quick Sort:** Randomized pivot selection
2. **Hash Tables:** Random hash functions
3. **Cryptography:** Random number generation
4. **Monte Carlo Methods:** Simulation, approximation
5. **Load Balancing:** Random assignment

### References

- [GeeksforGeeks - Randomized Algorithms](https://www.geeksforgeeks.org/randomized-algorithms/)
- [Geek Factorial - Randomized Quick Sort Algorithm](https://geekfactorial.blogspot.com/2016/08/randomized-quick-sort-algorithm.html)
