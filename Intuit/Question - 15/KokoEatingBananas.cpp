class Solution {
public:

    bool isPossible(vector<int>& piles, int h, long long int mid)
    {
        long long int count = 0;
        long long int i, j;
        for (i = 0; i < piles.size(); i++)
        {
            count += ceil(1.0 * (piles[i]) / (mid));
        }
        if (count <= h)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long int i, j, k;
        long long int n = piles.size();
        long long int sum = 0;
        int max_bananas = INT_MIN;
        for (i = 0; i < n; i++)
        {
            max_bananas = max(max_bananas, piles[i]);
            sum += piles[i];
        }
        if (h == 1)
        {
            return sum;
        }
        if (h == n)
        {
            return max_bananas;
        }
        long long int start = 1;
        long long int end = max_bananas;
        int mid;
        int ans = INT_MAX;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (isPossible(piles, h, mid) == true)
            {
                ans = min(ans, mid);
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};