class Solution {
public:

    bool isPossible(vector<int>& nums, int m, int mid)
    {
        int count = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > mid)
            {
                count++;
                sum = 0;
                i--;
            }
        }
        if (count <= m)
        {
            return true;
        }
        else return false;
    }

    int splitArray(vector<int>& nums, int m) {
        int i, j, k;
        int start = INT_MIN;
        int end = 0;
        int n = nums.size();
        for (i = 0; i < n; i++)
        {
            end += nums[i];
            start = max(start, nums[i]);
        }
        if (m == 1)
        {
            return end;
        }
        if (m == n)
        {
            return start;
        }
        int res;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            cout << mid << endl;
            if (isPossible(nums, m, mid) == true)
            {
                res = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return res;
    }
};