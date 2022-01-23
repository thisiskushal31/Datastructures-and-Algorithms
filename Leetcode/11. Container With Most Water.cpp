// Problem: https://leetcode.com/problems/container-with-most-water/

/*
Given n non-negative integers a1, a2, …, an, where each represents a point at coordinate (i, ai). n vertical lines 
are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
forms a container, such that the container contains the most water.

Note: You may not slant the container.

Example 1:

    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

    Input: height = [1,1]
    Output: 1

*/

/* 

**Approach#1

The key idea here is that , for any container, the water it could contain is determined by the 
shorter height. Try candidate from the far left and far right. Always move the shorter pointer to the center.
*/
public class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length -1;
        int max = 0;
        while (left < right) {
            max = Math.max(max, Math.min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                left ++;
            }
            else {
                right --;
            }
        }
        return max;
    }
}


//Approach#2 Same as above but with vector_array
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        
        int temp=0;
        int result=0;
        
        while (left<right)
        {
            int temp = (right-left)*min(height[left],height[right]);
            if (temp>result) result=temp;
            
            if (height[left]>=height[right])
                right--;
            else
                left++;
        }
        
        return result;
        
    }
};