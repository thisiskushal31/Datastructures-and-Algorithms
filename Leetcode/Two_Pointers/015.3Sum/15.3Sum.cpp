
// Approach #1: Two Pointers [Accepted]

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

//Time Complexity: O(n^2)
//Space Complexity: O(1)