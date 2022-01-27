// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    string max_str;
    //Function to find the largest number after k swaps.

    void helper(string str, int k, int curr_index)
    {
        //base condition
        if (k == 0)
        {
            return;
        }
        int n = str.size();

        //finding maximum digit from curr index to the end of the string
        char max_digit = str[curr_index];
        for (int i = curr_index + 1; i < n ; i++)
        {
            if (max_digit < str[i])
            {
                max_digit = str[i];
            }
        }

        //if this maximum digit is not at the current index then we decrease the value of k
        if (max_digit != str[curr_index])
        {
            k--;
        }

        //start from the last index to curr_index and find the max_digit and swap
        //it with the curr_index

        for (int j = n - 1; j >= curr_index; j--)
        {
            if (str[j] == max_digit)
            {
                swap(str[j], str[curr_index]);

                if (str > max_str)
                {
                    max_str = str;
                }

                helper(str, k, curr_index + 1);

                swap(str[curr_index] , str[j]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        // code here.
        //   int i,j;
        max_str = str;
        helper(str, k, 0);
        return max_str;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
// } Driver Code Ends