// Practice: https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1

// Editorial: Set 1 : https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
//            Set 2 : https://www.geeksforgeeks.org/duplicates-array-using-o1-extra-space-set-2/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> duplicates(int arr[], int n)
    {
        vector<int> count(n, 0);
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            count[arr[i]] += 1;
            if (count[arr[i]] == 2)
            {
                res.push_back(arr[i]);
            }
        }
        if (res.empty())
        {
            res.push_back(-1);
            return res;
        }
        sort(res.begin(), res.end());
        return res;
    }
};

//Another approach

// class Solution{
//   public:
//     vector<int> duplicates(int arr[], int n) {
//         // First check all the values that are
//         // present in an array then go to that
//         // values as indexes and increment by
//         // the size of array
//         for (int i = 0; i < n; i++) {
//             int index = arr[i] % n;
//             arr[index] += n;
//         }

//         // Now check which value exists more
//         // than once by dividing with the size
//         // of array
//         bool flag = false;
//         vector<int> ans;
//         for (int i = 0; i < n; i++) {
//             if ((arr[i] / n) > 1) {
//                 ans.push_back(i);
//                 flag = true;
//             }
//         }
//         if (!flag) ans.push_back(-1);
//         return ans;
//     }
// };

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends