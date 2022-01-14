// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int n)
{
	// Your code here
	vector<string> ans;
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		string temp = bitset<64>(i).to_string();
		const auto loc1 = temp.find('1');

		if (loc1 != string::npos)
			ans.push_back(temp.substr(loc1));
	}
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<string> ans = generate(n);
		for (auto it : ans) cout << it << " ";
		cout << endl;
	}
	return 0;
}  // } Driver Code Ends