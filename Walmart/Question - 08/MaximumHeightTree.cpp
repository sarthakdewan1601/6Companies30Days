// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int height(int n) {
        // code here
        int i = 1;
        if (n == 1) return 1;
        int ans = 1;
        while (ans <= n)
        {
            ans += i + 1;
            i++;
        }
        return i - 1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.height(N) << endl;
    }
    return 0;
}  // } Driver Code Ends