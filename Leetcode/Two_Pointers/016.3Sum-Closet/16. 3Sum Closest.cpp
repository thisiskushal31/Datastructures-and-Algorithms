// Problem: https://leetcode.com/problems/3sum/'

/*
Given an integer array nums of length n and an integer target, find three integers in nums 
such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

    Input: nums = [-1,2,1,-4], target = 1
    Output: 2
    Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
    
    Input: nums = [0,0,0], target = 1
    Output: 0
*/

/* 

**Approach 1

Just remember to sort first!
After determining the first element, how should the pointers of the second and third elements be changed?

*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {        
        sort(nums.begin(),nums.end());
        
        int temp = INT_MAX;
        int result;
        
        for (int a=0; a<nums.size(); a++)
        {
            int left = a+1;
            int right = nums.size()-1;
            int sum = target - nums[a];
            
            while (left<right)
            {
                if (temp > abs(nums[left]+nums[right]-sum))
                {
                    temp = abs(nums[left]+nums[right]-sum);
                    result = nums[a]+nums[left]+nums[right];
                }
                if (nums[left]+nums[right]==sum)
                    return target;
                else if (nums[left]+nums[right]>sum)
                    right--;
                else if (nums[left]+nums[right]<sum)    
                    left++;
            }
            
        }
        
        return result;
    }
};

/*
** Approach 2 without vector_array 
*/

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int minimalDist = Integer.MAX_VALUE;
        int res = 0;
        Arrays.sort(nums);

        for(int i=0;i<nums.length-2; i++){
            int l = i+1;
            int r = nums.length-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target) return target;
                else if(sum > target){//pay attention how target and sum is handled here.
                    if((sum - target) < minimalDist){
                        minimalDist = sum - target;
                        res = sum;
                    }
                    r--;
                }else{
                    if((target - sum) < minimalDist){

                        minimalDist = target - sum;
                        res = sum;
                    } 
                    l++;
                }
            }
            while(i<nums.length -1 && nums[i] == nums[i+1]) i++;
        }

        return res;
    }

}