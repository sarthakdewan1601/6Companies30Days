// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

template <typename T>
class Graph {


	map<T, list<T>> l;


public:


	void addEdge(T x , T y)
	{
		l[x].push_back(y);
	}

	string topological_sort()
	{
		//calculate the indegree for each of the node
		map<T, int> indegree;
		string answer = "";
		for (auto i : l)
		{
			indegree[i.first] = 0;
		}
		for (auto i : l)
		{
			for (auto j : l[i.first])
			{
				//if (j != "NULL")
				indegree[j]++;
			}
		}
// 		vector<T> result;
		queue<T> s;
		for (auto i : l)
		{
			if (indegree[i.first] == 0)
			{
				s.push(i.first);
			}
		}
		while (!s.empty())
		{
			T node = s.front();
			s.pop();
			//result.push_back(node);
			answer.push_back(node);
			for (auto i : l[node])
			{
				indegree[i]--;
				if (indegree[i] == 0)
				{
					s.push(i);
				}
			}
		}

		return answer;

// 		if (result.size() != l.size())
// 		{
// 			cout << "The graph has a cycle.." << endl;
// 		}
// 		else
// 		{
// 			cout << "The topological sort order is given by : ";
// 			for (auto i : result)
// 			{
// 				cout << i << " ";
// 			}
// 			cout << endl;
// 		}
	}


};
class Solution {
public:
	string findOrder(string dict[], int N, int K) {
		//code here
		int i, j, k;
		Graph<char> g;
		for (i = 1; i < N; i++)
		{
			string s1 = dict[i - 1];
			string s2 = dict[i];

			for (j = 0; j < min(s1.size(), s2.size()) ; j++)
			{
				if (s1[j] != s2[j])
				{
					g.addEdge(s1[j], s2[j]);
					break;
				}
			}
		}

		string answer = g.topological_sort();
		return answer;
	}
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
	int p1 = 0;
	int p2 = 0;
	for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
		p1 = order.find(a[i]);
		p2 = order.find(b[i]);
		//	cout<<p1<<" "<<p2<<endl;
	}

	if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

	return p1 < p2;
}

// Driver program to test above functions
int main() {
	int t;
	cin >> t;
	while (t--) {
		int N, K;
		cin >> N >> K;
		string dict[N];
		for (int i = 0; i < N; i++) cin >> dict[i];

		Solution obj;
		string ans = obj.findOrder(dict, N, K);
		order = "";
		for (int i = 0; i < ans.size(); i++) order += ans[i];

		string temp[N];
		std::copy(dict, dict + N, temp);
		sort(temp, temp + N, f);

		bool f = true;
		for (int i = 0; i < N; i++)
			if (dict[i] != temp[i]) f = false;

		if (f)cout << 1;
		else cout << 0;
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends