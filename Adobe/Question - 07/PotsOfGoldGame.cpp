// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int dp[501][501];
    int helper(vector<int> &arr, int start, int end)
    {
        //base condition
        if (start > end)
        {
            return 0;
        }
        if (start == end)
        {
            return arr[start];
        }

        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }

        //implementation
        int x = arr[start] + min(helper(arr, start + 1, end - 1), helper(arr, start + 2, end));

        int y = arr[end] + min(helper(arr, start + 1, end - 1), helper(arr, start, end - 2));

        return dp[start][end] = max(x, y);
    }

    int maxCoins(vector<int>&arr, int n)
    {
        //Write your code here
        int i = 0;
        int j = n - 1;
        memset(dp, -1, sizeof(dp));
        return helper(arr, i, j);
        // return dp[n-1][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends