/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element 
in the result must be unique and you may return the result in any order.

Example 1:

    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2]

Example 2:

    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [9,4]
    Explanation: [4,9] is also accepted.
*/

// **Approach 1 (Use two hash sets) (C++)
/// Time complexity: O(len(nums1) + len(nums2))

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> record(nums1.begin(), nums1.end());

        unordered_set<int> resultSet;
        for( int i = 0 ; i < nums2.size() ; i ++ )
            if( record.find(nums2[i]) != record.end() )
                resultSet.insert( nums2[i] );

        return vector<int>(resultSet.begin(), resultSet.end());
    }
};

// **Approach 1 (Use two hash sets) (Java)  Time complexity: O(n)

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> app = new HashSet<Integer>();
        for (int i = 0; i < nums1.length; i ++) {
            app.add(nums1[i]);
        }
        HashSet<Integer> res = new HashSet<Integer>();
        for (int i = 0; i < nums2.length; i ++) {
            if (app.contains(nums2[i])) {
                res.add(nums2[i]);
            }
        }
        int[] result = new int[res.size()];
        int i = 0;
        for (Integer j:res) {
            result[i++] = j;
        }
        return result;
    }
}

// **Approach 2 (Sort both arrays, use two pointers) (JAVA) Time complexity: O(nlogn)

    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int i = 0;
        int j = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                set.add(nums1[i]);
                i++;
                j++;
            }
        }
        int[] result = new int[set.size()];
        int k = 0;
        for (Integer num : set) {
            result[k++] = num;
        }
        return result;
    }

// **Approach 3 (Binary search) (JAVA) Time complexity: O(nlogn)

public int[] intersection(int[] nums1, int[] nums2) {
    Set<Integer> set = new HashSet<>();
    Arrays.sort(nums2);
    for (Integer num : nums1) {
        if (binarySearch(nums2, num)) {
            set.add(num);
        }
    }
    int i = 0;
    int[] result = new int[set.size()];
    for (Integer num : set) {
        result[i++] = num;
    }
    return result;
}
    
public boolean binarySearch(int[] nums, int target) {
    int low = 0;
    int high = nums.length - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}