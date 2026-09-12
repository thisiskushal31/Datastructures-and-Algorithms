// Approach 2: Two Pointers[Accepted]

class Solution {
    public: 
        public List<List<Integer>> threeSum(int[] nums) {
            List<List<Integer>> res = new ArrayList<>();
            if(nums == null || nums.length == 0) return res;
    
            Arrays.sort(nums);
            for(int i=0; i< nums.length -2; i++){
                if( i > 0 && nums[i] == nums[i-1]) continue;
    
                int l = i+1;
                int r = nums.length-1;
                while(l < r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum ==0){
                        List<Integer> t = new ArrayList<>();
                        t.add(nums[i]);
                        t.add(nums[l]);
                        t.add(nums[r]);
                        res.add(t);
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    }else if(sum < 0){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
            return res;
        }
    }
};

//Time Complexity: O(n^2)
//Space Complexity: O(1)

//Approach 3: Two Pointers but Different approach[Accepted]

class Solution {
    public List<List<Integer>> threeSum(int[] num) {
        Arrays.sort(num);
        List<List<Integer>> res = new LinkedList<>(); 
        for (int i = 0; i < num.length-2; i++) {
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                int lo = i+1, hi = num.length-1, sum = 0 - num[i];
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        res.add(Arrays.asList(num[i], num[lo], num[hi]));
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        lo++; hi--;
                    } else if (num[lo] + num[hi] < sum) {
                        // improve: skip duplicates
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        lo++;
                    } else {
                        // improve: skip duplicates
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        hi--;
                    }
                }
            }
        }
        return res;
    }
}