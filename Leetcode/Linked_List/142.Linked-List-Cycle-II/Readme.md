### 142. Linked List Cycle II  

#### Algorithm thought: fast and slow pointer, linked list

From the 141st question, it is known that the method of fast and slow pointer can determine whether the linked list is in the ring.

Assuming that when the two pointers meet, the pointer walks through the entrance to enter the ring in the M -steps, and then turns to the K1 circle (N steps of each circle) and more P steps; in the same way, the slow pointer walks across the entrance of Mu Mu into the ring of the ring and then turn aroundThe K2 circle is more P.Because the two are twice the relationship, M+K1 \*N+P = 2 \*(m+k2*n+p).

Get it after the simplification m = (k1-2k2)\*n-p，变换一下  p+m = (k1-2k2)\*n

Because the slow pointer has taken Ptes more than the integer circle, combined with this mathematical formula, which shows that if the slow pointer takes M -M, it will make up for the integer circle, that is, to the entrance of the ring.How to determine M?As long as another pointer starts with the slow pointer from Head, the place where they meet is the entrance of the ring.

There is also a very clever application of the algorithm of this question: 287. Find the Duplicate Number

> Solution 1: slow and fast pointer - C++ (Accepted)       
> Solution 2: slow and fast pointer - Java (Accepted)      

[Leetcode Link](https://leetcode.com/problems/linked-list-cycle-ii)        

[Leetcode Best solution](https://leetcode.com/problems/linked-list-cycle-ii/discuss/1701128/C%2B%2BJavaPython-Slow-and-Fast-oror-Image-Explanation-oror-Beginner-Friendly)       