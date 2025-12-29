### K Dimensional Tree (KD-Tree)

A **K-Dimensional Tree (KD-Tree)** is a space-partitioning data structure for organizing points in a k-dimensional space. It is a binary tree where each node represents a k-dimensional point and splits the space along one of the k dimensions.

**Key Properties:**
- Each node splits space along one dimension
- Alternates dimensions at each level (0, 1, 2, ..., k-1, 0, ...)
- Efficient for range searches and nearest neighbor queries
- Used in computational geometry and spatial databases

**Dimensions:** The tree alternates which dimension to split on at each level.

### KD-Tree Representation

**2D Points:** (3,6), (17,15), (13,15), (6,12), (9,1), (2,7), (10,19)

**KD-Tree (2D):**
```
        (7,2) [split on x]
       /      \
   (5,4)      (9,6) [split on y]
   [y]        /    \
  /  \    (8,1)   (10,11)
(2,3) (4,7) [x]    [x]
```

**Example:** Root splits on x-axis, children split on y-axis, and so on.

### Basic Operations on KD-Tree

#### 1. KD-Tree - Building

Build KD-Tree from points:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

struct Point {
    vector<int> coords;
    
    Point(vector<int> c) : coords(c) {}
    
    int get(int dim) {
        return coords[dim];
    }
    
    int size() {
        return coords.size();
    }
};

class KDNode {
public:
    Point point;
    KDNode* left;
    KDNode* right;
    int dimension;
    
    KDNode(Point p, int dim) 
        : point(p), left(nullptr), right(nullptr), dimension(dim) {}
};

class KDTree {
private:
    KDNode* root;
    int k; // Number of dimensions
    
    // Find median point along dimension
    Point findMedian(vector<Point>& points, int dim) {
        sort(points.begin(), points.end(), 
             [dim](const Point& a, const Point& b) {
                 return a.coords[dim] < b.coords[dim];
             });
        return points[points.size() / 2];
    }
    
    // Build KD-Tree recursively
    KDNode* buildTree(vector<Point>& points, int depth) {
        if (points.empty()) return nullptr;
        
        int dim = depth % k;
        
        // Find median along current dimension
        Point median = findMedian(points, dim);
        KDNode* node = new KDNode(median, dim);
        
        // Split points
        vector<Point> leftPoints, rightPoints;
        for (const Point& p : points) {
            if (p.coords[dim] < median.coords[dim]) {
                leftPoints.push_back(p);
            }
            else if (p.coords[dim] > median.coords[dim]) {
                rightPoints.push_back(p);
            }
        }
        
        // Recursively build left and right subtrees
        node->left = buildTree(leftPoints, depth + 1);
        node->right = buildTree(rightPoints, depth + 1);
        
        return node;
    }
    
    // Calculate distance between two points
    double distance(const Point& a, const Point& b) {
        double dist = 0.0;
        for (int i = 0; i < k; i++) {
            dist += pow(a.coords[i] - b.coords[i], 2);
        }
        return sqrt(dist);
    }
    
    // Nearest neighbor search
    void nearestNeighborUtil(KDNode* node, const Point& target, 
                            Point& best, double& bestDist) {
        if (node == nullptr) return;
        
        double dist = distance(node->point, target);
        if (dist < bestDist) {
            bestDist = dist;
            best = node->point;
        }
        
        int dim = node->dimension;
        double diff = target.coords[dim] - node->point.coords[dim];
        
        KDNode* near = (diff < 0) ? node->left : node->right;
        KDNode* far = (diff < 0) ? node->right : node->left;
        
        if (near != nullptr) {
            nearestNeighborUtil(near, target, best, bestDist);
        }
        
        if (far != nullptr && abs(diff) < bestDist) {
            nearestNeighborUtil(far, target, best, bestDist);
        }
    }
    
public:
    KDTree(vector<Point> points, int dimensions) : k(dimensions) {
        root = buildTree(points, 0);
    }
    
    // Insert point
    void insert(Point point) {
        root = insertUtil(root, point, 0);
    }
    
private:
    KDNode* insertUtil(KDNode* node, Point point, int depth) {
        if (node == nullptr) {
            return new KDNode(point, depth % k);
        }
        
        int dim = node->dimension;
        if (point.coords[dim] < node->point.coords[dim]) {
            node->left = insertUtil(node->left, point, depth + 1);
        }
        else {
            node->right = insertUtil(node->right, point, depth + 1);
        }
        
        return node;
    }
    
public:
    // Search for point
    bool search(Point target) {
        return searchUtil(root, target, 0);
    }
    
private:
    bool searchUtil(KDNode* node, Point target, int depth) {
        if (node == nullptr) return false;
        
        bool match = true;
        for (int i = 0; i < k; i++) {
            if (node->point.coords[i] != target.coords[i]) {
                match = false;
                break;
            }
        }
        if (match) return true;
        
        int dim = node->dimension;
        if (target.coords[dim] < node->point.coords[dim]) {
            return searchUtil(node->left, target, depth + 1);
        }
        else {
            return searchUtil(node->right, target, depth + 1);
        }
    }
    
public:
    // Find nearest neighbor
    Point nearestNeighbor(Point target) {
        Point best = root->point;
        double bestDist = distance(root->point, target);
        nearestNeighborUtil(root, target, best, bestDist);
        return best;
    }
    
    // Range search
    vector<Point> rangeSearch(Point min, Point max) {
        vector<Point> result;
        rangeSearchUtil(root, min, max, result);
        return result;
    }
    
private:
    void rangeSearchUtil(KDNode* node, Point min, Point max, 
                        vector<Point>& result) {
        if (node == nullptr) return;
        
        bool inRange = true;
        for (int i = 0; i < k; i++) {
            if (node->point.coords[i] < min.coords[i] || 
                node->point.coords[i] > max.coords[i]) {
                inRange = false;
                break;
            }
        }
        
        if (inRange) {
            result.push_back(node->point);
        }
        
        int dim = node->dimension;
        if (min.coords[dim] <= node->point.coords[dim]) {
            rangeSearchUtil(node->left, min, max, result);
        }
        if (max.coords[dim] >= node->point.coords[dim]) {
            rangeSearchUtil(node->right, min, max, result);
        }
    }
};

int main() {
    vector<Point> points = {
        Point({3, 6}), Point({17, 15}), Point({13, 15}),
        Point({6, 12}), Point({9, 1}), Point({2, 7}), Point({10, 19})
    };
    
    KDTree tree(points, 2); // 2D tree
    
    Point target({9, 2});
    Point nearest = tree.nearestNeighbor(target);
    
    cout << "Nearest neighbor to (9,2): (";
    for (int i = 0; i < nearest.size(); i++) {
        cout << nearest.coords[i];
        if (i < nearest.size() - 1) cout << ", ";
    }
    cout << ")" << endl;
    
    return 0;
}
```

### Time Complexity

| Operation | Average Case | Worst Case |
|-----------|--------------|------------|
| Build      | O(n log n)   | O(n log² n) |
| Search     | O(log n)     | O(n)       |
| Insert     | O(log n)     | O(n)       |
| Nearest Neighbor | O(log n) | O(n)       |
| Range Search | O(√n + k) | O(n)       |

**Note:** k is the number of points in the range, n is total points.

### Space Complexity

- **Space Complexity:** O(n) for storing n points
- **Auxiliary Space:** O(log n) for recursion stack

### Advantages of KD-Tree

1. **Efficient nearest neighbor** - O(log n) average case
2. **Range queries** - efficient spatial searches
3. **Multi-dimensional** - works for any k dimensions
4. **Simple structure** - binary tree extension
5. **Widely used** - in computational geometry

### Disadvantages of KD-Tree

1. **Worst case O(n)** - can degrade for high dimensions
2. **Curse of dimensionality** - inefficient for high k (>10)
3. **Not balanced** - can become skewed
4. **Static construction** - better when built from all points

### Applications of KD-Tree

1. **Nearest Neighbor Search:** Finding closest points
2. **Computer Graphics:** Ray tracing, collision detection
3. **Machine Learning:** KNN algorithm, clustering
4. **Geographic Information Systems (GIS):** Spatial queries
5. **Image Processing:** Feature matching, image search
6. **Robotics:** Path planning, obstacle avoidance

### KD-Tree vs Other Spatial Structures

| Feature | KD-Tree | R-Tree | Quad-Tree |
|---------|---------|--------|-----------|
| **Dimensions** | Any k | 2D/3D | 2D |
| **Structure** | Binary tree | Multi-way | 4-way |
| **Nearest Neighbor** | Good | Moderate | Good |
| **Range Query** | Good | Excellent | Good |
| **High Dimensions** | Poor | Poor | N/A |

### References

- [GeeksforGeeks - KD Tree](https://www.geeksforgeeks.org/k-dimensional-tree/)
- [GeeksforGeeks - KD Tree Nearest Neighbor](https://www.geeksforgeeks.org/k-dimensional-tree-set-2-find-minimum/)
