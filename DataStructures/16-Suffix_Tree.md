### Suffix Tree

A **Suffix Tree** is a compressed trie containing all suffixes of a given string. It is one of the most powerful data structures for string processing, enabling very fast pattern matching and substring operations.

**Key Properties:**
- Contains all suffixes of a string in a compressed trie structure
- Each edge is labeled with a substring
- All suffixes end at leaf nodes
- Enables O(m) pattern searching where m is pattern length
- More space-efficient than storing all suffixes explicitly

### Suffix Tree Representation

**String:** "banana$" (with sentinel $)

**Suffix Tree:**
```
        (root)
       /  |  \
      a   b   n
     / \  |    \
    na$  na$  ana$
   /  \   |
  $   na$ na$
```

**All Suffixes:**
- banana$
- anana$
- nana$
- ana$
- na$
- a$
- $

### Basic Operations on Suffix Tree

#### 1. Building Suffix Tree

**Ukkonen's Algorithm (O(n)):**

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class SuffixTreeNode {
public:
    unordered_map<char, SuffixTreeNode*> children;
    int start;
    int* end;
    SuffixTreeNode* suffixLink;
    int suffixIndex;
    
    SuffixTreeNode(int start, int* end) 
        : start(start), end(end), suffixLink(nullptr), suffixIndex(-1) {}
};

class SuffixTree {
private:
    string text;
    SuffixTreeNode* root;
    SuffixTreeNode* lastNewNode;
    SuffixTreeNode* activeNode;
    int activeEdge;
    int activeLength;
    int remainingSuffixCount;
    int leafEnd;
    int* rootEnd;
    int* splitEnd;
    int size;
    
    SuffixTreeNode* newNode(int start, int* end) {
        SuffixTreeNode* node = new SuffixTreeNode(start, end);
        return node;
    }
    
    int edgeLength(SuffixTreeNode* n) {
        return *(n->end) - (n->start) + 1;
    }
    
    int walkDown(SuffixTreeNode* currNode) {
        if (activeLength >= edgeLength(currNode)) {
            activeEdge += edgeLength(currNode);
            activeLength -= edgeLength(currNode);
            activeNode = currNode;
            return 1;
        }
        return 0;
    }
    
    void extendSuffixTree(int pos) {
        leafEnd = pos;
        remainingSuffixCount++;
        lastNewNode = nullptr;
        
        while (remainingSuffixCount > 0) {
            if (activeLength == 0) {
                activeEdge = pos;
            }
            
            if (activeNode->children.find(text[activeEdge]) == 
                activeNode->children.end()) {
                activeNode->children[text[activeEdge]] = 
                    newNode(pos, &leafEnd);
                
                if (lastNewNode != nullptr) {
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = nullptr;
                }
            }
            else {
                SuffixTreeNode* next = activeNode->children[text[activeEdge]];
                
                if (walkDown(next)) {
                    continue;
                }
                
                if (text[next->start + activeLength] == text[pos]) {
                    if (lastNewNode != nullptr && activeNode != root) {
                        lastNewNode->suffixLink = activeNode;
                        lastNewNode = nullptr;
                    }
                    activeLength++;
                    break;
                }
                
                splitEnd = new int;
                *splitEnd = next->start + activeLength - 1;
                
                SuffixTreeNode* split = newNode(next->start, splitEnd);
                activeNode->children[text[activeEdge]] = split;
                
                split->children[text[pos]] = newNode(pos, &leafEnd);
                next->start += activeLength;
                split->children[text[next->start]] = next;
                
                if (lastNewNode != nullptr) {
                    lastNewNode->suffixLink = split;
                }
                
                lastNewNode = split;
            }
            
            remainingSuffixCount--;
            
            if (activeNode == root && activeLength > 0) {
                activeLength--;
                activeEdge = pos - remainingSuffixCount + 1;
            }
            else if (activeNode != root) {
                activeNode = activeNode->suffixLink;
            }
        }
    }
    
    void setSuffixIndexByDFS(SuffixTreeNode* n, int labelHeight) {
        if (n == nullptr) return;
        
        bool leaf = true;
        for (auto& child : n->children) {
            leaf = false;
            setSuffixIndexByDFS(child.second, 
                labelHeight + edgeLength(child.second));
        }
        
        if (leaf) {
            n->suffixIndex = size - labelHeight;
        }
    }
    
public:
    SuffixTree(string txt) {
        text = txt + "$";
        size = text.length();
        rootEnd = new int;
        *rootEnd = -1;
        
        root = newNode(-1, rootEnd);
        activeNode = root;
        activeEdge = -1;
        activeLength = 0;
        remainingSuffixCount = 0;
        leafEnd = -1;
        
        for (int i = 0; i < size; i++) {
            extendSuffixTree(i);
        }
        
        int labelHeight = 0;
        setSuffixIndexByDFS(root, labelHeight);
    }
    
    bool search(string pattern) {
        SuffixTreeNode* current = root;
        int i = 0;
        
        while (i < pattern.length()) {
            if (current->children.find(pattern[i]) == 
                current->children.end()) {
                return false;
            }
            
            SuffixTreeNode* child = current->children[pattern[i]];
            int edgeLen = edgeLength(child);
            
            for (int j = 0; j < edgeLen && i < pattern.length(); j++) {
                if (text[child->start + j] != pattern[i]) {
                    return false;
                }
                i++;
            }
            
            current = child;
        }
        
        return true;
    }
    
    void printSuffixes(SuffixTreeNode* node, string suffix = "") {
        if (node == nullptr) return;
        
        if (node->suffixIndex != -1) {
            cout << "Suffix " << node->suffixIndex << ": " 
                 << suffix << endl;
            return;
        }
        
        for (auto& child : node->children) {
            string edge = text.substr(child.second->start, 
                edgeLength(child.second));
            printSuffixes(child.second, suffix + edge);
        }
    }
    
    void printAllSuffixes() {
        printSuffixes(root);
    }
};

int main() {
    string text = "banana";
    SuffixTree st(text);
    
    cout << "All suffixes:" << endl;
    st.printAllSuffixes();
    
    string pattern = "ana";
    if (st.search(pattern)) {
        cout << "\nPattern '" << pattern << "' found!" << endl;
    }
    else {
        cout << "\nPattern '" << pattern << "' not found!" << endl;
    }
    
    return 0;
}
```

#### 2. Pattern Searching in Suffix Tree

**Time Complexity: O(m)** where m is pattern length

```cpp
bool searchPattern(SuffixTreeNode* root, string pattern, string text) {
    SuffixTreeNode* current = root;
    int i = 0;
    
    while (i < pattern.length()) {
        if (current->children.find(pattern[i]) == current->children.end()) {
            return false;
        }
        
        SuffixTreeNode* child = current->children[pattern[i]];
        int edgeLen = *(child->end) - child->start + 1;
        
        for (int j = 0; j < edgeLen && i < pattern.length(); j++) {
            if (text[child->start + j] != pattern[i]) {
                return false;
            }
            i++;
        }
        
        current = child;
    }
    
    return true;
}
```

#### 3. Finding Longest Repeated Substring

```cpp
string longestRepeatedSubstring(SuffixTreeNode* node, string text, 
                                int& maxLen, int& startIdx, 
                                string current = "") {
    if (node == nullptr) return "";
    
    if (node->suffixIndex == -1) { // Internal node
        for (auto& child : node->children) {
            string edge = text.substr(child.second->start, 
                edgeLength(child.second));
            string newCurrent = current + edge;
            
            int currentLen = newCurrent.length();
            if (currentLen > maxLen) {
                maxLen = currentLen;
                startIdx = child.second->start - current.length();
            }
            
            longestRepeatedSubstring(child.second, text, maxLen, 
                                   startIdx, newCurrent);
        }
    }
    
    return "";
}
```

### Time Complexity

| Operation | Time Complexity |
|-----------|----------------|
| Build (Ukkonen's) | O(n) |
| Pattern Search | O(m) |
| Longest Common Substring | O(n) |
| Space | O(n) |

### Space Complexity

- **Space Complexity:** O(n) for the tree structure
- **More efficient than storing all suffixes:** Compressed representation

### Advantages of Suffix Tree

1. **Fast pattern matching** - O(m) time complexity
2. **Linear construction** - O(n) with Ukkonen's algorithm
3. **Powerful operations** - supports many string operations efficiently
4. **Space efficient** - compressed trie structure
5. **Widely used** - in bioinformatics, text processing

### Disadvantages of Suffix Tree

1. **Complex implementation** - Ukkonen's algorithm is non-trivial
2. **Memory overhead** - pointers and edge labels
3. **Less intuitive** - harder to understand than arrays
4. **Construction complexity** - requires careful implementation

### Applications of Suffix Tree

1. **Pattern Matching:** Fast substring search
2. **Bioinformatics:** DNA sequence analysis, genome alignment
3. **Text Processing:** Longest common substring, repeated patterns
4. **Data Compression:** LZ77, LZ78 algorithms
5. **Search Engines:** Full-text indexing
6. **String Algorithms:** Longest palindromic substring, suffix automata

### Suffix Tree vs Suffix Array

| Feature | Suffix Tree | Suffix Array |
|---------|-------------|--------------|
| **Construction** | O(n) | O(n log n) |
| **Pattern Search** | O(m) | O(m log n) |
| **Space** | O(n) | O(n) |
| **Implementation** | Complex | Simpler |
| **Memory** | Higher overhead | Lower overhead |
| **Use Case** | Fast queries | Simpler alternative |

### References

- [GeeksforGeeks - Suffix Tree](https://www.geeksforgeeks.org/pattern-searching-using-suffix-tree/)
- [GeeksforGeeks - Ukkonen's Suffix Tree Construction](https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-1/)
