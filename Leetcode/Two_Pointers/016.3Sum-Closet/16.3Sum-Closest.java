//Approach #2: Two Pointers [Accepted]

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int minimalDist = Integer.MAX_VALUE;
        int res = 0;
        Arrays.sort(nums);

        for(int i=0;i<nums.length-2; i++){
            int l = i+1;
            int r = nums.length-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target) return target;
                else if(sum > target){//pay attention how target and sum is handled here.
                    if((sum - target) < minimalDist){
                        minimalDist = sum - target;
                        res = sum;
                    }
                    r--;
                }else{
                    if((target - sum) < minimalDist){

                        minimalDist = target - sum;
                        res = sum;
                    } 
                    l++;
                }
            }
            while(i<nums.length -1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Algorithm #3: Two Pointers + Cleaner Code[Accepted]

public class Solution {
    public int threeSumClosest(int[] num, int target) {
        int result = num[0] + num[1] + num[num.length - 1];
        Arrays.sort(num);
        for (int i = 0; i < num.length - 2; i++) {
            int start = i + 1, end = num.length - 1;
            while (start < end) {
                int sum = num[i] + num[start] + num[end];
                if (sum > target) {
                    end--;
                } else {
                    start++;
                }
                if (Math.abs(sum - target) < Math.abs(result - target)) {
                    result = sum;
                }
            }
        }
        return result;
    }
}