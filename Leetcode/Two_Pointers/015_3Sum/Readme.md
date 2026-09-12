### 15.3Sum

#### Solution Description

This is the basic problem of double pointer arithmetic, which must be mastered and implemented quickly and accurately.

#### Details to note

0. Be sure to sort first.  

1. To avoid duplication, move the left and right pointers over duplicates only after confirming that a set of solutions has been found. Do not skip duplicates before deciding whether the solution holds.  

```cpp
  if (nums[left]+nums[right]==sum)
  {
    record results;
    left++;
    right--;
    while (left<right && nums[left]==nums[left-1]) left++;
    while (left<right && nums[right]==nums[right+1]) right--;
  }
  ```

2. For the outermost loop, also determine one, expand the inner loop first, and then skip the outermost repetition.  

```cpp
 for (int a=0; a<nums.size(); a++)
 {
    //inner loop
    while (nums[a]==nums[a+1]) a++;
 }
```

> Approach #1: Two Pointer [Accepted - C++]
> Approach #2: Two Pointer [Accepted - Java]

[Leetcode Link](https://leetcode.com/problems/3sum)  
