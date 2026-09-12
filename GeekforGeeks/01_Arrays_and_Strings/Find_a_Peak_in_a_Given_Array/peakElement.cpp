// Practice: https://practice.geeksforgeeks.org/problems/peak-element/1/

// Editorial: https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/

// { Driver Code Starts
//Initial Template for C
#include <stdio.h>
#include <stdbool.h>
// } Driver Code Ends
//User function Template for C

int peakElement(int arr[], int n)
{
    int i = 1;
    if (n == 1 || arr[i - 1] > arr[i])
        return 0;

    while (i < n - 1)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            return i;
        i++;
    }
    return n - 1;
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n], tmp[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            tmp[i] = a[i];
        }
        bool f = 0;

        int A = peakElement(tmp, n);

        if (A < 0 && A >= n)
            printf("0\n");
        else
        {
            if (n == 1 && A == 0)
                f = 1;
            else if (A == 0 && a[0] >= a[1])
                f = 1;
            else if (A == n - 1 && a[n - 1] >= a[n - 2])
                f = 1;
            else if (a[A] >= a[A + 1] && a[A] >= a[A - 1])
                f = 1;
            else
                f = 0;
            printf("%d\n", f);
        }
    }

    return 0;
} // } Driver Code Ends
// Complexity : O(n)

/*
// A C++ program to find a peak element
// using divide and conquer
#include <bits/stdc++.h>
using namespace std;

// A binary search based function
// that returns index of a peak element
int findPeakUtil(int arr[], int low,
                 int high, int n)
{
    // Find index of middle element
    // (low + high)/2
    int mid = low + (high - low) / 2;

    // Compare middle element with its
    // neighbours (if neighbours exist)
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;

    // If middle element is not peak and its
    // left neighbour is greater than it,
    // then left half must have a peak element
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return findPeakUtil(arr, low, (mid - 1), n);

    // If middle element is not peak and its
    // right neighbour is greater than it,
    // then right half must have a peak element
    else
        return findPeakUtil(
            arr, (mid + 1), high, n);
}

// A wrapper over recursive function findPeakUtil()
int findPeak(int arr[], int n)
{
    return findPeakUtil(arr, 0, n - 1, n);
}

// Driver Code
int main()
{
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of a peak point is "
         << findPeak(arr, n);
    return 0;
}

// complexity : O(log n)
*/