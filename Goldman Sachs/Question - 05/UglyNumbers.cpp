// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


// } Driver Code Ends
//User function template for C++
class Solution {
public:
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
		// code here
		ull arr[n + 1];
		int i;
		int c2 = 0, c3 = 0, c5 = 0;
		arr[0] = 1;
		for (i = 1; i <= n; i++)
		{
			arr[i] = min({2 * arr[c2] , 3 * arr[c3], 5 * arr[c5]});
			if (arr[i] == 2 * arr[c2])
				c2++;
			if (arr[i] == 3 * arr[c3])
				c3++;
			if (arr[i] == 5 * arr[c5])
				c5++;
		}
		return arr[n - 1];
	}
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		Solution ob;
		auto ans = ob.getNthUglyNo(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends