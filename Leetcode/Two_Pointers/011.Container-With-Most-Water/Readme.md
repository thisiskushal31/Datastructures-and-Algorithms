### 11. Container With Most Water 

#### Solution Description:

The key idea here is that for any container, the water it could contain is determined by the shorter height. Try candidate from the far left and far right. Always move the shorter pointer to the center.

#### Algorithm: Double pointer

Let the left pointer point to 0 and the right pointer point to height.size()-1. Every time I consider if the horizontal distance is reduced by 1, should I choose to move the left pointer or the right pointer, or to examine both?

In fact, it is only necessary to move the shorter board of height[left] and height[right], so that it is possible to increase the total area. Otherwise moving the taller board won't make the result any better because the area is limited by the shorter board.

```cpp
if (height[left]>=height[right])
   right--;
else
   left++;
```

> Approach #0: Brute force [TimeOut - Java]
> Approach #1: Double Pointer [Accepted - Java]
> Approach #2: Double Pointer [Accepted - C++]

[Leetcode Link](https://leetcode.com/problems/container-with-most-water)
