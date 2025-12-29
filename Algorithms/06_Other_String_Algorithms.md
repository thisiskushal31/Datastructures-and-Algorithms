# Other String Algorithms

**String Algorithms** are algorithms designed to solve problems involving strings (sequences of characters). This section covers advanced string algorithms beyond basic pattern searching.

**String Processing:** String algorithms are crucial for text processing, pattern matching, and data analysis. They involve operations like finding longest common substrings, palindromic substrings, string compression, and advanced pattern matching techniques. Understanding these algorithms is essential for solving real-world problems involving text data.

![String Algorithms Visualization](./assets/String_Algorithms_Visualization.png)

> **Image Credit:** [Wikipedia - Aho-Corasick Algorithm](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm)

### String Matching Algorithms

#### 1. Longest Common Substring

Find longest common substring between two strings.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string longestCommonSubstring(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0;
    int endIndex = 0;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i - 1;
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    
    return s1.substr(endIndex - maxLen + 1, maxLen);
}
```

**Time Complexity:** O(m × n)  
**Space Complexity:** O(m × n)

#### 2. Longest Palindromic Substring

Find longest palindromic substring (see Dynamic Programming section for DP solution).

```cpp
#include <iostream>
#include <string>
using namespace std;

string expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    string longest = "";
    
    for (int i = 0; i < s.length(); i++) {
        // Odd length palindromes
        string odd = expandAroundCenter(s, i, i);
        if (odd.length() > longest.length()) {
            longest = odd;
        }
        
        // Even length palindromes
        string even = expandAroundCenter(s, i, i + 1);
        if (even.length() > longest.length()) {
            longest = even;
        }
    }
    
    return longest;
}
```

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

#### 3. Manacher's Algorithm

Find longest palindromic substring in O(n) time.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    // Transform string: "abc" -> "^#a#b#c#$"
    string transformed = "^";
    for (char c : s) {
        transformed += "#";
        transformed += c;
    }
    transformed += "#$";
    
    int n = transformed.length();
    vector<int> P(n, 0);
    int center = 0, right = 0;
    int maxLen = 0, centerIndex = 0;
    
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;
        
        if (i < right) {
            P[i] = min(right - i, P[mirror]);
        }
        
        // Expand around center
        while (transformed[i + (1 + P[i])] == transformed[i - (1 + P[i])]) {
            P[i]++;
        }
        
        // Update center and right
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
        
        // Update longest palindrome
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

### String Transformation Algorithms

#### 1. Edit Distance (Levenshtein Distance)

Minimum operations to convert one string to another (see Dynamic Programming section).

#### 2. String Rotation

Check if one string is rotation of another.

```cpp
bool isRotation(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    
    string combined = s1 + s1;
    return combined.find(s2) != string::npos;
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

#### 3. Anagram Checking

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool areAnagrams(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    return s1 == s2;
}

// Using frequency array (more efficient)
bool areAnagrams(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    
    vector<int> count(26, 0);
    
    for (char c : s1) count[c - 'a']++;
    for (char c : s2) count[c - 'a']--;
    
    for (int c : count) {
        if (c != 0) return false;
    }
    
    return true;
}
```

**Time Complexity:** O(n) with frequency array, O(n log n) with sorting  
**Space Complexity:** O(1) with frequency array

### String Compression

#### Run-Length Encoding

```cpp
#include <iostream>
#include <string>
using namespace std;

string runLengthEncode(string s) {
    if (s.empty()) return "";
    
    string encoded = "";
    int count = 1;
    
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        }
        else {
            encoded += s[i - 1] + to_string(count);
            count = 1;
        }
    }
    
    encoded += s[s.length() - 1] + to_string(count);
    return encoded;
}

string runLengthDecode(string encoded) {
    string decoded = "";
    
    for (int i = 0; i < encoded.length(); i += 2) {
        char ch = encoded[i];
        int count = encoded[i + 1] - '0';
        
        for (int j = 0; j < count; j++) {
            decoded += ch;
        }
    }
    
    return decoded;
}
```

### Advanced String Problems (Striver's A2Z - 9 Problems)

1. Longest Common Substring
2. Longest Palindromic Substring
3. Edit Distance
4. String Rotation
5. Anagram Groups
6. Valid Anagram
7. Group Anagrams
8. Longest Substring Without Repeating Characters
9. Minimum Window Substring

### Time Complexity

| Algorithm | Time Complexity |
|-----------|----------------|
| Longest Common Substring | O(m × n) |
| Longest Palindromic Substring (Expand) | O(n²) |
| Manacher's Algorithm | O(n) |
| Edit Distance | O(m × n) |
| Anagram Check | O(n) |
| String Rotation | O(n) |

### Space Complexity

- **Space Complexity:** O(1) to O(m × n) depending on algorithm
- **Auxiliary Space:** O(1) to O(n)

### Applications

1. **Text Processing:** Search, replace, format
2. **Bioinformatics:** DNA/RNA sequence analysis
3. **Data Compression:** String encoding
4. **Plagiarism Detection:** Similarity checking
5. **Search Engines:** Text indexing

### References

- [GeeksforGeeks - String Algorithms](https://www.geeksforgeeks.org/string-data-structure/)
- [GeeksforGeeks - Manacher's Algorithm](https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/)
