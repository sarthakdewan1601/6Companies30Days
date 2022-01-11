// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    void optimalparams(int i, int j, int s[100][100], char &var, string &st)
    {
        if (i == j)
        {
            st.push_back(var);
            var++;
            return;
        }

        st.push_back('(');
        optimalparams(i, s[i][j], s, var, st);
        optimalparams(s[i][j] + 1, j, s, var, st);

        st.push_back(')');
    }

    string matrixChainOrder(int p[], int n) {
        // code here
        // n = n-1;
        int m[100][100];
        int s[100][100];
        int i, j, k;
        for (i = 0; i < n ; i++)
        {
            m[i][i] = 0;
        }

        int l;
        for (l = 2; l < n ; l++)
        {
            for (i = 0; i < n - l + 1; i++)
            {
                j = i + l - 1;
                m[i][j] = INT_MAX;
                for (k = i ; k < j ; k++)
                {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[j] * p[k];
                    if (q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
        char var = 'A';
        string st;
        optimalparams(1, n - 1, s, var, st);
        return st;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];

        Solution ob;
        cout << ob.matrixChainOrder(p, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends