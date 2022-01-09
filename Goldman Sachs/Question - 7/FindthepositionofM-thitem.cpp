// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int findPosition(int n , int m , int k) {
        // code here
        int temp = n - k + 1;
        int temp2 = m - temp;
        if (m + k <= n + 1)
        {
            return m + k - 1;
        }
        else
        {
            int ans = temp2 % n;
            if (ans == 0)
            {
                return n;
            }
            else
            {
                return ans;
            }
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;

        cin >> N >> M >> K;

        Solution ob;
        cout << ob.findPosition(N, M, K) << endl;
    }
    return 0;
}  // } Driver Code Ends