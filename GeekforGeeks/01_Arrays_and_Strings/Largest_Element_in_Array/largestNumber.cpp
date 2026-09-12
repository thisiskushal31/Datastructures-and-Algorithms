// Practice : https://practice.geeksforgeeks.org/problems/largest-element-in-array4009

// Editorial: https://www.geeksforgeeks.org/c-program-find-largest-element-array/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int max_no = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > max_no)
            {
                max_no = arr[i];
            }
        }
        return max_no;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.largest(arr, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends