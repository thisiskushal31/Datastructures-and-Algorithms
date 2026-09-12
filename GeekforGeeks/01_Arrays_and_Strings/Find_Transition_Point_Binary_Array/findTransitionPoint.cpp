// Practice: https://practice.geeksforgeeks.org/problems/find-transition-point-1587115620/1

// Editorial: https://www.geeksforgeeks.org/find-transition-point-binary-array/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    int lb = 0, ub = n-1;
    while (lb <= ub)
    {
        int mid = (lb+ub)/2;
        if (arr[mid] == 0)
            lb = mid+1;
        else if (arr[mid] == 1)
        {
            if (mid == 0
                    || (mid > 0 && 
                       arr[mid - 1] == 0))
                return mid;
            ub = mid-1;
        }
    }
    return -1;
}