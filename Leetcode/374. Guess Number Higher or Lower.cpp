// Problem: https://leetcode.com/problems/guess-number-higher-or-lower/

/*
    We are playing the Guess Game. The game is as follows:

    I pick a number from 1 to n. You have to guess which number I picked.

    Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

    You call a pre-defined API int guess(int num), which returns 3 possible results:

    -1: The number I picked is lower than your guess (i.e. pick < num).
    1: The number I picked is higher than your guess (i.e. pick > num).
    0: The number I picked is equal to your guess (i.e. pick == num).
    Return the number that I picked.

    Example 1:
    Input: n = 10, pick = 6
    Output: 6

    Example 2:
    Input: n = 1, pick = 1
    Output: 1

    Example 3:
    Input: n = 2, pick = 1
    Output: 1
*/

/*
** Approach 01 ::: Java Code
*/

/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int left = 1;
        int right = n;
        while(left < right){
            int mid = left + (right -left)/2;
            int res = guess(mid);
            if(res == 0) return mid;
            else if( res > 0){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        return left;
    }
}
/*
** Approach 02 :::: C++ Code

This is just a simple question of binary search here you have to use already defined function int guess(int num) to 
check if the guessed number m is greater or smaller than the picked number                                                                                                                                                    
Only difference is that here you have already defined function to check conditions of the binary search
*/

int guessNumber(int n) {
    long long int m,i=1,j=n;
    while(j>=i)
    {
        m=i+(j-i)/2;
        if(guess(m)==0)
        {
            return m;
        }
        if(guess(m)==-1)
        {
            j=m-1; 
        }
        if(guess(m)==1) 
        {
            i=m+1;
        }
    }
    return -1;
}