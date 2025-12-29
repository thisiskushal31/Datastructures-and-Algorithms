# DSA Patterns Identification Cheatsheet

**Quick Reference Guide** for identifying which coding pattern to use based on problem keywords and descriptions.

> **Pro Tip:** Recognizing patterns quickly during coding interviews is key to solving problems efficiently. This cheatsheet helps you identify the right pattern based on keywords in the problem statement.

![DSA Patterns Cheatsheet](https://postimg.cc/YhfSrL42)

---

## How to Use This Cheatsheet

When reading a problem statement, look for these **keywords** to quickly identify which pattern to apply:

---

## 🔍 Binary Search

**Keywords to Look For:**
- `sorted`
- `search`
- `left/right`
- `log(n)`
- `upper/lower bound`
- `first/last occurrence`

**When to Use:**
- Array/list is sorted
- Need to find element or boundary
- Time complexity hint mentions O(log n)
- Searching in sorted matrix

**Example Problems:**
- Search in rotated sorted array
- Find first/last position of element
- Search in 2D matrix
- Find peak element

---

## 🌳 Depth-First Search (DFS)

**Keywords to Look For:**
- `recursion`
- `backtrack`
- `stack`
- `tree/graph`
- `path`
- `explore deeply`

**When to Use:**
- Tree/graph traversal
- Path problems
- Exploring all possibilities
- Need to go deep before backtracking

**Example Problems:**
- Path sum
- Maximum depth
- Same tree
- Number of islands

---

## 🪟 Sliding Window

**Keywords to Look For:**
- `subarray`
- `contiguous`
- `window size`
- `sum/max/min in range`
- `fixed/variable window`
- `consecutive elements`

**When to Use:**
- Subarray/substring problems
- Fixed or variable window size
- Need to find sum/max/min in range
- Consecutive elements

**Example Problems:**
- Maximum sum subarray of size K
- Longest substring with K distinct characters
- Minimum window substring
- Average of all subarrays

---

## 👉 Two Pointers

**Keywords to Look For:**
- `left and right`
- `sorted array`
- `move inward`
- `reverse in-place`
- `pair sum`
- `meet in middle`

**When to Use:**
- Sorted array problems
- Finding pairs/triplets
- In-place operations
- Opposite ends approach

**Example Problems:**
- Two sum in sorted array
- Remove duplicates
- Squaring sorted array
- Triplets with target sum

---

## 🐢 Fast & Slow Pointers (Hare & Tortoise)

**Keywords to Look For:**
- `cycle detection`
- `loop`
- `find middle`
- `linked list`
- `tortoise hare`
- `detect loop start`

**When to Use:**
- Linked list problems
- Cycle detection
- Finding middle element
- Two pointers at different speeds

**Example Problems:**
- Detect cycle in linked list
- Find middle of linked list
- Kth node from end
- Palindrome linked list

---

## 📊 Breadth-First Search (BFS)

**Keywords to Look For:**
- `queue`
- `shortest path`
- `level order`
- `tree/graph`
- `traverse layers`
- `neighbors`

**When to Use:**
- Level-by-level traversal
- Shortest path problems
- Tree/graph traversal
- Need to process all neighbors

**Example Problems:**
- Level-order traversal
- Zigzag traversal
- Right side view
- Shortest path in graph

---

## 🔄 Backtracking

**Keywords to Look For:**
- `combinations`
- `permutations`
- `all solutions`
- `recursive`
- `choices/decisions`
- `undo move`

**When to Use:**
- Generate all combinations/permutations
- Constraint satisfaction
- Need to explore all possibilities
- Can backtrack from invalid states

**Example Problems:**
- N-Queens
- Sudoku solver
- Generate parentheses
- Combination sum
- Permutations

---

## 💾 Dynamic Programming

**Keywords to Look For:**
- `subproblem`
- `overlapping`
- `memoization`
- `optimal`
- `cache`
- `state transition`

**When to Use:**
- Optimization problems
- Overlapping subproblems
- Optimal substructure
- Can cache results

**Example Problems:**
- 0/1 Knapsack
- Longest common subsequence
- Edit distance
- Coin change
- Climbing stairs

---

## 🎯 Greedy

**Keywords to Look For:**
- `always best choice`
- `locally optimal`
- `sorting`
- `intervals`
- `maximize/minimize`
- `no future change`

**When to Use:**
- Optimization problems
- Local optimal leads to global optimal
- Interval problems
- Scheduling problems

**Example Problems:**
- Activity selection
- Fractional knapsack
- Minimum spanning tree
- Job sequencing
- Meeting rooms

---

## 🗂️ Hashing/Hash Table

**Keywords to Look For:**
- `hashmap`
- `lookup`
- `frequency`
- `set`
- `collisions`
- `constant time`

**When to Use:**
- Need O(1) lookup
- Frequency counting
- Duplicate detection
- Set operations

**Example Problems:**
- Two sum
- Group anagrams
- Longest substring without repeating
- Top K frequent elements

---

## 🔗 Union Find (Disjoint Set)

**Keywords to Look For:**
- `connected components`
- `group`
- `parent/leader`
- `path compression`
- `merge sets`
- `cycle detection`

**When to Use:**
- Connected components
- Grouping elements
- Cycle detection in undirected graph
- Dynamic connectivity

**Example Problems:**
- Number of provinces
- Redundant connection
- Friend circles
- Accounts merge

---

## 📋 Topological Sort

**Keywords to Look For:**
- `directed acyclic graph`
- `course schedule`
- `dependency`
- `in-degree`
- `order`
- `build sequence`

**When to Use:**
- Dependency ordering
- Prerequisites
- Build order
- Directed acyclic graph

**Example Problems:**
- Course schedule
- Alien dictionary
- Task scheduling
- Build order

---

## 📚 Trie

**Keywords to Look For:**
- `prefix`
- `autocomplete`
- `startsWith`
- `dictionary`
- `string search`
- `character node`

**When to Use:**
- Prefix matching
- String search
- Autocomplete
- Dictionary problems

**Example Problems:**
- Implement Trie
- Word search II
- Longest common prefix
- Design search autocomplete

---

## ⛰️ Heap / Priority Queue

**Keywords to Look For:**
- `top k`
- `min/max`
- `extract`
- `insert`
- `dynamic median`
- `scheduling`

**When to Use:**
- Top K elements
- Min/max operations
- Median finding
- Priority-based processing

**Example Problems:**
- K largest elements
- Top K frequent elements
- Find median from data stream
- Merge K sorted lists

---

## Pattern Recognition Flowchart

```
Is the array/list sorted?
├─ YES → Binary Search or Two Pointers
└─ NO → Continue...

Is it a tree/graph problem?
├─ YES → DFS or BFS
└─ NO → Continue...

Is it a subarray/substring problem?
├─ YES → Sliding Window
└─ NO → Continue...

Is it a linked list problem?
├─ YES → Fast & Slow Pointers or Two Pointers
└─ NO → Continue...

Need all combinations/permutations?
├─ YES → Backtracking
└─ NO → Continue...

Optimization with overlapping subproblems?
├─ YES → Dynamic Programming
└─ NO → Continue...

Local optimal → Global optimal?
├─ YES → Greedy
└─ NO → Continue...

Need O(1) lookup?
├─ YES → Hashing
└─ NO → Check other patterns...
```

---

## Quick Decision Matrix

| Problem Type | Primary Pattern | Secondary Pattern |
|--------------|----------------|-------------------|
| Sorted array search | Binary Search | Two Pointers |
| Subarray/substring | Sliding Window | Two Pointers |
| Tree traversal | DFS / BFS | - |
| Linked list | Fast & Slow / Two Pointers | - |
| All combinations | Backtracking | DFS |
| Optimization | Dynamic Programming | Greedy |
| Top K elements | Heap | Quick Select |
| String prefix | Trie | Hashing |
| Dependencies | Topological Sort | DFS |
| Connected components | Union Find | DFS/BFS |

---

## Interview Tips

1. **Read the problem carefully** - Identify keywords first
2. **Check constraints** - They often hint at the pattern
3. **Look at examples** - Visualize the pattern
4. **Time complexity hints** - O(log n) → Binary Search, O(n) → Sliding Window/Two Pointers
5. **Data structure hints** - Sorted → Binary Search, Tree → DFS/BFS
6. **Problem category** - Array → Sliding/Two Pointers, Graph → DFS/BFS/Topological

---

## Practice Strategy

1. **Memorize keywords** - Know which keywords map to which pattern
2. **Practice pattern recognition** - Read problems and identify patterns without solving
3. **Solve by pattern** - Group problems by pattern type
4. **Time yourself** - Pattern recognition should be < 30 seconds
5. **Review mistakes** - Note which patterns you missed

---

## Additional Resources

- [Coding Patterns Guide](./Coding_Patterns.md) - Detailed pattern explanations with code
- [Logic Building](./../Algorithms/00_Logic_Building.md) - Problem-solving fundamentals
- [GeeksforGeeks - Pattern Searching](https://www.geeksforgeeks.org/algorithms-gq/pattern-searching/)

---

## Reference

**Image Source:** [DSA Patterns Cheatsheet](https://postimg.cc/YhfSrL42)

**Note:** This cheatsheet is designed to help you quickly identify patterns during coding interviews. Practice recognizing these keywords in problem statements to improve your problem-solving speed.

---

## Pattern Priority (When Multiple Patterns Apply)

1. **Check constraints first** - They often eliminate patterns
2. **Time complexity requirement** - O(log n) → Binary Search, O(n) → Sliding/Two Pointers
3. **Data structure** - Tree → DFS/BFS, Array → Sliding/Two Pointers
4. **Problem type** - Optimization → DP/Greedy, Search → Binary Search
5. **Keywords** - Use this cheatsheet as final check

---

**Remember:** Pattern recognition is a skill that improves with practice. Use this cheatsheet regularly while solving problems to build pattern recognition muscle memory!

