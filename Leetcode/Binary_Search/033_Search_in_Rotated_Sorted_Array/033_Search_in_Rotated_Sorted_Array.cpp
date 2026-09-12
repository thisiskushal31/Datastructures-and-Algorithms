// Solution 1:

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left=0;
        int right=nums.size()-1;
        int mid;
        
        if (nums.size()==0) return -1;
        
        while (left<right)
        {
            mid = left+(right-left)/2;
            
            if (nums[mid]==target) return mid;
            
            if (nums[left]<=nums[mid] && nums[left]<=target)
            {
                if (target<nums[mid])
                    right = mid;
                else
                    left = mid+1;
            }
            else if (nums[left]>nums[mid] && nums[left]>target)
            {
                if (target<nums[mid])
                    right = mid;
                else
                    left = mid+1;
            }
            else if (nums[left]<=nums[mid] && nums[left]>target)
                left = mid+1;
            else if (nums[left]>nums[mid] && nums[left]<=target)    
                right = mid;
                
        }
        
        if (nums[left]==target) 
            return left;
        else 
            return -1;
        
    }
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)

// Solution 2:

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        if (nums.size()==0) return -1;
        
        int left=0;
        int right=nums.size()-1;
        int mid;
        
        while (left<right)
        {
            mid = left+(right-left)/2;
            if (nums[left]==target) return left;
            if (nums[right]==target) return right;
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
        
        if (nums[left]==target)
            return left;
        else
            return -1;
    }
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)

// Solution 3:

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()-1;
        
        while (left<right)
        {
            int mid = left+(right-left)/2;
            
            if (nums[mid] == target) return mid;
            
            if (nums[mid]>=nums[0] == target>=nums[0])
            {
                if (nums[mid]<target)
                    left = mid+1;
                else
                    right = mid-1;
            }
            else if (target>=nums[0])
                right = mid-1;
            else
                left = mid+1;
        }
        
        if (left==right && nums[left]==target)
            return left;
        else
            return -1;
    }
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)