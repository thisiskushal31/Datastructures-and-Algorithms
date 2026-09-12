# Coding Patterns for Solving DSA Problems

This document covers **16 essential coding patterns** for solving Data Structures and Algorithms problems during interviews. These patterns provide a systematic approach to problem-solving and help recognize common problem types.

**Reference:** [Several Coding Patterns for Solving Data Structures and Algorithms Problems during Interviews](https://github.com/Chanda-Abdul/Several-Coding-Patterns-for-Solving-Data-Structures-and-Algorithms-Problems-during-Interviews)

---

## Pattern 1: Sliding Window

**When to Use:** Problems involving subarrays or substrings with a fixed or variable window size.

**Key Concept:** Maintain a window that slides through the array/string, efficiently updating the window by removing elements from one end and adding from the other.

### Fixed Window Size

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Example: Maximum sum of K consecutive elements
int maxSumKConsecutive(vector<int>& arr, int k) {
    int n = arr.size();
    if (k > n) return -1;
    
    int windowSum = 0;
    // Sum of first window
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    
    int maxSum = windowSum;
    
    // Slide window
    for (int i = k; i < n; i++) {
        windowSum = windowSum - arr[i - k] + arr[i];
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

### Variable Window Size

```cpp
// Example: Longest substring with K distinct characters
int longestSubstringKDistinct(string s, int k) {
    int n = s.length();
    unordered_map<char, int> charCount;
    int left = 0;
    int maxLen = 0;
    
    for (int right = 0; right < n; right++) {
        charCount[s[right]]++;
        
        // Shrink window if more than k distinct characters
        while (charCount.size() > k) {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) {
                charCount.erase(s[left]);
            }
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(k) for hash map

**Common Problems:**
- Maximum sum subarray of size K
- Longest substring with K distinct characters
- Minimum window substring
- Average of all subarrays of size K

---

## Pattern 2: Two Pointers

**When to Use:** Problems with sorted arrays or linked lists where we need to find pairs/triplets that meet certain constraints.

**Key Concept:** Use two pointers moving from different ends or at different speeds to find pairs or triplets efficiently.

### Opposite Ends (Sorted Array)

```cpp
// Example: Find pair with target sum in sorted array
vector<int> twoSum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == target) {
            return {left, right};
        }
        else if (sum < target) {
            left++; // Need larger sum
        }
        else {
            right--; // Need smaller sum
        }
    }
    
    return {}; // No pair found
}
```

### Same Direction

```cpp
// Example: Remove duplicates from sorted array
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int writeIndex = 1;
    for (int readIndex = 1; readIndex < nums.size(); readIndex++) {
        if (nums[readIndex] != nums[readIndex - 1]) {
            nums[writeIndex++] = nums[readIndex];
        }
    }
    
    return writeIndex;
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

**Common Problems:**
- Two sum in sorted array
- Remove duplicates
- Squaring sorted array
- Triplets with target sum

---

## Pattern 3: Fast & Slow Pointers (Hare & Tortoise)

**When to Use:** Problems involving cycles in linked lists or arrays, finding middle element, or detecting cycles.

**Key Concept:** Use two pointers moving at different speeds. The fast pointer moves twice as fast as the slow pointer.

### Cycle Detection

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true; // Cycle detected
        }
    }
    
    return false;
}
```

### Find Middle Element

```cpp
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

**Common Problems:**
- Detect cycle in linked list
- Find middle of linked list
- Find kth node from end
- Palindrome linked list

---

## Pattern 4: Merge Intervals

**When to Use:** Problems involving overlapping intervals, merging intervals, or scheduling conflicts.

**Key Concept:** Sort intervals by start time, then merge overlapping intervals.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start, end;
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> mergeIntervals(vector<Interval>& intervals) {
    if (intervals.empty()) return {};
    
    // Sort by start time
    sort(intervals.begin(), intervals.end(), 
         [](Interval a, Interval b) {
             return a.start < b.start;
         });
    
    vector<Interval> merged;
    merged.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        Interval& last = merged.back();
        
        // Overlapping intervals
        if (intervals[i].start <= last.end) {
            last.end = max(last.end, intervals[i].end);
        }
        else {
            merged.push_back(intervals[i]);
        }
    }
    
    return merged;
}
```

**Time Complexity:** O(n log n) for sorting  
**Space Complexity:** O(n)

**Common Problems:**
- Merge intervals
- Insert interval
- Interval intersection
- Meeting rooms

---

## Pattern 5: Cyclic Sort

**When to Use:** Problems involving arrays with numbers in a given range (e.g., 1 to n).

**Key Concept:** Place each number at its correct index (number i at index i-1).

```cpp
// Example: Find all missing numbers in array [1..n]
vector<int> findMissingNumbers(vector<int>& nums) {
    int i = 0;
    int n = nums.size();
    
    // Cyclic sort
    while (i < n) {
        int correctIndex = nums[i] - 1;
        if (nums[i] != nums[correctIndex]) {
            swap(nums[i], nums[correctIndex]);
        }
        else {
            i++;
        }
    }
    
    // Find missing numbers
    vector<int> missing;
    for (int j = 0; j < n; j++) {
        if (nums[j] != j + 1) {
            missing.push_back(j + 1);
        }
    }
    
    return missing;
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

**Common Problems:**
- Find missing numbers
- Find duplicate numbers
- Find first missing positive
- Find all duplicates

---

## Pattern 6: In-place Reversal of Linked List

**When to Use:** Problems requiring reversal of linked list nodes in-place without extra memory.

**Key Concept:** Reverse links between nodes by maintaining previous, current, and next pointers.

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    
    while (current) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Reverse portion of linked list
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    
    // Move to left position
    for (int i = 0; i < left - 1; i++) {
        prev = prev->next;
    }
    
    // Reverse
    ListNode* current = prev->next;
    for (int i = 0; i < right - left; i++) {
        ListNode* next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    
    return dummy->next;
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

**Common Problems:**
- Reverse linked list
- Reverse linked list II (reverse portion)
- Reverse nodes in k-group
- Reverse alternating k-group

---

## Pattern 7: Tree Breadth First Search (BFS)

**When to Use:** Problems requiring level-by-level traversal of trees or finding shortest paths.

**Key Concept:** Use a queue to process nodes level by level.

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Level-order traversal
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(currentLevel);
    }
    
    return result;
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(w) where w is maximum width

**Common Problems:**
- Level-order traversal
- Zigzag traversal
- Right side view
- Minimum depth of binary tree

---

## Pattern 8: Depth First Search (DFS)

**When to Use:** Problems requiring traversal to leaf nodes, path problems, or tree structure problems.

**Key Concept:** Use recursion (or stack) to traverse deep into tree before backtracking.

```cpp
// Pre-order traversal
void preorderDFS(TreeNode* root, vector<int>& result) {
    if (!root) return;
    
    result.push_back(root->val); // Process node
    preorderDFS(root->left, result);
    preorderDFS(root->right, result);
}

// In-order traversal
void inorderDFS(TreeNode* root, vector<int>& result) {
    if (!root) return;
    
    inorderDFS(root->left, result);
    result.push_back(root->val); // Process node
    inorderDFS(root->right, result);
}

// Post-order traversal
void postorderDFS(TreeNode* root, vector<int>& result) {
    if (!root) return;
    
    postorderDFS(root->left, result);
    postorderDFS(root->right, result);
    result.push_back(root->val); // Process node
}

// Path sum
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }
    
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(h) where h is height

**Common Problems:**
- Tree traversals
- Path sum
- Maximum depth
- Same tree
- Symmetric tree

---

## Pattern 9: Two Heaps

**When to Use:** Problems where we need to find smallest element in one part and largest in another part.

**Key Concept:** Use min-heap for one part and max-heap for the other.

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // Left half (max at top)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Right half (min at top)
    
public:
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }
        
        // Balance heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
    }
};
```

**Time Complexity:** O(log n) for insertion, O(1) for median  
**Space Complexity:** O(n)

**Common Problems:**
- Find median from data stream
- Sliding window median
- IPO problem
- Maximize capital

---

## Pattern 10: Subsets

**When to Use:** Problems involving generating all subsets, combinations, or permutations.

**Key Concept:** Use BFS or backtracking to generate all subsets incrementally.

```cpp
// Generate all subsets
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    result.push_back({}); // Empty subset
    
    for (int num : nums) {
        int n = result.size();
        for (int i = 0; i < n; i++) {
            vector<int> newSubset = result[i];
            newSubset.push_back(num);
            result.push_back(newSubset);
        }
    }
    
    return result;
}

// Generate subsets with backtracking
void generateSubsets(vector<int>& nums, vector<int>& current, 
                    vector<vector<int>>& result, int index) {
    result.push_back(current);
    
    for (int i = index; i < nums.size(); i++) {
        current.push_back(nums[i]);
        generateSubsets(nums, current, result, i + 1);
        current.pop_back(); // Backtrack
    }
}
```

**Time Complexity:** O(2^n × n)  
**Space Complexity:** O(2^n)

**Common Problems:**
- Subsets
- Subsets II (with duplicates)
- Permutations
- Combination sum

---

## Pattern 11: Modified Binary Search

**When to Use:** Problems with sorted arrays, matrices, or search spaces where we need to find elements or boundaries.

**Key Concept:** Modify binary search logic based on problem requirements.

```cpp
// Standard binary search
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    
    return -1;
}

// Find first occurrence
int findFirst(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Continue searching left
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return result;
}

// Search in rotated sorted array
int searchRotated(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) return mid;
        
        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}
```

**Time Complexity:** O(log n)  
**Space Complexity:** O(1)

**Common Problems:**
- Binary search
- Search in rotated array
- Find peak element
- Search in 2D matrix

---

## Pattern 12: Bitwise XOR

**When to Use:** Problems involving finding unique elements, missing numbers, or bit manipulation.

**Key Concept:** XOR properties: a ^ a = 0, a ^ 0 = a, a ^ b = b ^ a

```cpp
// Find single number (all others appear twice)
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num; // XOR cancels duplicates
    }
    return result;
}

// Find two single numbers
vector<int> singleNumber2(vector<int>& nums) {
    int xorAll = 0;
    for (int num : nums) {
        xorAll ^= num;
    }
    
    // Find rightmost set bit
    int rightmostSetBit = xorAll & (-xorAll);
    
    int num1 = 0, num2 = 0;
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
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

**Common Problems:**
- Single number
- Two single numbers
- Missing number
- Complement of number

---

## Pattern 13: Top 'K' Elements

**When to Use:** Problems asking for top/smallest/frequent K elements.

**Key Concept:** Use heap (priority queue) to efficiently find K elements.

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Find K largest elements
vector<int> findKLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return result;
}

// Top K frequent elements
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, 
                   greater<pair<int, int>>> minHeap;
    
    for (auto& pair : freq) {
        minHeap.push({pair.second, pair.first});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    return result;
}
```

**Time Complexity:** O(n log k)  
**Space Complexity:** O(k)

**Common Problems:**
- K largest elements
- Top K frequent elements
- K closest points
- Frequency sort

---

## Pattern 14: K-way Merge

**When to Use:** Problems involving merging K sorted arrays or lists.

**Key Concept:** Use min-heap to efficiently merge K sorted sequences.

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto compare = [](ListNode* a, ListNode* b) {
        return a->val > b->val; // Min heap
    };
    
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
    
    // Push first node of each list
    for (ListNode* list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }
    
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();
        
        current->next = node;
        current = current->next;
        
        if (node->next) {
            minHeap.push(node->next);
        }
    }
    
    return dummy->next;
}
```

**Time Complexity:** O(n log k) where n is total elements, k is number of lists  
**Space Complexity:** O(k)

**Common Problems:**
- Merge K sorted lists
- Kth smallest in sorted matrix
- Smallest range covering elements

---

## Pattern 15: 0/1 Knapsack (Dynamic Programming)

**When to Use:** Optimization problems with constraints, subset problems, or resource allocation.

**Key Concept:** Use dynamic programming with memoization or tabulation to solve optimization problems.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 0/1 Knapsack - Maximum value with weight constraint
int knapsack01(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w], // Don't take
                    dp[i - 1][w - weights[i - 1]] + values[i - 1] // Take
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][capacity];
}

// Space optimized
int knapsack01Optimized(vector<int>& weights, vector<int>& values, int capacity) {
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < weights.size(); i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    
    return dp[capacity];
}
```

**Time Complexity:** O(n × capacity)  
**Space Complexity:** O(capacity) optimized

**Common Problems:**
- 0/1 Knapsack
- Partition equal subset sum
- Target sum
- Coin change

---

## Pattern 16: Topological Sort (Graph)

**When to Use:** Problems with dependencies, scheduling, or ordering tasks with prerequisites.

**Key Concept:** Find linear ordering of vertices such that for every edge (u, v), u comes before v.

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
private:
    int V;
    vector<list<int>> adj;
    
public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    vector<int> topologicalSort() {
        vector<int> inDegree(V, 0);
        
        // Calculate in-degrees
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                inDegree[neighbor]++;
            }
        }
        
        queue<int> q;
        // Add vertices with 0 in-degree
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            
            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return result;
    }
};
```

**Time Complexity:** O(V + E)  
**Space Complexity:** O(V)

**Common Problems:**
- Course schedule
- Alien dictionary
- Task scheduling
- Build order

---

## Pattern Recognition Guide

### How to Identify Which Pattern to Use?

1. **Sliding Window:** Subarray/substring problems, fixed/variable window
2. **Two Pointers:** Sorted arrays, pairs/triplets, opposite ends
3. **Fast & Slow:** Linked lists, cycles, middle element
4. **Merge Intervals:** Overlapping intervals, scheduling
5. **Cyclic Sort:** Arrays with numbers in range [1..n]
6. **In-place Reversal:** Reverse linked list without extra space
7. **Tree BFS:** Level-order traversal, shortest path
8. **Tree DFS:** Path problems, tree structure
9. **Two Heaps:** Median, smallest/largest in two parts
10. **Subsets:** Generate all combinations/permutations
11. **Binary Search:** Sorted arrays, search space reduction
12. **Bitwise XOR:** Unique elements, missing numbers
13. **Top K:** Heap problems, frequent/smallest/largest K
14. **K-way Merge:** Multiple sorted sequences
15. **0/1 Knapsack:** Optimization with constraints, DP
16. **Topological Sort:** Dependencies, ordering tasks

---

## Practice Strategy

1. **Learn the pattern** - Understand when and how to use it
2. **Solve basic problems** - Start with easy problems using the pattern
3. **Practice variations** - Solve medium/hard problems with pattern variations
4. **Recognize patterns** - Practice identifying which pattern to use
5. **Combine patterns** - Some problems use multiple patterns

---

## References

- [Several Coding Patterns Repository](https://github.com/Chanda-Abdul/Several-Coding-Patterns-for-Solving-Data-Structures-and-Algorithms-Problems-during-Interviews)
- [GeeksforGeeks - Sliding Window](https://www.geeksforgeeks.org/window-sliding-technique/)
- [GeeksforGeeks - Two Pointers](https://www.geeksforgeeks.org/two-pointer-technique/)
- [GeeksforGeeks - Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/)

