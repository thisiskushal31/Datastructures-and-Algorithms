### 88. Merge Sorted Array 

#### Solution Description

Start filling in descending order from the m+n-1th position of nums1, and perform merge sort.

#### Algorithm: Double Pointer

The main logic behind this approach is to start filling the nums1 array from the back. Let's keep a pointer p1 at m-1 in nums1 and p2 at n-1 in nums2, and I at n+m-1;(nums1) compare values at p1 and p2 put the larger value at i and decrement the respective indexes.  

```cpp
int tail1 = m - 1, tail2 = n - 1, finished = m + n - 1;
while (tail1 >= 0 && tail2 >= 0) {
    nums1[finished--] = (nums1[tail1] > nums2[tail2]) ? nums1[tail1--] : nums2[tail2--];
}

while (tail2 >= 0) { //only need to combine with remaining nums2, if any
    nums1[finished--] = nums2[tail2--];
}
```

> Approach #1: Two Pointers [Accepted - C++]
> Approach #2: Two Pointers [Accepted - Java]

[Leetcode Link](https://leetcode.com/problems/merge-sorted-array)

[Best Leetcode Solution](https://leetcode.com/problems/merge-sorted-array/discuss/1189409/My-Java-Solution)