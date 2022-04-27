### 075.Sort-Colors

The difficulty lies in how to achieve in-page.The basic idea is to set three pointers:     

```cpp
int left=0;
int mid=0;
int right=nums.size()-1;
```  

Traversing the MID pointer, when encount ering No. 2 ball, exchange with the Right pointer; when encountering No. 1, continue to move forward; when you reach the No. 0 ball, you exchange with the Left pointer.      
The difficulty of understanding is:     

```cpp
if (nums[mid]==0)
{
  swap(nums[left],nums[mid]);
  left++;
  mid++;
}
```

Because the initial position of the LEFT and the MID, there is an asynchronous only because of the appearance of No. 1.Therefore, the interval between these two pointers will always be only No. 1, so when left and MID are exchanged, the Left pointer will pass to MID to No. 1 instead of No. 0.     

> Solution 1: Two Pointers[Accepted -- C++]      
> Solution 2: One Pointer[Accepted -- Java]      

[Leetcode Link](https://leetcode.com/problems/sort-colors)

[Leetcode Solution](https://leetcode.com/problems/sort-colors/discuss/26549/Java-solution-both-2-pass-and-1-pass) -- Java          
[Leetcode Solution](https://leetcode.com/problems/sort-colors/discuss/1408321/3-solutions-from-brute-force-to-optimization-or-c%2B%2B-solution) -- C++        