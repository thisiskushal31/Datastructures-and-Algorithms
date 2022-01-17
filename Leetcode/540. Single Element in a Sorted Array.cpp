// Problem: https://leetcode.com/problems/single-element-in-a-sorted-array/

/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 Example 1:
    Input: nums = [1,1,2,3,3,4,4,8,8]
    Output: 2

 Example 2:
    Input: nums = [3,3,7,7,10,11,11]
    Output: 10
*/

/*
** Approach 01 - C++ Code 

All elements before the required have the first occurrence at even index (0, 2, ..) and the next occurrence at 
    odd index (1, 3, …). And all elements after the required elements have the first occurrence at an odd index 
        and the next occurrence at an even index. 
1) Find the middle index, say ‘mid’.
2) If ‘mid’ is even, then compare arr[mid] and arr[mid + 1]. If both are the same, then the required element 
    after ‘mid’ and else before mid.
3) If ‘mid’ is odd, then compare arr[mid] and arr[mid – 1]. If both are the same, then the required 
    element after ‘mid’ and else before mid.
[Refrence link] (https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int m,i=0,j=nums.size()-1;
        while(j>i)
        {
            m=(j+i)/2;
            if(m%2!=0)
            {
                if(nums[m]==nums[m-1])
                    i=m+1;
                else if(nums[m]==nums[m+1])
                    j=m-1;
                else 
                    return nums[m];
            }
            else 
            {
                if(nums[m]==nums[m+1])
                i=m+2;
                else if (nums[m]==nums[m-1])
                    j=m-2;
                else 
                    return nums[m];
            }
        }
        return nums[i];
    }
};

// Runtime: 44 ms, faster than 5.95% of C++ online submissions for Single Element in a Sorted Array.
// Memory Usage: 22.3 MB, less than 15.27% of C++ online submissions for Single Element in a Sorted Array.