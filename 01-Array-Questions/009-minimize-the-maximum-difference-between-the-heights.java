// Practice: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

// Editorial: https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/

import java.util.*;
import java.lang.*;
import java.io.*;

class MinimizeHeights {
    public static int getMinimizeHeights(int arr[], int n, int k) {
        if (n == 1)
            return 0;
        Arrays.sort(arr);
        int diff = arr[n - 1] - arr[0];
        int minimum = arr[0] + k;
        int maximum = arr[n - 1] - k;
        int temp = 0;
        if (minimum > maximum) {
            temp = minimum;
            minimum = maximum;
            maximum = temp;
        }
        for (int i = 1; i < n - 1; i++) {
            int difference = arr[i] - k;
            int sum = arr[i] + k;
            if (difference >= minimum || sum <= maximum)
                continue;
            if (maximum - difference <= sum - minimum)
                minimum = difference;
            else
                maximum = sum;
        }
        return Math.min(diff, maximum - minimum);
    }

    public static void main(String[] args) {
        int arr[] = { 7, 12, 3 };
        int n = arr.length;
        int k = 8;
        System.out.println(getMinimizeHeights(arr, n, k));
    }
}