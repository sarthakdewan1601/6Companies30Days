// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int lengthOfLongestAP(int a[], int n) {
        // code here
        if (n <= 2) return n;
        int i, j, k;
        vector<unordered_map<int, int>> dp(n);
        int max_len = INT_MIN;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                int diff = a[j] - a[i];
                if (dp[i].find(diff) != dp[i].end())
                {
                    dp[j][diff] = dp[i][diff] + 1;
                }
                else
                {
                    dp[j][diff] = 2;
                }
                max_len = max(max_len, dp[j][diff]);
            }
        }
        return max_len;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends