### Logic Building

**Logic Building** is the foundation of problem-solving in programming. It involves developing the ability to break down problems, think algorithmically, and write code that solves real-world problems efficiently.

**Problem-Solving Process:** Logic building starts with understanding the problem, breaking it into smaller subproblems, identifying patterns, designing a solution using appropriate data structures and algorithms, implementing it step-by-step, and testing with various inputs. This systematic approach helps transform complex problems into manageable code solutions.

> **Note:** Logic building is a fundamental skill that improves with practice. Start with simple problems and gradually move to more complex ones, focusing on pattern recognition and algorithmic thinking.

**Key Concepts:**
- Problem analysis and decomposition
- Algorithmic thinking
- Pattern recognition
- Step-by-step problem solving
- Code structure and organization

### Problem-Solving Approach

#### 1. Understand the Problem
- Read the problem carefully
- Identify inputs and outputs
- Understand constraints
- Identify edge cases

#### 2. Break Down the Problem
- Divide into smaller subproblems
- Identify patterns
- Think about similar problems
- Consider different approaches

#### 3. Design the Solution
- Choose appropriate data structures
- Select suitable algorithms
- Plan the algorithm steps
- Consider time/space complexity

#### 4. Implement the Solution
- Write clean, readable code
- Handle edge cases
- Add comments for clarity
- Test with sample inputs

#### 5. Test and Debug
- Test with various inputs
- Check edge cases
- Verify correctness
- Optimize if needed

### Basic Programming Patterns

#### Pattern 1: Input/Output Handling

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Reading integers
    int n;
    cin >> n;
    
    // Reading array
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Processing
    // ...
    
    // Output
    cout << result << endl;
    
    return 0;
}
```

#### Pattern 2: Conditional Logic

```cpp
// If-else statements
if (condition1) {
    // Code block 1
}
else if (condition2) {
    // Code block 2
}
else {
    // Code block 3
}

// Switch statement
switch (variable) {
    case value1:
        // Code
        break;
    case value2:
        // Code
        break;
    default:
        // Code
}
```

#### Pattern 3: Loops

```cpp
// For loop
for (int i = 0; i < n; i++) {
    // Code
}

// While loop
while (condition) {
    // Code
}

// Do-while loop
do {
    // Code
} while (condition);

// Range-based for loop (C++11)
for (int element : container) {
    // Code
}
```

#### Pattern 4: Functions

```cpp
// Function definition
returnType functionName(parameters) {
    // Function body
    return value;
}

// Example
int add(int a, int b) {
    return a + b;
}

// Function call
int result = add(5, 3);
```

### Common Problem-Solving Patterns

#### Pattern 1: Counting Problems

```cpp
// Count occurrences
int countOccurrences(vector<int>& arr, int target) {
    int count = 0;
    for (int num : arr) {
        if (num == target) {
            count++;
        }
    }
    return count;
}
```

#### Pattern 2: Finding Maximum/Minimum

```cpp
// Find maximum
int findMax(vector<int>& arr) {
    int maxVal = INT_MIN;
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

// Find minimum
int findMin(vector<int>& arr) {
    int minVal = INT_MAX;
    for (int num : arr) {
        if (num < minVal) {
            minVal = num;
        }
    }
    return minVal;
}
```

#### Pattern 3: Summation Problems

```cpp
// Sum of array elements
int sumArray(vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

// Sum of even numbers
int sumEven(vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        if (num % 2 == 0) {
            sum += num;
        }
    }
    return sum;
}
```

#### Pattern 4: Searching Problems

```cpp
// Linear search
int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Not found
}
```

#### Pattern 5: Array Manipulation

```cpp
// Reverse array
void reverseArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// Rotate array
void rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}
```

### Logic Building Exercises

#### Exercise 1: Check if Number is Prime

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
```

#### Exercise 2: Find Factorial

```cpp
long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
```

#### Exercise 3: Check Palindrome

```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
```

#### Exercise 4: Find GCD

```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
```

#### Exercise 5: Fibonacci Sequence

```cpp
int fibonacci(int n) {
    if (n <= 1) return n;
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
```

### Debugging Techniques

#### 1. Print Statements
```cpp
cout << "Debug: value = " << value << endl;
```

#### 2. Check Edge Cases
- Empty input
- Single element
- Maximum values
- Negative numbers
- Zero values

#### 3. Step Through Code
- Trace execution manually
- Check variable values at each step
- Verify logic flow

#### 4. Use Debugger
- Set breakpoints
- Inspect variables
- Step through code line by line

### Best Practices

#### 1. Code Readability
- Use meaningful variable names
- Add comments for complex logic
- Follow consistent formatting
- Keep functions small and focused

#### 2. Error Handling
```cpp
// Check for invalid input
if (n < 0) {
    cout << "Invalid input" << endl;
    return -1;
}
```

#### 3. Modular Code
- Break code into functions
- Reuse code when possible
- Keep functions single-purpose

#### 4. Efficiency
- Choose appropriate data structures
- Avoid unnecessary computations
- Consider time/space complexity

### Common Mistakes to Avoid

1. **Off-by-one errors** - Check loop boundaries
2. **Integer overflow** - Use appropriate data types
3. **Array bounds** - Always check array indices
4. **Null pointers** - Check before dereferencing
5. **Infinite loops** - Ensure loop termination
6. **Missing edge cases** - Test boundary conditions

### Logic Building Resources

#### Practice Problems (Easy)
1. Sum of two numbers
2. Check even/odd
3. Find maximum of three numbers
4. Check leap year
5. Calculate area of circle
6. Convert temperature
7. Check vowel/consonant
8. Find largest digit
9. Reverse a number
10. Check armstrong number

#### Practice Problems (Medium)
1. Prime number generation
2. Factorial calculation
3. Fibonacci series
4. Palindrome checking
5. GCD/LCM calculation
6. Pattern printing
7. Number system conversion
8. String manipulation
9. Array operations
10. Matrix operations

### Next Steps

After mastering logic building:
1. Learn [Time Complexity and Space Complexity](./01_Time_Complexity_and_Space_Complexity.md)
2. Practice basic [Searching and Sorting](./02_Searching_and_Sorting.md)
3. Understand [Data Structures](../DataStructures/Readme.md)
4. Explore [Foundation](../Foundation/Readme.md) concepts
5. Solve problems on coding platforms

### References

- [GeeksforGeeks - Basic Programming](https://www.geeksforgeeks.org/basic-programming/)
- [GeeksforGeeks - Problem Solving](https://www.geeksforgeeks.org/problem-solving/)

