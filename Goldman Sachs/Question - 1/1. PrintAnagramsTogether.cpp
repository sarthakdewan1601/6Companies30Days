class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& strs) {
        //code here
        vector<vector<string>> result;
        int i,j,k;
        int n = strs.size();
        vector<string> blank;
        int count = 0;
        for(i=0;i<n;i++)
        {
            if(strs[i] == "")
            {
                count++;
                blank.push_back(strs[i]);
            }
        }
        if(count != 0)
            result.push_back(blank);
        for(i=0;i<n;i++)
        {
            if(strs[i] == "-1" || strs[i] == "")
            {
                continue;
            }
            vector<string> temp;
            temp.push_back(strs[i]);
            unordered_map<char,int> original;
            for(j = 0; j < strs[i].size(); j++)
            {
                original[strs[i][j]]++;
            }
            for(j = i + 1; j < n ; j++)
            {
                bool check = true;
                unordered_map<char,int> umap;
                for(k = 0 ; k < strs[j].size(); k++)
                {
                    umap[strs[j][k]]++;
                }
                if(umap.size() == original.size())
                {
                    for(auto it : original)
                    {
                        if(umap.find(it.first) == umap.end())
                        {
                            check = false;
                            break;
                        }
                        else if(umap.find(it.first) != umap.end()
                               && umap[it.first] != it.second)
                        {
                            check = false;
                            break;
                        }
                    }
                }
                else
                {
                    check = false;
                }
                if(check == false)
                {
                    continue;
                }
                else
                {
                    temp.push_back(strs[j]);
                    strs[j] = "-1";
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};
