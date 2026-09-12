// Approach #1: Binary Search

class Solution {
public:
    int mySqrt(int x) {
        if (x == 1)
        {
            return 1;
        }
        long long int i = 1, j = x / 2, mid;
        while (j > i)
        {
            mid = i + (j - i) / 2;
            long long int ans = mid * mid;
            if (ans == x)
            {
                return mid;
            }
            else if (ans > x)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        if (j * j > x)
        {
            return j - 1;
        }
        return j;
    }
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)