// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    string amendSentence (string s)
    {
        // your code here
        vector<string> st;
        int i, j, k;
        int n = s.size();
        string res = "";
        for (i = 0; i < n; i++)
        {
            if (i == 0)
            {
                res.push_back(s[i]);
            }
            else
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    res.push_back(' ');
                    res.push_back(s[i]);
                }
                else
                {
                    res.push_back(s[i]);
                }
            }
        }
        transform(res.begin(), res.end(), res.begin(), ::tolower);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.amendSentence (s) << endl;
    }
}  // } Driver Code Ends