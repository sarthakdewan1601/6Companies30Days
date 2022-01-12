class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        int i, j, k;
        for (i = 0; i < 9; i++)
        {
            unordered_map<char, int> umap;
            for (j = 0; j < 9; j++)
            {
                if (mat[i][j] != '.' && umap.find(mat[i][j]) != umap.end() && umap[mat[i][j]] >= 1)
                {
                    // cout<<i<<" "<<j<<endl;
                    // cout<<"Hello1"<<endl;
                    return false;
                }
                umap[mat[i][j]]++;
            }
        }
        //each column
        for (i = 0; i < 9; i++)
        {
            unordered_map<int, int> umap;
            for (j = 0; j < 9; j++)
            {
                if (mat[j][i] != '.' && umap.find(mat[j][i]) != umap.end() && umap[mat[j][i]] >= 1)
                {
                    // cout<<"Hello2"<<endl;
                    return false;
                }
                umap[mat[j][i]]++;
            }
        }
        int l;
        for (i = 0; i < 9 ; i += 3)
        {
            for (j = 0; j < 9 ; j += 3)
            {
                unordered_map<int, int> umap;
                int a = i;
                int b = j;
                for (k = a; k < a + 3; k++)
                {
                    for (l = b; l < b + 3 ; l++)
                    {
                        if (mat[k][l] != '.' && umap.find(mat[k][l]) != umap.end() && umap[mat[k][l]] >= 1)
                        {
                            // cout<<"Hello3"<<endl;
                            return false;
                        }
                        umap[mat[k][l]]++;
                    }
                }
            }
        }
        return true;
    }
};