// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here

        /*
        Approach -
        1. First use the concept of two sum
        2. Then use the concept of three sum
        */

        int i, j, l;
        int n = arr.size();
        set<vector<int>> st; // I had to use set, since my solution was giving TLE for some reason
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        for (i = 0; i < n - 3; i++)
        {
            for (j = i + 1; j < n - 2; j++)
            {
                int start = j + 1;
                int end = n - 1;
                while (start < end)
                {
                    int sum = arr[i] + arr[j] + arr[start] + arr[end];
                    if (sum == k)
                    {

                        vector<int> elements = {arr[i], arr[j], arr[start], arr[end]};
                        //This method was giving tle
                        // if(!std::count(result.begin(), result.end(), elements))
                        //     result.push_back({arr[i],arr[j],arr[start],arr[end]});
                        // result.push_back(elements);
                        st.insert(elements);
                        start++;
                        end--;
                    }
                    else if (sum < k)
                    {
                        start++;
                    }
                    else
                    {
                        end--;
                    }
                }
            }
        }
        result.insert(result.begin() , st.begin(), st.end());
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends