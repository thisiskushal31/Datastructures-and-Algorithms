### How to measure Time and Space Complexity of an Algorithm?

#### Introduction

Measurement of time complexity is the process of measuring the time it takes to execute a certain algorithm and the measurement of space complexity is the process of measuring the space it takes to execute a certain algorithm or rather say the analysis of algorithms that are used to solve a problem.  

But we are going to say this part as the analysis of algorithms that are used to solve a problem.

#### Understanding Time Complexity and Space Complexity

In order to understand the time complexity and space complexity of an algorithm, we can take a situation and analyze it.    

*Q. Imagine a classroom of 100 students in which you gave your pen to one person. You have to find that pen without knowing to whom you gave it.*    

Here are some ways to find the pen and what the O order is.  

> **O(n2):** You go and ask the first person of the class, if he has the pen. Also, you ask this person about other 99 people in the classroom if they have that pen and so on, This is what we call O(n2). 
> **O(n):** Going and asking each student individually is O(N). 
> **O(log n):** Now I divide the class into two groups, then ask: “Is it on the left side, or the right side of the classroom?” Then I take that group and divide it into two and ask again, and so on. Repeat the process till you are left with one student who has your pen. This is what you mean by O(log n). 

**NOTE:** *The above O -> is called Big – Oh which is an asymptotic notation. There are other asymptotic notations like theta and Omega*.

*So we are trying to find here when the algorithm give us worst time complexity when the 'N' Number of test cases is given in our case we will take 'N Student'*

So **What is meant by Time Complexity of an Algorithm?**->  Instead of measuring actual time required in executing each statement in the code, Time Complexity considers how many times each statement executes. 

So **What is meant by Space Complexity of an Algorithm?**->  Space Complexity of an algorithm is the total space taken by the algorithm with respect to the input size.

In order to get more information about the time complexity and space complexity of an algorithm, we can take a look at the following resources: 
> [Understanding Time Complexity with Simple Examples](https://www.geeksforgeeks.org/understanding-time-complexity-simple-examples/)
> [Time Complexity and Space Complexity](https://www.geeksforgeeks.org/time-complexity-and-space-complexity/) 
> [Big–Ω (Big- Omega) Notation](https://www.geeksforgeeks.org/analysis-of-algorithms-big-%cf%89-big-omega-notation/) 
> [What does ‘Space Complexity’ mean?](https://www.geeksforgeeks.org/g-fact-86/)

#### Analysis of Algorithms | Set 1 (Asymptotic Analysis)

**Given two algorithms for a task, how do we find out which one is better?**  
> One naive way of doing this is – implement both the algorithms and run the two programs on your computer for different inputs and see which one takes less time. There are many problems with this approach for analysis of algorithms.   
> 1) It might be possible that for some inputs, first algorithm performs better than the second. And for some inputs second performs better.
> 2) It might also be possible that for some inputs, first algorithm perform better on one machine and the second works better on other machine for some other inputs.



##### Credits

> **Source:** *GeeksforGeeks*
> [https://www.geeksforgeeks.org/understanding-time-complexity-simple-examples/](https://www.geeksforgeeks.org/understanding-time-complexity-simple-examples/)
> [https://www.geeksforgeeks.org/analysis-of-algorithms-set-1-asymptotic-analysis/](https://www.geeksforgeeks.org/analysis-of-algorithms-set-1-asymptotic-analysis/)