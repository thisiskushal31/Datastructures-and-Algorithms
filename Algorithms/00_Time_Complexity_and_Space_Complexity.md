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

[Asymptotic Analysis](https://www.geeksforgeeks.org/analysis-of-algorithms-set-1-asymptotic-analysis) is the big idea that handles above issues in analyzing algorithms. In Asymptotic Analysis, we evaluate the performance of an algorithm in terms of input size (we don’t measure the actual running time). We calculate, how the time (or space) taken by an algorithm increases with the input size.   

For Example: Take Two Machine **A B** and **Machine A** is Faster than **Machine B**. So, both **Machine A** & **Machine B** has a constant *A*. Let’s say the constant for *A* is *0.2* and the constant for *B* is *1000* which means that *A is 5000 times more powerful than B*. 

*Here are some running times for this example:*   
> Linear Search running time in seconds on A: 0.2 * n   
> Binary Search running time in seconds on B: 1000*log(n)   

    ------------------------------------------------
    |n      | Running time on A | Running time on B |
    -------------------------------------------------
    |10     | 2 sec             | ~ 1 h             |
    -------------------------------------------------
    |100    | 20 sec            | ~ 1.8 h           |
    -------------------------------------------------
    |10^6   | ~ 55.5 h          | ~ 5.5 h           |
    -------------------------------------------------
    |10^9   | ~ 6.3 years       | ~ 8.3 h           |
    -------------------------------------------------          

But this **not the best way to find the efficiency of an algorithm** because 
1. Asymptotic analysis considers machine constraints in case when the both the machine is same it will fails.    
2. Asymptotic analysis considers the input sizes larger than a constant value. It might be possible that those large inputs are never given to your software and an algorithm which is asymptotically slower, always performs better for your particular situation. So, you may end up choosing an algorithm that is Asymptotically slower but faster for your software.    

#### Analysis of Algorithms | Set 2 (Worst, Average and Best Cases)

We can have three cases to analyze an algorithm: 
1) The Worst Case 
2) Average Case 
3) Best Case

Lets take the following implementation of Linear Search. 
```cpp
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
```

> **Worst Case Analysis (Usually Done):** In the worst-case analysis, we calculate the upper bound on the running time of an algorithm. We say that the running time of an algorithm is upper bounded by the running time of the worst case. The worst case is the case in which the algorithm takes the maximum amount of time to execute. So, the worst-case time complexity of linear search would be Θ(n) when element is not found or at the last of the array.      
> **Average Case Analysis (Sometimes done):** In average case analysis, we take all possible inputs and calculate computing time for all of the inputs. Sum all the calculated values and divide the sum by the total number of inputs. We must know (or predict) the distribution of cases. For the linear search problem, let us assume that all cases are uniformly distributed (including the case of x not being present in the array). So we sum all the cases and divide the sum by (n+1). Following is the value of average-case time complexity. 
![Average Case Analysis](https://github.com/thisiskushal31/Datastructures-and-Algorithms/blob/main/Algorithms/assets/formula_average_case.png?raw=true)
> **Best Case Analysis (Bogus):** In the best case analysis, we calculate the lower bound on the running time of an algorithm, that is not helpful as it lower bound does not tell us anything about the efficiency of the algorithm.

##### Which case to use for analysis of algorithms? 
Answer is: *Use the worst case analysis* as the worst case analysis gives us at what extent the algorithm is breaking so that we improve the efficiency of the algorithm in time of need.

[Worst, Average and Best Cases More Brief Information](https://www.geeksforgeeks.org/analysis-of-algorithms-set-2-asymptotic-analysis)
#### Analysis of Algorithms | Set 3 (Asymptotic Notations)


#### Credits

> **Source:** *GeeksforGeeks*           
> [https://www.geeksforgeeks.org/understanding-time-complexity-simple-examples/](https://www.geeksforgeeks.org/understanding-time-complexity-simple-examples/)        
> [https://www.geeksforgeeks.org/analysis-of-algorithms-set-1-asymptotic-analysis/](https://www.geeksforgeeks.org/analysis-of-algorithms-set-1-asymptotic-analysis/)       