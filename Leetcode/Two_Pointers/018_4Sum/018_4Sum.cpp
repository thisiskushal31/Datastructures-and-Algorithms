// Solution 1: Runtime error

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>results;
        if (nums.size()<4) return results;
        
        sort(nums.begin(),nums.end());
        
        for (int a=0; a<nums.size(); a++)
        {
            if (nums[a]*4>target) break;
            if (nums[a]+nums.back()*3<target) continue;
            
            if (a>0 && nums[a]==nums[a-1]) continue;
            
            for (int b=a+1; b<nums.size(); b++)
            {
                if (nums[a]+nums[b]*3>target) break;
                if (nums[a]+nums[b]+nums.back()*2<target) continue;
                
                if (b>a+1 && nums[b]==nums[b-1]) continue;
                
                int left = b+1;
                int right = nums.size()-1;
                if (nums[a]+nums[b]+nums[left]*2>target) break;
                                
                while (left<right)
                {
                    if (nums[a]+nums[b]+nums[left]+nums[right]==target)
                    {
                        vector<int>temp = {nums[a],nums[b],nums[left],nums[right]};
                        results.push_back(temp);
                        left++;
                        right--;
                        while (nums[left]==nums[left-1]) left++;
                        while (nums[right]==nums[right+1]) right--;
                        
                    }
                    else if (nums[a]+nums[b]+nums[left]+nums[right]>target)
                        right--;
                    else if (nums[a]+nums[b]+nums[left]+nums[right]<target)
                        left++;
                }
                
            }
            
        }
        return results;
    }
};

// Solution 2: Accepted
// Smilar approach as the above solution, but more efficient.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n=nums.size();
    vector<vector<int>>ans;
    if(nums.empty())
        return ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        int target3=target-nums[i];
        for(int j=i+1;j<n;j++){
            int target2=target3-nums[j];
            int f=j+1;
            int b=n-1;
            while(f<b){
                int twosum=nums[f]+nums[b];
                if(twosum<target2){
                    f++;
                }
                else if(twosum>target2){
                    b--;
                }
                else{
                    vector<int>quad(4,0);
                    quad[0]=nums[i];
                    quad[1]=nums[j];
                    quad[2]=nums[f];
                    quad[3]=nums[b];
                    ans.push_back(quad);
             while (f<b && nums[f] == quad[2]) f++;
             while (f<b && nums[b] == quad[3]) b--;
                }
            }
            while(j+1<n && nums[j+1]==nums[j]) j++;
        }
        while(i+1<n && nums[i+1]==nums[i]) i++;
    }
    return ans;
    }
};