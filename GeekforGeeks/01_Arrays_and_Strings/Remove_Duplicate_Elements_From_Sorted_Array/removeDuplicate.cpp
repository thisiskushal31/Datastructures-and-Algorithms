// Practice : https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1

// Editorial : https://www.geeksforgeeks.org/remove-duplicates-sorted-array/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
        int j;
        sort(a,a+n);
        for(int i=0;i<n-1;i++){
            if(a[i]!=a[i+1]){
                a[j++]=a[i];
            }
        }
        a[j++]=a[n-1];    
        return j; 
    }
};

// Another Approach

// class Solution{
// public:
//     int remove_duplicate(int a[],int n)
//     {
//         /*No use of extra space */
//         int i=0;

//         for(int j=1;j<n;j++)
//         {
//             if(a[j]!=a[i]){
//                 i++;
//                 a[i]=a[j];
//             }
//         }
//         return i+1;
//     }
// };

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}  // } Driver Code Ends