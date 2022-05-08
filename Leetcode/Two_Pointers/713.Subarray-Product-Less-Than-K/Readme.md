### 713.Subarray-Product-Less-Than-K

#### Solution 1

This question has obvious characteristics of sliding window, so the basic idea is to use double pointers. Guarantee a maximum window whose product is less than k, the number of subarrays that can be formed in this window is j-i+1;    

One thing to note in this question is that when *nums[i]>k*, the right pointer cannot move, but the left pointer will still move forward, so there may be a situation where *j < i*. In this case, it is only necessary to reset these two pointers. Can:    

```cpp
if (j<i)
{
    j = i;
    product = 1;
}
```
#### Solution 2 & 3

1. The idea is always keep an max-product-window less than K;      
2. Every time shift window by adding a new number on the right(j), if the product is greater than k, then try to reduce numbers on the left(i), until the subarray product fit less than k again, (subarray could be empty);      
3. Each step introduces x new subarrays, where x is the size of the current window (j + 1 - i);       
example:    

```cpp
for window (5, 2), when 6 is introduced, it     
add 3 new subarray: (5, (2, (6)))     
        (6)    
     (2, 6)     
  (5, 2, 6)    
```   

> Solution 1: Sliding Window -- C++ solution        
> Solution 2: Sliding Window -- C++ solution         
> Solution 3: Sliding Window -- Java solution        

[Best Leetcode Solution](https://leetcode.com/problems/subarray-product-less-than-k/discuss/108861/JavaC%2B%2B-Clean-Code-with-Explanation)     

[Leetcode Link](https://leetcode.com/problems/subarray-product-less-than-k)