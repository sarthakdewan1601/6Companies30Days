class Solution{
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()%2 != 0) return false;
        int i,j,n = nums.size();
        unordered_map<int,int> umap;
        for(i=0;i<n;i++)
        {
            umap[nums[i]%k]++;
        }
        for(i=0;i<n;i++)
        {
            int rem = nums[i]%k;
            
            if(rem == 0)
            {
                if(umap[rem] % 2 != 0)
                {
                    return false;
                }
            }
            else if(2*rem == k)
            {
                if(umap[rem] % 2 != 0)
                {
                    return false;
                }
            }
            else
            {
                if(umap[rem] != umap[k - rem]) return false;
            }
        }
        return true;
    }
};
