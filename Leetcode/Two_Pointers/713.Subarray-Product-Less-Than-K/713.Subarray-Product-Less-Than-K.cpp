// Solution 1: O(n) time, O(1) space O(n) time, O(1) space (sliding window) -- C++ solution

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if (k<=1) return 0;
        int j=0;
        int prod = 1;
        int count = 0;
        for (int i=0; i<nums.size(); i++)
        {            
            if (j<i)
            {
                j = i;
                prod = 1;
            }
            
            while (j<nums.size() && prod*nums[j]<k)
            {
                prod = prod*nums[j];
                j++;
            }
            count += j-i;
            prod = prod/nums[i];
        }
        return count;
    }
};

// Solution 2: O(n) time, O(1) space O(n) time, O(1) space (sliding window) -- C++ solution

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int cnt = 0;
        int pro = 1;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            pro *= nums[j];
            while (i <= j && pro >= k) {
                pro /= nums[i++];
            }
            cnt += j - i + 1;
        }
        return cnt;
    }
};