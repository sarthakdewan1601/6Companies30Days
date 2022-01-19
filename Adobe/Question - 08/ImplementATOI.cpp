// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int i, j, k;
        int n = str.size();
        for (i = 0; i < n; i++)
        {
            if ((str[i] > '9' || str[i] < '0') && (str[i] != '-'))
            {
                return -1;
            }
        }

        i = 0;
        bool flag = false; //positive
        int ans = 0;
        while (i < n)
        {
            if (i == 0 && str[i] == '-')
            {
                flag = true; //negative
                i++;
                continue;
            }
            ans = ans * 10 + (str[i] - '0');
            i++;
        }

        if (flag)
        {
            return ans * -1;
        }
        else
        {
            return ans;
        }

        // return stoi(str);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
}  // } Driver Code Ends