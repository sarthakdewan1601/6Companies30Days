class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int i, j, k;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int time = 0;
        int count = 0;
        int number = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 || grid[i][j] == 2) number++;
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while (!q.empty())
        {
            k = q.size();
            count += k;
            while (k--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1) continue;

                    grid[nx][ny] = 2;
                    // count++;
                    q.push({nx, ny});
                }
            }
            if (!q.empty()) time++;
        }
        return count == number ? time : -1;
    }
};