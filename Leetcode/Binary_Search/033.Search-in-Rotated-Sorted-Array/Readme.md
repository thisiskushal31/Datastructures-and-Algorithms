### 33. Search-in-Rotated-Sorted-Array

#### Solution Description:

Here, Key idea is to use binary search to find the target it is also called Pivotted Binary Search.

#### Solution 1

The breakthrough of this type of question is to use nums[left] to determine the positional relationship between the three by comparing nums[left] and nums[mid], nums[left] and target.

```cpp
        while (left<right)
        {
            mid = left+(right-left)/2;            
            if (nums[mid]==target) return mid;            
            if (nums[left]<=nums[mid] && nums[left]<=target || nums[left]>nums[mid] && nums[left]>target) //In the same section
            {
                if (target<nums[mid])
                    right = mid;
                else
                    left = mid+1;
            }
            else if (nums[left]<=nums[mid] && nums[left]>target) //In different sections
                left = mid+1;
            else if (nums[left]>nums[mid] && nums[left]<=target) //In different sections   
                right = mid;                
        }
```

Every time mid = left+(right-left)/2 is determined, you can check nums[mid]==target to judge in advance.

#### Solution 2

In fact, nums[mid] and target can also be compared with nums[0] respectively to judge whether mid and target are in the same interval.

```cpp
        while (left<right)
        {
            mid = left+(right-left)/2;
            if (nums[mid]==target) return mid;            
            if (target>=nums[0] && nums[mid]>=nums[0] || target<nums[0] && nums[mid]<nums[0])
            {
                if (nums[mid]>target)
                    right=mid;
                else
                    left=mid+1;
            }
            else if (target>=nums[0] && nums[mid]<nums[0])
                right=mid;
            else if (target<nums[0] && nums[mid]>=nums[0])
                left=mid+1;
        }
```        

#### Solution 3

There is a neater solution. Ordinary binary search, need to compare the value of nums[mid] and target. In this question, because nums[mid] and target may not be in the same monotonic interval, their comparison is not helpful for guiding the update of [left, right]. So what should you do if you encounter this situation?  

We found that if we can determine that target is in the monotonic interval on the left, and nums[mid] is in the monotonic interval on the right, then we can directly move the search range to the left interval, the method is ```right=mid-1```. If we can determine that target is in the monotonic interval on the right, and nums[mid] is in the monotonic interval on the left, then we can directly move the search range to the right interval, the method is ```left=mid+1```. In this way, the conventional binary search can quickly locate the target.  

So the key to this question is to determine which interval nums[mid] and target are in? The method is amazing, just compare each of them with the result of the size of nums[0]!   

#### Solution 4

If the entire left part is monotonically increasing, which means the pivot point is on the right part      
If left <= target < mid ------> drop the right half        
Else ------> drop the left half             
If the entire right part is monotonically increasing, which means the pivot point is on the left part               
If mid < target <= right ------> drop the left half       
Else ------> drop the right half          


[Leetcode Link](https://leetcode.com/problems/search-in-rotated-sorted-array)

[Best Leetcode Solution](https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14436/Revised-Binary-Search)