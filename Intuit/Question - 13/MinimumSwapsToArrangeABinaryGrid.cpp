class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int swaps = 0;
        int i, j, k;
        int n = grid.size();
        vector<pair<int, int>> trail;
        for (i = 0; i < n; i++)
        {
            for (j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 1)
                {
                    trail.push_back({n - j - 1, i});
                    break;
                }
            }
            if (j == -1)
            {
                trail.push_back({n, i});
            }
        }
        // for(i=0;i<n;i++)
        // {
        //     cout<<trail[i].first<<" "<<trail[i].second<<endl;
        // }
        for (i = 0; i < n; i++)
        {
            bool check = true;
            int required_trail = n - i - 1;
            // cout<<required_trail<<endl;
            if (trail[i].first >= required_trail) continue;
            else
            {
                for (j = i + 1; j < n; j++)
                {
                    if (trail[j].first >= required_trail)
                    {
                        // cout<<j<<endl;
                        check = false;
                        swaps += (j - i);
                        for (k = j; k > i; k--)
                        {
                            swap(trail[k], trail[k - 1]);
                        }
                        break;
                    }
                }
                if (check)
                {
                    return -1;
                }
            }
        }
        return swaps;
    }
};