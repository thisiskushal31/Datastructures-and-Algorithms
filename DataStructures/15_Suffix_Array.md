### Suffix Array

A **Suffix Array** is a sorted array of all suffixes of a given string. It is a space-efficient alternative to Suffix Tree and is widely used in string processing algorithms.

**Key Properties:**
- Contains all suffixes of a string in lexicographically sorted order
- More space-efficient than Suffix Tree (O(n) vs O(n) but simpler)
- Enables efficient string searching, pattern matching, and substring operations
- Used in bioinformatics, text compression, and search engines

### Suffix Array Representation

**String:** "banana"

**All Suffixes:**
```
0: banana
1: anana
2: nana
3: ana
4: na
5: a
```

**Suffix Array (sorted):**
```
Index: 5  3  1  0  4  2
Suffix: a  ana  anana  banana  na  nana
```

**Suffix Array:** `[5, 3, 1, 0, 4, 2]`

### Basic Operations on Suffix Array

#### 1. Building Suffix Array

**Naive Approach (O(n² log n)):**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> buildSuffixArrayNaive(string s) {
    int n = s.length();
    vector<pair<string, int>> suffixes;
    
    // Generate all suffixes with their indices
    for (int i = 0; i < n; i++) {
        suffixes.push_back({s.substr(i), i});
    }
    
    // Sort suffixes lexicographically
    sort(suffixes.begin(), suffixes.end());
    
    // Extract indices
    vector<int> suffixArray;
    for (auto& p : suffixes) {
        suffixArray.push_back(p.second);
    }
    
    return suffixArray;
}
```

**Efficient Approach (O(n log² n)) using Doubling:**

```cpp
vector<int> buildSuffixArray(string s) {
    int n = s.length();
    vector<int> suffixArray(n), rank(n), tempRank(n);
    
    // Initialize with single characters
    for (int i = 0; i < n; i++) {
        suffixArray[i] = i;
        rank[i] = s[i];
    }
    
    // Sort by first character
    sort(suffixArray.begin(), suffixArray.end(), 
         [&](int a, int b) { return s[a] < s[b]; });
    
    // Doubling method
    for (int k = 1; k < n; k *= 2) {
        // Update rank
        tempRank[suffixArray[0]] = 0;
        int r = 0;
        for (int i = 1; i < n; i++) {
            int prev = suffixArray[i-1];
            int curr = suffixArray[i];
            
            if (rank[prev] != rank[curr] || 
                (prev + k < n ? rank[prev + k] : -1) != 
                (curr + k < n ? rank[curr + k] : -1)) {
                r++;
            }
            tempRank[curr] = r;
        }
        rank = tempRank;
        
        // Sort by rank
        vector<vector<int>> buckets(n+1);
        for (int i = 0; i < n; i++) {
            int key = (suffixArray[i] + k < n) ? rank[suffixArray[i] + k] : -1;
            buckets[key + 1].push_back(suffixArray[i]);
        }
        
        suffixArray.clear();
        for (auto& bucket : buckets) {
            for (int idx : bucket) {
                suffixArray.push_back(idx);
            }
        }
    }
    
    return suffixArray;
}
```

#### 2. Building LCP Array (Longest Common Prefix)

LCP array stores the length of the longest common prefix between consecutive suffixes in the suffix array.

```cpp
vector<int> buildLCPArray(string s, vector<int>& suffixArray) {
    int n = s.length();
    vector<int> lcp(n), invSuffix(n);
    
    // Build inverse suffix array
    for (int i = 0; i < n; i++) {
        invSuffix[suffixArray[i]] = i;
    }
    
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (invSuffix[i] == n - 1) {
            k = 0;
            continue;
        }
        
        int j = suffixArray[invSuffix[i] + 1];
        
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
            k++;
        }
        
        lcp[invSuffix[i]] = k;
        
        if (k > 0) k--;
    }
    
    return lcp;
}
```

#### 3. Pattern Searching in Suffix Array

**Binary Search (O(m log n)):**

```cpp
bool searchPattern(string text, vector<int>& suffixArray, string pattern) {
    int n = text.length();
    int m = pattern.length();
    
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        string suffix = text.substr(suffixArray[mid]);
        
        int cmp = pattern.compare(0, m, suffix, 0, min(m, (int)suffix.length()));
        
        if (cmp == 0) {
            return true; // Pattern found
        }
        else if (cmp < 0) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return false;
}
```

#### 4. Finding Longest Repeated Substring

```cpp
string longestRepeatedSubstring(string s, vector<int>& suffixArray, vector<int>& lcp) {
    int n = s.length();
    int maxLen = 0;
    int startIdx = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (lcp[i] > maxLen) {
            maxLen = lcp[i];
            startIdx = suffixArray[i];
        }
    }
    
    return (maxLen > 0) ? s.substr(startIdx, maxLen) : "";
}
```

### Time Complexity

| Operation | Time Complexity |
|-----------|----------------|
| Build (Naive) | O(n² log n) |
| Build (Efficient) | O(n log² n) or O(n log n) |
| Pattern Search | O(m log n) |
| LCP Array | O(n) |
| Space | O(n) |

### Space Complexity

- **Space Complexity:** O(n) for suffix array and auxiliary arrays
- **More efficient than Suffix Tree:** Simpler structure, easier to implement

### Advantages of Suffix Array

1. **Space efficient** - O(n) space, simpler than Suffix Tree
2. **Fast pattern matching** - O(m log n) with binary search
3. **Easy to implement** - simpler than Suffix Tree
4. **Wide applications** - string processing, bioinformatics
5. **Cache friendly** - array-based structure

### Disadvantages of Suffix Array

1. **Slower than Suffix Tree** - for some operations
2. **Construction time** - O(n log n) or O(n log² n)
3. **Less intuitive** - harder to visualize than trees

### Applications of Suffix Array

1. **String Matching:** Pattern searching in text
2. **Bioinformatics:** DNA sequence analysis, genome alignment
3. **Text Compression:** Burrows-Wheeler Transform (BWT)
4. **Search Engines:** Full-text indexing
5. **Data Compression:** LZ77, LZ78 algorithms
6. **Longest Common Substring:** Finding repeated patterns

### Suffix Array vs Suffix Tree

| Feature | Suffix Array | Suffix Tree |
|---------|-------------|-------------|
| **Space** | O(n) | O(n) |
| **Construction** | O(n log n) | O(n) |
| **Pattern Search** | O(m log n) | O(m) |
| **Implementation** | Simpler | More complex |
| **Memory** | Lower overhead | Higher overhead |

### References

- [GeeksforGeeks - Suffix Array](https://www.geeksforgeeks.org/suffix-array-set-1-introduction/)
- [GeeksforGeeks - Suffix Array Construction](https://www.geeksforgeeks.org/suffix-array-set-2-a-nlognlogn-algorithm/)
