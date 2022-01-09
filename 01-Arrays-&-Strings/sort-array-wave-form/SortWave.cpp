// Practice : https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1/

// Editorial: https://www.geeksforgeeks.org/sort-array-wave-form-2/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr, int n){
        int i=0,j=0;
        int temp;
        for(int i = 0;i<=n-2;i=i+2){
           if(arr[i]<=arr[i+1])
           {
               int temp = arr[i];
               arr[i]=arr[i+1];
               arr[i+1]=temp;
           }
       }
       
       for (int i = 0; i + 1 < n; i += 2)
            swap(arr[i], arr[i + 1]);
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        vector<int> a(n); //declare vector of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        Solution ob;
        ob.convertToWave(a, n);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}  // } Driver Code Ends