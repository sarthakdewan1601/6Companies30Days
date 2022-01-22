// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:

    int subsetsum(int arr[] , int n , int range)
    {
        bool dp[n + 1][range + 1];

        //initialisation
        int i, j, k;
        //when we have n = 0 we can make no subsets
        for (i = 0; i <= range; i++)
        {
            dp[0][i] = false;
        }
        //when we have sum = 0, we can make 1 subset
        for (i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        //fill the table
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= range; j++)
            {
                if (arr[i - 1] <= j) //choices - it can be included or it cannot be
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else //no choice, it has to be excluded
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        //return the answer
        //we know we have to minimize(range - 2*s1)
        vector<int> vec;
        for (i = 0; i <= range / 2; i++) // rest of the sum will be in second half = range - s1 = s2
        {
            // cout<<dp[n][i]<<" ";
            if (dp[n][i] == true)
            {
                vec.push_back(i);
            }
        }
        // cout<<endl;
        int mn = INT_MAX;
        for (i = 0; i < vec.size(); i++)
        {
            mn = min(mn, range - (2 * vec[i]));
        }
        return mn; //answer
    }

    int minDifference(int arr[], int n)  {
        // Your code goes here
        int sum = 0;
        int i , j, k;
        for (int i = 0; i < n ; i++)
        {
            sum += arr[i];
        }
        int answer = subsetsum(arr, n, sum);
        return answer;
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

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.minDifference(a, n) << "\n";

    }
    return 0;
}  // } Driver Code Ends