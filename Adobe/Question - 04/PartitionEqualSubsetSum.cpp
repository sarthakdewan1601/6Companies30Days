// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int i, j, k;
        int sum = 0;
        for (i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        if (sum % 2 != 0) return 0;

        bool dp[n + 1][sum / 2 + 1];
        for (i = 0; i <= sum / 2; i++)
        {
            dp[0][i] = 0;
        }
        for (i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= sum / 2; j++)
            {
                if (arr[i - 1] > sum / 2)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
            }
        }
        if (dp[n][sum / 2] == true)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}  // } Driver Code Ends