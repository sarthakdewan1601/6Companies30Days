class Solution {
public:

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& ocean, int prevHeight)
    {
        int n = heights.size();
        int m = heights[0].size();
        int dir1[4] = {0, 0, -1, 1};
        int dir2[4] = {1, -1, 0, 0};
        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            return;
        }
        if (heights[i][j] < prevHeight || ocean[i][j] == true)
        {
            return;
        }

        ocean[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            dfs(heights, i + dir1[k], j + dir2[k], ocean, heights[i][j]);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //approach -
        //we check from the top and left first
        //then we check from right and bottom

        int i, j, k;
        int n = heights.size();
        int m = heights[0].size();
        // vector<vector<bool>> visited(n,vector<bool>(m,false));
        // vector<vector<char>> color(n,vector<char>(m,'w'));
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        //for pacific ocean
        //top row
        for (i = 0; i < m; i++)
        {
            //int start = heights[0][i];
            // color[0][i] = 'b';
            dfs(heights, 0, i, pacific, INT_MIN);
            dfs(heights, n - 1, i, atlantic, INT_MIN);
        }
        //left column
        for (i = 0; i < n; i++)
        {
            dfs(heights, i, 0, pacific, INT_MIN);
            dfs(heights, i, m - 1, atlantic, INT_MIN);
        }

        //returned of all dfs i'll find the coomon ones
        vector<vector<int>> result;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if ((pacific[i][j] && atlantic[i][j]))
                {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};