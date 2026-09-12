### 016. 3Sum-Closet  

#### Solution Description

Just remember to sort first! 
After determining the first element, how should the pointers of the second and third elements be changed? 

#### Algorithm Description

Similar to 3 Sum problem, use 3 pointers to point current element, next element and the last element. If the sum is less than target, it means we have to add a larger element so next element move to the next. If the sum is greater, it means we have to add a smaller element so last element move to the second last element. Keep doing this until the end. Each time compare the difference between sum and target, if it is less than minimum difference so far, then replace result with it, otherwise keep iterating.  

```cpp
while (left<right)
{
  if (abs(nums[left]+nums[right]-sum)<CurSum)
  //update min result
  if (nums[left]+nums[right]<sum)
     left++;
  else
     right--;
}
```

> Approach #1: Two Pointers [Accepted - C++]
> Approach #2: Two Pointers [Accepted - Java]
> Algorithm #3: Two Pointers + Cleaner Code[Accepted - Java]

[Leetcode Link](https://leetcode.com/problems/3sum-closest)