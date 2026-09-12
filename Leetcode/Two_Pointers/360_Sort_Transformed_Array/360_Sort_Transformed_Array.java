// Solution 2: Two pointers -- Java


class Solution {
    int a, b, c;
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
        int n = nums.length, i = 0, j = n - 1;
        int[] rst = new int[n];
        int index = a >= 0 ? n - 1 : 0;
        
        while (i <= j) {
            int left = calc(nums[i]), right = calc(nums[j]);
            if (a >= 0) {
                rst[index--] = left >= right ? calc(nums[i++]) : calc(nums[j--]);
            } else { // a < 0
                rst[index++] = left >= right ? calc(nums[j--]) : calc(nums[i++]);
            }
        }

        return rst;
    }
    
    private int calc(int x) {
        return a * x * x + b * x + c;
    }
}

// time: O(n)
// space: O(n) store result