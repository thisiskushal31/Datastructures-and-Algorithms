// Practice: https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1

// Editorial: Set 1 : https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
//            Set 2 : https://www.geeksforgeeks.org/duplicates-array-using-o1-extra-space-set-2/

// { Driver Code Starts
import java.io.*;
import java.util.*;

class findDuplicates {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = sc.nextInt();
            Solution g = new Solution();
            ArrayList<Integer> ans = Solution.duplicates(a, n);
            for (Integer val : ans)
                System.out.print(val + " ");
            System.out.println();
        }
    }

    }
    // } Driver Code Ends

    class Solution {

    public static ArrayList<Integer> duplicates(int arr[], int n) {
        // First check all the values that are
        // present in an array then go to that
        // values as indexes and increment by
        // the size of array
        for (int i = 0; i < n; i++) {
            int index = arr[i] % n;
            arr[index] += n;
        }

        // Now check which value exists more
        // than once by dividing with the size
        // of array
        int flag = 0;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            if ((arr[i] / n) > 1) {
                ans.add(i);
                flag = 1;
            }
        }
        if (flag == 0)
            ans.add(-1);
        return ans;
    }
}
