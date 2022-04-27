### 209.Minimum-Size-Subarray-Sum

**Basic ideas**: Because the intention guarantees that all array elements are positive, you can use a double pointer to determine the boundary.When the sub -array between the double pointers and greater than the SUM, record *Len* and *Left++*; otherwise *Right++*.      

In actual programming, the idea of controlling the right pointer with the for loop is relatively clear. The left pointer is moved only when the right pointer is fixed; in contrast, it is easier to use the While to control the dual pointer.      

Details: Pay attention to update Len under what conditions.      

> Solution 1: Two Pointers(Accepted-C++)   
> Solution 2: Two Pointers(Accepted-Java)   

[Leetcode Link](https://leetcode.com/problems/minimum-size-subarray-sum)          
[Leetcode Solution](https://leetcode.com/problems/minimum-size-subarray-sum/discuss/59078/Accepted-clean-Java-O(n)-solution-(two-pointers)) -- C++    
[Leetcode Solution](https://leetcode.com/problems/minimum-size-subarray-sum/discuss/1232367/C%2B%2B-sliding-window-solution) -- Java      
