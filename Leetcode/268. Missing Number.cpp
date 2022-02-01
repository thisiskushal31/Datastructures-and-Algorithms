/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number 
in the range that is missing from the array.

Example 1:
    Input: nums = [3,0,1]
    Output: 2
    Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing 
    number in the range since it does not appear in nums.

Example 2:
    Input: nums = [0,1]
    Output: 2
    Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the 
    missing number in the range since it does not appear in nums.

Example 3:
    Input: nums = [9,6,4,2,3,5,7,0,1]
    Output: 8
    Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the 
    missing number in the range since it does not appear in nums.
*/

// **Approach 1 (Hash Table) (C++)

#include<bits/stdc++.h>
#include<numerics>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> full(nums.size()+1);
        iota(full.begin(), full.end(), 0);
        
        for(int num : nums){
            full.erase(remove(full.begin(), full.end(), num), full.end());
        }
        
        return full[0];
    }
};

// ** Approach 2 (C++ : Bit Manipulations)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        //exclusive-or from (a) [0 to n] and (b) [all number in "nums"]
        //same numbers in (a) and (b) will counteract each other
        //so it will remain 0 ^ the missing number = the missing nuber
        for(int i = 0; i < nums.size(); i++){
            result ^= nums[i];
            result ^= i;
        }
        result ^= nums.size();
        return result;
    }
};

// ** Approach 2 (Java)

class Solution {
    public int missingNumber(int[] nums) {
        boolean[] app = new boolean[nums.length + 1];
        for (int i = 0; i < nums.length; i ++) {
            app[nums[i]] = true;
        }
        for (int i = 0; i < app.length; i ++) {
            if (!app[i]) {
                return i;
            }
        }
        return 0;
    }
}

// ** Approach 3 (Java)

public class Solution {
    public int missingNumber(int[] nums) {
        int i = 0;
        while ( i < nums.length) {
            //if nums[i] == n ?
            if (nums[i] == nums.length) {
                i ++;
                continue;
            }
            if (nums[i] != i) {
                int tmp = nums[i];
                nums[i] = nums[nums[i]];
                nums[tmp] = tmp;
            }   
            else {
                i ++;
            }
        }
        for (int j = 0; j < nums.length; j ++) {
            if (nums[j] != j) {
                return j;
            }
        }
        return nums.length;
    }
}

// ** Approach 4 (Java)

public class Solution {
    public int missingNumber(int[] nums) {
        int sum = 0;
        int expected = (1 + nums.length) * nums.length / 2;
        for (int i = 0; i < nums.length; i ++) {
            sum += nums[i];
        }
        return expected - sum;
    }
}

// ** Approach 5 (Java)

public class Solution {
    public int missingNumber(int[] nums) {
        int miss = 0;
        for (int i = 0; i < nums.length; i ++) {
            miss = miss ^ i + 1;
            miss = miss ^ nums[i];
        }
        return miss;
    }
}