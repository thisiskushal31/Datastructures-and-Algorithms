// Approach #2: Newton Solution

class Solution {
    public int mySqrt(int x) {
        long ans = 1;
     
        while (ans * ans <= x) {
            ++ans;
        }
        
        return (int) ans - 1;
    }
}

// Time Complexity: O(log(x))
// Space Complexity: O(1)

// Approach #3: Binary Search

class Solution {
    public int mySqrt(int x) {
        if (x == 0) return 0;
        int start = 1, end = x;
        while (start < end) { 
            int mid = start + (end - start) / 2;
            if (mid <= x / mid && (mid + 1) > x / (mid + 1))// Found the result
                return mid; 
            else if (mid > x / mid)// Keep checking the left part
                end = mid;
            else
                start = mid + 1;// Keep checking the right part
        }
        return start;
    }
}

// Time Complexity: O(log(n))
// Space Complexity: O(1)