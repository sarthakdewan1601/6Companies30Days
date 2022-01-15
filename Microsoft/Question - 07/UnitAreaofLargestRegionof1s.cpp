// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find unit area of the largest region of 1s.

    void bfs(vector<vector<int>> &grid, int r, int c, int &count)
    {
        queue<pair<int, int>> q;

        // int direction1[5] = {0,-1,0,1,0};
        // int direction2[5] = {-1,-1,1,1,-1};
        vector<pair<int, int>> dir = {
            { -1, 0 },
            {1, 0   },
            {0, 1   },
            {0, -1  },
            { -1, -1},
            {1, 1   },
            { -1, 1 },
            {1, -1  }
        };


        q.push({r, c});
        // visited[r][c] = 1;

        // int count = -1;

        while (!q.empty())
        {
            int r1 = q.front().first;
            int c1 = q.front().second;
            q.pop();
            for (int k = 0; k < dir.size(); k++)
            {
                int x = r1 + dir[k].first;
                int y = c1 + dir[k].second;
                if (x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0 || grid[x][y] == 0)
                {
                    continue;
                }
                grid[x][y] = 0;
                q.push({x, y});
            }
            count++;
        }
        // return count;
    }

    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int res = 1;
        // vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));

        int i, j, k;
        for (i = 0; i < grid.size(); i++)
        {
            for (j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int count = -1;
                    bfs(grid, i, j, count);
                    // cout<<count<<endl;
                    res = max(res, count);
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>>grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends