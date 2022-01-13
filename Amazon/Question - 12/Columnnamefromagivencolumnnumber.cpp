// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    string colName (long long int n)
    {
        // your code here
        string ans = "";

        while (n != 0)
        {
            n--;
            int rem = n % 26;
            char ch = 'A' + rem;
            ans = ch + ans;
            n = n / 26;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        long long int n; cin >> n;
        Solution ob;
        cout << ob.colName (n) << '\n';
    }
}
// } Driver Code Ends