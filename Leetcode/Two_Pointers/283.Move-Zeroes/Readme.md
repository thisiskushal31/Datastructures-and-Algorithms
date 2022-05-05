### 283.Move-Zeroes

Think about how to implement it with in-page.  
The basic idea is to use double pointers.      
Plan 1: Let the right pointer be thrown to the left when you encounter a non -zero number;   
Scheme 2: Let the right pointer meet 0 and throw it to the right.     

#### plan 1：

```cpp
int left=0;
int right=0;
```

a encounter nums[right]==How should I operate when 0? Since the non -0 is thrown to the left, then the right pointer continues to move forward when it encounters 0.

b when you encounter Nums [Right]! = How should you operate when 0?     
First, throw this number on the left:      

```cpp
swap(nums[left],nums[right])
```

Then, nums [left] is no longer 0, so you can rest assured left++.    
What about the right pointer?The key point is here. If left! = Right, the left pointer must point to 0, because the reason for the gap between the left and right pointers is because there is a 0 existence.The right pointer can move forward with 0, so the left pointer must be at first, and the right pointer is 0 after the exchange, so you can continue to Right ++      

In summary:

```cpp
        while (right<nums.size())
        {
            if (nums[right]==0)
            {
                right++;
            }
            else
            {
                swap(nums[left],nums[right]);
                left++;
                right++;
            }
                
        }
```

Similar questions:
[75.Sort-Colors](https://leetcode.com/problems/sort-colors/)           

> Solution 1: o(N) C++ Solution(Accepted)      
> Solution 2: O(N) Java Solution Using Insert Index (Accepted)       

[Leetcode Link](https://leetcode.com/problems/move-zeroes)          

[Best Explaination](https://leetcode.com/problems/move-zeroes/discuss/172432/THE-EASIEST-but-UNUSUAL-snowball-JAVA-solution-BEATS-100-(O(n))-%2B-clear-explanation)