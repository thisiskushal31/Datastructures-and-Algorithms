// Problem: https://leetcode.com/problems/3sum/

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and 
nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]

Example 2:

    Input: nums = []
    Output: []

Example 3:

    Input: nums = [0]
    Output: []

*/

/* 

**Approach 1

1. Be sure to sort first. 
2.To avoid duplication, move the left and right pointers over duplicates only after 
    confirming that a set of solutions has been found. Do not skip duplicates before deciding whether the solution 
    holds. Be sure to sort first. To avoid duplication, move the left and right pointers over duplicates only after 
    confirming that a set of solutions has been found. Do not skip duplicates before deciding whether the solution holds.
3. For the outermost loop, one is also determined, and the inner loop is expanded first, and then the outermost repetition is skipped.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        
        for (int i=0; i<nums.size(); i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        
        for (int a=0; a<nums.size(); a++)
        {

            int sum=-nums[a];
            
            int left=a+1;
            int right=nums.size()-1;
            
            while (left<right)
            {
                if (nums[left]+nums[right]==sum)
                {
                    vector<int>temp{nums[a],nums[left],nums[right]};
                    result.push_back(temp);
                    left++;
                    right--;
                    while (left<right && nums[left]==nums[left-1]) left++;
                    while (left<right && nums[right]==nums[right+1]) right--; 
                }
                else if (nums[left]+nums[right]<sum)
                    left++;
                else if (nums[left]+nums[right]>sum)
                    right--;
            }
            
            while (a+1<nums.size() && nums[a]==nums[a+1])
                a++;
        }
        
        return result;
    }
};

// Approach 2 

class Solution {
public: 
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums == null || nums.length == 0) return res;

        Arrays.sort(nums);
        for(int i=0; i< nums.length -2; i++){
            if( i > 0 && nums[i] == nums[i-1]) continue;

            int l = i+1;
            int r = nums.length-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum ==0){
                    List<Integer> t = new ArrayList<>();
                    t.add(nums[i]);
                    t.add(nums[l]);
                    t.add(nums[r]);
                    res.add(t);
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l-1]) l++;
                    while(l < r && nums[r] == nums[r+1]) r--;
                }else if(sum < 0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return res;
    }
}