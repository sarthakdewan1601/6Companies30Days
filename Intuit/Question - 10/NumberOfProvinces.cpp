class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, int j)
    {
        isConnected[i][j] = 0;
        for (int k = 0; k < isConnected.size(); k++)
        {
            if (isConnected[j][k] == 1)
            {
                dfs(isConnected, j, k);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int i, j, k, res = 0;
        int n = isConnected.size();
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    res++;
                    dfs(isConnected, i, j);
                }
            }
        }
        return res;
    }
};