//Approach_1: Double Pointer

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

// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach #0: Brute force 
// TimeOut
public static int maxArea_bf(int[] height) {
    int len = height.length;
    int max = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            int area = Math.min(height[i], height[j]) * (j - i);
            max = Math.max(max, area);
        }
    }

    return max;
}
// time: O(n^2) space: O(1)