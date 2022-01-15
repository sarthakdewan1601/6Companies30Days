// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
	//Function to calculate the span of stockâ€™s price for all n days.
	vector <int> calculateSpan(int price[], int n)
	{
		// Your code here
		int i, j, k;
		stack<pair<int, int>> s;
		vector<int> ans;
		s.push({price[0], 1});
		ans.push_back(1);
		for (i = 1; i < n; i++)
		{
			//   s.push(prices[i]);
			int count = 1;
			while (!s.empty() && (s.top().first <= price[i]))
			{
				count += s.top().second;
				s.pop();
			}
			ans.push_back(count);
			s.push({price[i] , count});
		}
		return ans;
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
		int i, a[n];
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);

		for (i = 0; i < n; i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends