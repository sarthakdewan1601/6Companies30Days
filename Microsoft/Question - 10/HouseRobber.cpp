// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int nums[], int n)
    {
        // Your code here
        // int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        else if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        int i, j, k;
        int arr[n];
        arr[0] = nums[0];
        arr[1] = nums[1];
        arr[2] = nums[0] + nums[2];
        for (i = 3; i < n; i++)
        {
            arr[i] = nums[i] + max(arr[i - 3], arr[i - 2]);
        }
        int ans = INT_MIN;
        for (i = 0; i < n; i++)
        {
            ans = max(ans, arr[i]);
        }
        return ans;
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
        //taking number of houses
        int n;
        cin >> n;
        int a[n];

        //inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        //calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends