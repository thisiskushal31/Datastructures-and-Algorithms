### 360.Sort-Transformed-Array

![Problem Statement](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/Leetcode/Two_Pointers/360.Sort-Transformed-Array/sort-transformed-array-leetcode-problem-statement.png?raw=true)

**As this problem is for premium you will be able to solve it only if you have a premium account, for free user there is a screenshot of the problem statement.**   [Problem Statement](https://www.tutorialspoint.com/sort-transformed-array-in-cplusplus)     

#### Solution

Note that A is equal to zero and positive negative situation, which will affect the results.If A == 0, the function result is monotonous itself, but the order is changed according to whether B greater than 0.          

When A is not equal to zero, set two pointers left and right, and you can move the pointer that moves far away according to the distance from the nums [left], num [right] to the middle axis (-b/2A).The distance between Right and the central axis.Let the two pointers keep approaching until left == Right.              

You can also move the pointer directly with the size of the Func [i] corresponding to the two pointers.When A> 0, priority to move the two is large, and the final result is backflow; when A <0, the two are small between the two.        

Summary: 
- Math basics: x^2 dominates the overall curve so it is up to a to determine:      
    - if a < 0, both sides will be small and center will be large. Prioritize larger value.     
    - if a > 0, center will be small and both sides will be large. Prioritize smaller value.     
    - starting index being 0 or n-1, is driven by a       

> Solution 1: Two pointers--C++      
> Solution 2: Two pointers--Java     

[Leetcode Link](https://leetcode.com/problems/sort-transformed-array)          

[Best Solution](https://github.com/awangdev/LintCode/blob/master/Java/360.%20Sort%20Transformed%20Array.java)          

>Tags: Math, Two Pointers     