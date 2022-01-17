// Problem: https://leetcode.com/problems/sqrtx/

/*
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer 
part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Example 1:
Input: x = 4
Output: 2

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
*/

/*
** Approach 01
We want to find a square root of a number X 
and return the floor(ans) means we want to return its integer part only
so we need to find a number mid such that mid*mid == X
to find such a number mid we use binary search    
if we are X is not a perfect square then we return number 
            such that floor(sqrt(X)) is equal; to that number
*/

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

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sqrt(x).
// Memory Usage: 6 MB, less than 24.67% of C++ online submissions for Sqrt(x)

/*
** Approach 02 (JAVA CODE)
*/

class Solution {
    public int mySqrt(int x) {
        long ans = 1;
     
        while (ans * ans <= x) {
            ++ans;
        }
        
        return (int) ans - 1;
    }
}

// Runtime: 18 ms, faster than 7.76% of Java online submissions for Sqrt(x).
// Memory Usage: 36 MB, less than 66.92% of Java online submissions for Sqrt(x).