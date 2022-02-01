/**
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
**/

// **Approach 3 (Divide and Conquer Approach) (C++)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> myset(nums.begin(), nums.end());
        return myset.size() < nums.size();
    }
};

/*
Thought Process (Java)

1. Sort
    Time complexity O(n logn)
    Space complexity O(1) or O(n) depends on if we can temper the original array
2. Hash Table - Set
    Time complexity O(n)
    Space complexity O(n)
*/

// **Approach 1 (Sort) (Java)

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
}

// **Approach 2 (Hash Table - Set) (Java)

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums){
            if (!set.add(num)) return true;
        }
        return false;
    }
}