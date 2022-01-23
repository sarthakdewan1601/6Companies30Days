class Solution {
public:
    int helper(vector<int>& weights, int n, int days, int mid)
    {
        int d = 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {

            sum += weights[i];
            if (sum > mid)
            {
                d++;
                sum = weights[i];
                // i--;
            }
        }
        if (d > days)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int i, j, k;
        int n = weights.size();
        int start = INT_MIN;
        int end = 0;
        int mid;
        for (i = 0; i < n; i++)
        {
            start = max(start, weights[i]);
        }
        for (i = 0; i < n; i++)
        {
            end += weights[i];
        }
        if (days == 1)
        {
            return end;
        }
        else if (days == n)
        {
            return start;
        }
        int res = 0;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            // cout<<mid<<endl;
            int ans = helper(weights, n, days, mid);
            if (ans == 0)
            {
                res = mid;
                end = mid - 1;
            }
            else if (ans == 1)
            {
                start = mid + 1;
            }
        }
        return res;
    }
};