// Practice: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

// Editorial: https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/ (O(n^n))
//            https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/ (O(n))

// still not passed by GFG

// Recursive Approach

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int jumps = 0;
       for(int i=0;i<n;) {
           if(i == n-1) {
               return jumps;
           }
           if(arr[i] == 0 && i < n-1) {
               return -1;
           }
           i += arr[i];
           jumps++;
       }
       return jumps;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends