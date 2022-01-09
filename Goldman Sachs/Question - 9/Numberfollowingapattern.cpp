// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  string printMinNumberForPattern(string S) {
    // code here
    stack<string> s;
    string ans = "";
    int num = 1;
    int n = S.size();
    for (int i = 0; i < n; i++)
    {
      if (S[i] == 'D')
      {
        s.push(to_string(num));
        num++;
      }
      else
      {
        s.push(to_string(num));
        num++;

        while (s.size() > 0)
        {
          ans += s.top();
          s.pop();
        }
      }
    }
    s.push(to_string(num));
    while (s.size() > 0)
    {
      ans += s.top();
      s.pop();
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
    string S;
    cin >> S;
    Solution ob;
    cout << ob.printMinNumberForPattern(S) << endl;
  }
  return 0;
}
// } Driver Code Ends