class Solution {
public:
    int dp[201][201];
    int helper(int start, int end)
    {
        //base conditions
        if (start >= end)
        {
            return 0;
        }
        if (dp[start][end] != -1) return dp[start][end];

        int ans = INT_MAX;
        //hypothesis
        int i;
        for (i = start; i <= end; i++)
        {
            int temp = i;
            temp += max(helper(start, i - 1) , helper(i + 1, end));
            ans = min(ans, temp);
        }

        //induction
        return dp[start][end] = ans;
    }

    int getMoneyAmount(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        memset(dp, -1, sizeof(dp));
        int start = 1;
        int end = n;
        return helper(start, end);
    }
};