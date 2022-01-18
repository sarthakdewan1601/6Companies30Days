// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    vector<vector<long long>> dp;
    long long int helper(int n, int x, int base)
    {
        long long int temp = pow(base, x);
        //base case
        if (temp == n)
        {
            return 1;
        }
        else if (temp > n)
        {
            return 0;
        }
        else if (dp[n][base] != -1)
        {
            return dp[n][base];
        }

        //we choose the current base or we donot choose the current base
        return dp[n][base] = helper(n - temp, x, base + 1) + helper(n, x, base + 1);
    }


    long long int numOfWays(int n, int x)
    {
        // code here
        int num = pow(n, 1.0 / x);
        dp.resize(n + 1, vector<long long>(num + 1, -1));
        //return util(n, x, num);
        return helper(n, x, 1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout << ob.numOfWays(n, x) << endl;
    }
    return 0;
}
// } Driver Code Ends