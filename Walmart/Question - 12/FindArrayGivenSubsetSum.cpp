class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int> res;
        sort(sums.begin(), sums.end());
        int m = sums.size();
        while (sums.size() > 1)
        {
            int diff = sums[sums.size() - 1] - sums[sums.size() - 2];
            unordered_map<int, int> umap;
            for (int j = 0; j < sums.size(); j++)
            {
                umap[sums[j]]++;
            }
            vector<int> excluding;
            vector<int> including;

            for (auto x : sums)
            {
                if (umap[x] > 0)
                {
                    excluding.push_back(x);
                    including.push_back(diff + x);
                    umap[x]--;
                    umap[x + diff]--;
                }
            }
            bool check = false;
            for (int j = 0; j < excluding.size(); j++)
            {
                if (excluding[j] == 0)
                {
                    // pos = j;
                    check = true;
                    break;
                }
            }
            if (check)
            {
                sums = excluding;
                res.push_back(diff);
            }
            else
            {
                sums = including;
                res.push_back(-1 * diff);
            }
        }
        return res;
    }
};