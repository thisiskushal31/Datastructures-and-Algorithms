/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the 
array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the 
elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a 
length of n. 

Example 1:

    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]
    Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:

    Input: nums1 = [1], m = 1, nums2 = [], n = 0
    Output: [1]
    Explanation: The arrays we are merging are [1] and [].
    The result of the merge is [1].
*/

/*
    **Approach 1 ( C++ Approach)
    With Vector_Array
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = m+n-1;
        int end1 = m -1;
        int end2 = n -1;

        while(end2 >= 0){
            if(end1 >=0){
                nums1[end--] = nums1[end1] > nums2[end2] ? nums1[end1--] : nums2[end2--];
            }else{
                nums1[end--] = nums2[end2--];
            }
        }
    }
};

/*
    **Approach 2 ( Java Approach)
*/

public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {

        int end = m+n-1;
        int end1 = m -1;
        int end2 = n -1;

        while(end2 >= 0){
            if(end1 >=0){
                nums1[end--] = nums1[end1] > nums2[end2] ? nums1[end1--] : nums2[end2--];
            }else{
                nums1[end--] = nums2[end2--];
            }
        }

    }
}