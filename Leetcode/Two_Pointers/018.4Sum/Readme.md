### 18. 4Sum  

#### Sol 1: General Idea
To do 4sum according to the idea of ​​​​3sum, the time complexity of n*n*n*log(n) is required.    
Need to pay attention to the necessary pruning to reduce the amount of computation. For example, the first layer of loop   

```cpp
for (int h1=0; h1<nums.size(); h1++)
{
   if (nums[h1]*4>target) break;
   if (nums[h1]+nums.back()*3<target) continue;
}
```  

Similar second-level loop

```cpp
for (int h2=0; h2<nums.size(); h2++)
{
   if (nums[h1]+3*nums[h2]>target) break;
   if (nums[h1]+nums[h2]+nums.back()*2<target) continue;
}
```    

For the third layer cycle

```cpp
int left=h2+1;
int right=nums.size()-1;
if (nums[h1]+nums[h2]+2*nums[left]>target) break;
if (nums[h1]+nums[h2]+2*nums[right]<target) continue;
```    

For H1 (H2) to avoid the operation of duplicate elements

```cpp
if (h1>0 && nums[h1]==nums[h1-1]) continue;
```

#### Sol 3: General Idea

If you have already read and implement the 3sum and 4sum by using the sorting approach: reduce them into 2sum at the end, you might already got the feeling that, all ksum problem can be divided into two problems:    

2sum Problem    
Reduce K sum problem to K – 1 sum Problem    
Therefore, the ideas is simple and straightforward. We could use recursive to solve this problem. Time complexity is O(N^(K-1)).      

> Solution 1: Runtime error Timedout in function call -- C++     
> Solution 2: Accepted - C++   
> Solution 3: Accepted - Java     

[Leetcode Link](https://leetcode.com/problems/4sum)