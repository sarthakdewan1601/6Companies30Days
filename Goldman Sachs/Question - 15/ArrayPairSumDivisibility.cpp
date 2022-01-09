// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if (nums.size() % 2 != 0) return false;
        int i, j, n = nums.size();
        unordered_map<int, int> umap;
        for (i = 0; i < n; i++)
        {
            umap[nums[i] % k]++;
        }
        for (i = 0; i < n; i++)
        {
            int rem = nums[i] % k;

            if (rem == 0)
            {
                if (umap[rem] % 2 != 0)
                {
                    return false;
                }
            }
            else if (2 * rem == k)
            {
                if (umap[rem] % 2 != 0)
                {
                    return false;
                }
            }
            else
            {
                if (umap[rem] != umap[k - rem]) return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends