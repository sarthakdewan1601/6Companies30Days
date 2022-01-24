class Solution {
public:
    // int fact(int num)
    // {
    //     int temp = num;
    //     int prod = 1;
    //     while(temp != 0)
    //     {
    //         prod = prod * temp;
    //         temp--;
    //     }
    //     // cout<<prod<<endl;
    //     return prod;
    // }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int i, j, k;
        int ans = 0;
        for (i = 0; i < n; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            unordered_map<int, int> umap;
            for (j = 0; j < n; j++)
            {
                if (j != i)
                {
                    int x1 = points[j][0];
                    int y1 = points[j][1];
                    int diff = pow(x - x1, 2) + pow(y - y1, 2);
                    umap[diff]++;
                }
            }
            // for(auto j : umap)
            // {
            //     cout<<j.second<<" "<<j.first;
            //     cout<<endl;
            // }
            // cout<<endl;
            for (auto j : umap)
            {
                if (j.second >= 2)
                {
                    // cout<<j.second<<endl;
                    ans += (j.second * (j.second - 1));
                }
            }
        }
        return ans;
    }
};