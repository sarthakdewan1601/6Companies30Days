// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:

    int helper(int a, int b, int i, int j)
    {
        //base condition
        if (i >= a || j >= b)
        {
            return 0;
        }
        if (i == a - 1 && j == b - 1)
        {
            return 1;
        }

        //hypothesis
        int ans = helper(a, b, i, j + 1) + helper(a, b, i + 1, j);

        //induction
        return ans;
    }

    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        return helper(a, b, 0, 0);
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking dimensions of the matrix
        int a, b;
        cin >> a >> b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a, b) << endl;
    }
}

// } Driver Code Ends