
// } Driver Code Ends
class Solution {
public:

    bool helper(vector<vector<char>>& board, string word, int start, int i, int j, int n, int m,
                vector<vector<bool>> &visited)
    {
        //base case
        if (start == word.size())
        {
            return true;
        }
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] ||
                board[i][j] != word[start]) return false;


        //implementation
        int dir1[4] = {0, 0, 1, -1};
        int dir2[4] = {1, -1, 0, 0};
        bool ans = false;
        int k = 0;
        visited[i][j] = true;
        for (k = 0; k < 4; k++)
        {
            int x = i + dir1[k];
            int y = j + dir2[k];

            if (helper(board, word, start + 1, x, y, n, m, visited)) return true;
        }
        visited[i][j] = false;
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int i, j, k;
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m ; j++)
            {
                if (board[i][j] == word[0] && helper(board, word, 0, i, j, n, m, visited))
                {
                    // helper(board,word,0,i,j,n,m,visited);
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>>board(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(board, word);
        if (ans)
            cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends