/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that
the majority element always exists in the array.

Example 1:
    Input: nums = [3,2,3]
    Output: 3

Example 2:
    Input: nums = [2,2,1,1,1,2,2]
    Output: 2

Constraints:
    n == nums.length
    1 <= n <= 5 * 104
    -231 <= nums[i] <= 231 - 1
*/

// Thought Process(C++)

// **Approach 1 (way to search for the max entry in a map) (C++)

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int,int>x;
            for(auto &i:nums){
                x[i]++;
            }
            int maxx = 0 , ans = 0;
            for(auto it =x.cbegin();it!=x.cend(); ++it ) {  // way to find the max entry of an element
                if (it ->second > maxx) {
                    ans = it->first;
                    maxx = it->second;
                }
            }
            return ans;
        }
};

/*
Thought Process(Java)

1. Sorting
    i. Time complexity O(nlogn)
    ii. Space complexity O(1)

2. HashMap
    i.Time complexity O(n)
    ii.Space complexity O(n)

3. Divide and Conquer

4. Boyer-Moore Voting Algorithm: O(n)

*/

// **Approach 1 ( Sorting Approach) (Java)

class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}

// **Approach 2 (Hashmap Approach) (Java)

class Solution {
    public int majorityElement(int[] nums) {
        int major = 0, count = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) map.put(num, map.getOrDefault(num, 0) + 1);
        for (int key : map.keySet()) {
            if (map.get(key) > count) {
                count = map.get(key);
                major = key;
            }
        }
        return major;
    }
}

// **Approach 3 (Divide and Conquer Approach) (Java)

class Solution {
    public int majorityElement(int[] nums) {
        return getMajor(nums, 0, nums.length - 1);
    }

    private int getMajor(int[] nums, int lo, int hi) {
        if (lo == hi) return nums[lo];
        int mi = lo + (hi - lo) / 2;
        int left = getMajor(nums, lo, mi);
        int right = getMajor(nums, mi + 1, hi);
        if (left == right) return left;
        int leftCount = countInRange(nums, left, lo, mi);
        int rightCount = countInRange(nums, right, mi + 1, hi);
        return leftCount > rightCount ? left : right;
    }

    private int countInRange(int[] nums, int target, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] == target) count++;
        }
        return count;
    }
}

// **Approach 4 (Boyer-Moore Voting Algorithm) (Java)

class Solution {
    public int majorityElement(int[] nums) {
        int major = 0, count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (count == 0) major = nums[i];
            if (major == nums[i]) count++;
            else count--;
        }
        return major;
    }
}