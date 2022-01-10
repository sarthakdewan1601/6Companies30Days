class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i, j, k, n = arr.size();
        int sub_size = 0;
        int ans = INT_MIN;
        for (i = 1; i < n - 1; i++)
        {
            int count = 1;
            //if peak
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                j = i;
                while (j > 0 && arr[j] > arr[j - 1])
                {
                    count++;
                    j--;
                }
                j = i;
                while (j < n - 1 && arr[j] > arr[j + 1])
                {
                    count++;
                    j++;
                }
                ans = max(ans, count);
            }
            // return ans;
        }
        if (ans == INT_MIN) return 0;
        return ans;
    }
};