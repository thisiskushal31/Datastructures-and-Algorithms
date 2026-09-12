### 69. Sqrt(x)

#### Solution Description

Here Key Idea to use Divide and Conquer to solve this problem and also in order to achieve O(logn) time complexity.

#### Algorithm Description

We want to find a square root of a number X and return the floor(ans) means we want to return its integer part only so we need to find a number mid such that *mid*mid == X* to find such a number mid we use binary search if we are X is not a perfect square then we return number such that floor(sqrt(X)) is equal to that number.

``` cpp
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
```

> Approach #1: Binary Search: Divide & Conquer  [Accepted - C++]
> Approach #2: Newton Solution  [Accepted - Java]
> Approach #3: Binary Search: Divide & Conquer  [Accepted - Java]

[Leetcode Link](https://leetcode.com/problems/sqrtx/)