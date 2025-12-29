# Bit Algorithms

**Bit Manipulation** is the act of algorithmically manipulating bits or binary digits. It's a fundamental technique used in competitive programming and system-level programming.

**Bitwise Operations:** Bit manipulation involves operations on individual bits using bitwise operators (AND, OR, XOR, NOT, left shift, right shift). These operations are extremely fast and space-efficient, making them ideal for optimization problems, set operations, and low-level programming. Understanding bit manipulation is crucial for competitive programming and system design.

![Bitwise Operators Table](./assets/Bitwise_Operators_Table.png)

> **Image Credit:** [Wikipedia - Bitwise Operations](https://en.wikipedia.org/wiki/Bitwise_operation)

**Key Concepts:**
- Operations on individual bits
- Efficient operations using bitwise operators
- Space-efficient data representation
- Fast arithmetic operations

### Bitwise Operators

#### 1. AND (&)
Returns 1 if both bits are 1, else 0.

```cpp
5 & 3 = 1
// 5 = 101
// 3 = 011
// --------
// 1 = 001
```

#### 2. OR (|)
Returns 1 if at least one bit is 1, else 0.

```cpp
5 | 3 = 7
// 5 = 101
// 3 = 011
// --------
// 7 = 111
```

#### 3. XOR (^)
Returns 1 if bits are different, else 0.

```cpp
5 ^ 3 = 6
// 5 = 101
// 3 = 011
// --------
// 6 = 110
```

#### 4. NOT (~)
Flips all bits (1's complement).

```cpp
~5 = -6 (in 32-bit system)
// 5 = 000...101
// ~5 = 111...010
```

#### 5. Left Shift (<<)
Shifts bits to the left, fills with 0.

```cpp
5 << 2 = 20
// 5 = 101
// 5 << 2 = 10100 = 20
```

#### 6. Right Shift (>>)
Shifts bits to the right.

```cpp
20 >> 2 = 5
// 20 = 10100
// 20 >> 2 = 101 = 5
```

### Common Bit Operations

#### 1. Check if Bit is Set

```cpp
bool isBitSet(int num, int pos) {
    return (num & (1 << pos)) != 0;
}

// Example: Check if 3rd bit (0-indexed) of 5 is set
// 5 = 101, 3rd bit (from right) = 1
// isBitSet(5, 2) returns true
```

#### 2. Set a Bit

```cpp
int setBit(int num, int pos) {
    return num | (1 << pos);
}

// Example: Set 2nd bit of 5
// 5 = 101, setBit(5, 1) = 111 = 7
```

#### 3. Clear a Bit

```cpp
int clearBit(int num, int pos) {
    return num & ~(1 << pos);
}

// Example: Clear 2nd bit of 7
// 7 = 111, clearBit(7, 1) = 101 = 5
```

#### 4. Toggle a Bit

```cpp
int toggleBit(int num, int pos) {
    return num ^ (1 << pos);
}

// Example: Toggle 2nd bit of 5
// 5 = 101, toggleBit(5, 1) = 111 = 7
```

#### 5. Count Set Bits (Population Count)

```cpp
// Method 1: Loop through all bits
int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// Method 2: Brian Kernighan's Algorithm (faster)
int countSetBits(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1); // Removes rightmost set bit
        count++;
    }
    return count;
}

// Method 3: Built-in function (C++)
#include <bitset>
int countSetBits(int num) {
    return __builtin_popcount(num); // GCC built-in
}
```

**Time Complexity:** O(log n) or O(number of set bits) for Brian Kernighan's

#### 6. Find Most Significant Bit (MSB)

```cpp
int findMSB(int num) {
    if (num == 0) return 0;
    
    int msb = 0;
    while (num >>= 1) {
        msb++;
    }
    return msb;
}

// Using log
#include <cmath>
int findMSB(int num) {
    return (int)log2(num);
}
```

#### 7. Find Least Significant Bit (LSB)

```cpp
int findLSB(int num) {
    return num & (-num); // Returns number with only LSB set
}

// Or find position
int findLSBPosition(int num) {
    if (num == 0) return -1;
    return __builtin_ctz(num); // Count trailing zeros (GCC)
}
```

#### 8. Check if Number is Power of 2

```cpp
bool isPowerOf2(int num) {
    if (num == 0) return false;
    return (num & (num - 1)) == 0;
}

// Power of 2 has only one set bit
// num & (num - 1) clears the rightmost set bit
// If result is 0, only one bit was set
```

#### 9. Swap Two Numbers

```cpp
void swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b; // b = (a^b)^b = a
    a = a ^ b; // a = (a^b)^a = b
}
```

#### 10. Find Single Number (XOR Property)

```cpp
// Find single number when all others appear twice
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num; // XOR cancels duplicates
    }
    return result;
}

// Example: [2, 3, 2, 4, 4]
// 2^3^2^4^4 = (2^2)^(4^4)^3 = 0^0^3 = 3
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

### Advanced Bit Manipulation Problems

#### 1. Find Two Single Numbers

Given array where all numbers appear twice except two numbers.

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> findTwoSingles(vector<int>& nums) {
    int xorAll = 0;
    for (int num : nums) {
        xorAll ^= num;
    }
    
    // Find rightmost set bit in xorAll
    int rightmostSetBit = xorAll & (-xorAll);
    
    int num1 = 0, num2 = 0;
    
    // Divide numbers into two groups based on rightmost set bit
    for (int num : nums) {
        if (num & rightmostSetBit) {
            num1 ^= num;
        }
        else {
            num2 ^= num;
        }
    }
    
    return {num1, num2};
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> result = findTwoSingles(nums);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
```

#### 2. Count Bits in Range

Count total set bits from 1 to n.

```cpp
int countBits(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += __builtin_popcount(i);
    }
    return count;
}

// Optimized using pattern
int countBits(int n) {
    if (n == 0) return 0;
    
    int powerOf2 = (int)log2(n);
    int count = powerOf2 * (1 << (powerOf2 - 1));
    
    int remaining = n - (1 << powerOf2) + 1;
    count += remaining;
    count += countBits(remaining - 1);
    
    return count;
}
```

#### 3. Reverse Bits

```cpp
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}
```

#### 4. Power Set Using Bits

Generate all subsets using bit manipulation.

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> powerSet(vector<int>& nums) {
    int n = nums.size();
    int totalSubsets = 1 << n; // 2^n
    
    vector<vector<int>> result;
    
    for (int i = 0; i < totalSubsets; i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { // Check if jth bit is set
                subset.push_back(nums[j]);
            }
        }
        result.push_back(subset);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets = powerSet(nums);
    
    for (auto& subset : subsets) {
        for (int x : subset) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
```

**Time Complexity:** O(2^n × n)  
**Space Complexity:** O(2^n)

#### 5. Maximum XOR of Two Numbers

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findMaximumXOR(vector<int>& nums) {
    int maxXOR = 0;
    int mask = 0;
    
    for (int i = 31; i >= 0; i--) {
        mask |= (1 << i);
        unordered_set<int> prefixes;
        
        for (int num : nums) {
            prefixes.insert(num & mask);
        }
        
        int candidate = maxXOR | (1 << i);
        
        for (int prefix : prefixes) {
            if (prefixes.find(candidate ^ prefix) != prefixes.end()) {
                maxXOR = candidate;
                break;
            }
        }
    }
    
    return maxXOR;
}
```

### Bit Tricks and Hacks

#### 1. Multiply by 2
```cpp
int multiplyBy2(int n) {
    return n << 1; // Left shift by 1
}
```

#### 2. Divide by 2
```cpp
int divideBy2(int n) {
    return n >> 1; // Right shift by 1
}

// For negative numbers, use arithmetic right shift
int divideBy2(int n) {
    return (n + (n >> 31)) >> 1; // Handles negative
}
```

#### 3. Check if Even/Odd
```cpp
bool isEven(int n) {
    return (n & 1) == 0;
}

bool isOdd(int n) {
    return (n & 1) == 1;
}
```

#### 4. Absolute Value
```cpp
int abs(int n) {
    int mask = n >> 31; // -1 if negative, 0 if positive
    return (n ^ mask) - mask;
}
```

#### 5. Minimum of Two Numbers
```cpp
int min(int a, int b) {
    return b ^ ((a ^ b) & -(a < b));
}
```

#### 6. Maximum of Two Numbers
```cpp
int max(int a, int b) {
    return a ^ ((a ^ b) & -(a < b));
}
```

### Bit Manipulation Patterns

#### Pattern 1: XOR Properties
- `a ^ a = 0`
- `a ^ 0 = a`
- `a ^ b = b ^ a`
- `(a ^ b) ^ c = a ^ (b ^ c)`

#### Pattern 2: AND Properties
- `a & a = a`
- `a & 0 = 0`
- `a & ~a = 0`

#### Pattern 3: OR Properties
- `a | a = a`
- `a | 0 = a`
- `a | ~a = -1` (all bits set)

### Common Bit Manipulation Problems (Striver's A2Z)

1. Check if bit is set
2. Set/Clear/Toggle bit
3. Count set bits
4. Find single number
5. Find two single numbers
6. Power of 2
7. Reverse bits
8. Count bits in range
9. Maximum XOR of two numbers
10. Power set using bits
11. Subset sum using bits
12. Gray code
13. Number of 1 bits
14. Missing number
15. Complement of number
16. Bitwise AND of range
17. XOR queries
18. Maximum XOR

### Time Complexity

| Operation | Time Complexity |
|-----------|----------------|
| Basic bit operations | O(1) |
| Count set bits | O(log n) or O(number of set bits) |
| Power set | O(2^n × n) |
| Maximum XOR | O(n × 32) |

### Space Complexity

- **Space Complexity:** O(1) for most operations
- **Auxiliary Space:** O(1) to O(n) depending on problem

### Advantages of Bit Manipulation

1. **Fast operations** - Hardware-level operations
2. **Space efficient** - Can represent multiple flags in one integer
3. **Powerful tricks** - Many elegant solutions
4. **Competitive programming** - Essential skill

### Disadvantages of Bit Manipulation

1. **Less readable** - Can be hard to understand
2. **Error-prone** - Easy to make mistakes
3. **Platform dependent** - Bit representation varies
4. **Limited to integers** - Can't use with floats directly

### Applications

1. **Competitive Programming** - Fast solutions
2. **System Programming** - Flags, permissions
3. **Cryptography** - Encryption algorithms
4. **Graphics** - Color manipulation
5. **Networking** - Protocol headers
6. **Memory Optimization** - Pack multiple values

### References

- [GeeksforGeeks - Bit Manipulation](https://www.geeksforgeeks.org/bits-manipulation-important-tactics/)
- [GeeksforGeeks - Bitwise Operators](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
- [GeeksforGeeks - Bit Manipulation Problems](https://www.geeksforgeeks.org/tag/bit-manipulation/)
