class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int i, j, k;
        int n = grid.size();
        int count0 = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({0, {i, j}});
                }
                else
                {
                    count0++;
                    grid[i][j] = INT_MAX;
                }
            }
        }

        if (count0 == 0 || q.size() == 0) return -1;

        int dir1[4] = {0, 0, -1, 1};
        int dir2[4] = {1, -1, 0, 0};
        int ans = 0;
        while (!q.empty())
        {
            int curr_dist = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for (k = 0; k < 4; k++)
            {
                int newx = x + dir1[k];
                int newy = y + dir2[k];

                if (newx >= 0 && newx < n && newy >= 0 && newy < n && grid[newx][newy] > curr_dist + 1)
                {
                    grid[newx][newy] = curr_dist + 1;
                    q.push({curr_dist + 1, {newx, newy}});
                    ans = max(ans, grid[newx][newy]);
                }
            }
        }
        return ans;
    }
};