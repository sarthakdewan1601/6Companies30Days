// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    int lis(vector<int> &temp)
    {
        vector<int> res;
        if (temp.size() > 0) res.push_back(temp[0]);

        for (int i = 1; i < temp.size() ; i++)
        {
            if (temp[i] > res.back()) res.push_back(temp[i]);
            else
            {
                int id = lower_bound(res.begin(), res.end(), temp[i]) - res.begin();
                res[id] = temp[i];
            }
        }
        return res.size();
    }


    int minInsAndDel(int a[], int b[], int n, int m) {
        // code here
        vector<int> temp;
        int i , j, k;
        for (i = 0; i < n; i++)
        {
            if (binary_search(b, b + m, a[i]))
            {
                temp.push_back(a[i]);
            }
        }

        return n + m - (2 * lis(temp));
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        int A[N], B[M];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < M; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.minInsAndDel(A, B, N, M) << endl;
    }
    return 0;
}  // } Driver Code Ends