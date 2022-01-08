// Practice : https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1/

// Editorial : https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/


//o(Log(N)) Approach using Binary Search Pivot Technqiue

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int MinIndex(int arr[], int n)
    {
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int prev = (mid - 1 + n) % n, next = (mid + 1) % n;
            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
                return mid;
            else if (arr[mid] <= arr[high])
                high = mid - 1;
            else if (arr[mid] >= arr[low])
                low = mid + 1;
        }
        return -1;
    }
    int Binary(int arr[], int lo, int ho, int K)
    {
        while (lo <= ho)
        {
            int mid = lo + (ho - lo) / 2;
            if (K > arr[mid])
            {
                lo = mid + 1;
            }
            else if (K < arr[mid])
            {
                ho = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
    int search(int A[], int l, int h, int key)
    {
        int n = h - l + 1;
        int pivot = MinIndex(A, n);
        int k1 = Binary(A, 0, pivot - 1, key);
        int k2 = Binary(A, pivot + 1, h, key);
        if (k1 != -1)
        {
            return k1;
        }
        else
        {
            return k2;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
    return 0;
} // } Driver Code Ends]

/* Author Version

class Solution{
    public:
    int search(int A[], int l, int h, int key) { 
    if (l > h) return -1; 
    int mid = (l+h)/2; 
    if (A[mid] == key) return mid; 

    if (A[l] <= A[mid]) { 
        if (key >= A[l] && key <= A[mid]) 
        return search(A, l, mid-1, key); 
        return search(A, mid+1, h, key); 
    } 
    if (key >= A[mid] && key <= A[h]) 
        return search(A, mid+1, h, key); 
    return search(A, l, mid-1, key); 
    } 
};

*/