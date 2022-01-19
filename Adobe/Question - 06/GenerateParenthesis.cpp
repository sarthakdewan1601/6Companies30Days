// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
public:
    void helper(int n, vector<string> &res , int open_braces , int close_braces, string s)
    {
        //base case
        if (close_braces == 0 && open_braces == 0)
        {
            res.push_back(s);
            return;
        }

        //implementation
        if (open_braces > 0)
        {
            string st = s;
            st.push_back('(');
            helper(n, res, open_braces - 1, close_braces, st);
        }
        if (close_braces > open_braces)
        {
            string st = s;
            st.push_back(')');
            helper(n, res, open_braces, close_braces - 1, st);
        }
    }

    vector<string> AllParenthesis(int n)
    {
        // Your code goes here
        vector<string> res;
        int open_braces = n;
        int close_braces = n;
        string s;
        helper(n, res, open_braces, close_braces, s);
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
    }
    return 0;
}
// } Driver Code Ends