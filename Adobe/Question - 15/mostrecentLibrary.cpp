#include<bits/stdc++.h>
using namespace std;

void tokenize(string s, string del, vector<string> &str)
{
	int start = 0;
	int end = s.find(del);
	while (end != -1) {
		// cout << s.substr(start, end - start) << endl;
		str.push_back(s.substr(start, end - start));
		start = end + del.size();
		end = s.find(del, start);
	}
	// cout << s.substr(start, end - start);
	str.push_back(s.substr(start, end - start));
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	vector<string> str1;
	vector<string> str2;
	tokenize(s1, ".", str1);
	tokenize(s2, ".", str2);

	int i;
	bool flag = false;
	for (i = 0; i < min(str1.size(), str2.size()); i++)
	{
		if (str1[i] == str2[i]) continue;
		if (str1[i] < str2[i])
		{
			flag = true;
			cout << s2 << endl;
		}
		else
		{
			flag = true;
			cout << s1 << endl;
		}
	}
	if (str1.size() < str2.size() && flag == false) cout << s2 << endl;
	return 0;
}