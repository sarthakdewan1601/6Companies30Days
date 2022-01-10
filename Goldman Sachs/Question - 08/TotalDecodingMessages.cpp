// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  /*
      bool valid(string s, int i, int j)
      {
          if(stoi(s.substr(i,j-i+1)) <= 26 && stoi(s.substr(i,j-i+1)) >= 1 &&
              s[i] != '0')
          {
              return true;
          }
          return false;
      }

      void helper(string s, int index, vector<string> &path, vector<vector<string>> &result)
      {
          if(index == s.size())
          {
              result.push_back(path);
              return;
          }
          for(int i = index;i<s.size();i++)
            {
                if(s[i] == '0')
                {
                    continue;
                }
                if(valid(s,index,i))
                {
                    path.push_back(s.substr(index,i-index+1));
                    helper(s,i+1,path,result);
                    path.pop_back();
                }
            }
      }
  */


  int CountWays(string s) {
    // Code here

    //main solution here
    //the above approach failed so i had to go through this one

    int n = s.size();
    if (s[0] == '0') return 0;
    for (int i = 0; i < n - 1; i++)
    {
      if (s[i] == '0' && s[i + 1] == '0') return 0;
    }
    if (s.size() == 1) return 1;

    int dp[n];
    dp[0] = 1;
    int i, j, k;
    for (i = 1; i < n; i++)
    {
      if (s[i] == '0' && s[i - 1] == '0')
      {
        dp[i] = 0;
      }
      else if (s[i - 1] == '0' && s[i] != '0')
      {
        dp[i] = dp[i - 1] % 1000000007;
      }
      else if (s[i - 1] != '0' && s[i] == '0')
      {
        if (s[i - 1] == '1' || s[i - 1] == '2')
        {
          dp[i] = (i >= 2 ? dp[i - 2] % 1000000007 : 1) % 1000000007;
        }
        else
        {
          dp[i] = 0;
        }
      }
      else
      {
        dp[i] = dp[i - 1] % 1000000007;
        if (stoi(s.substr(i - 1, 2)) <= 26)
        {
          dp[i] += (i >= 2 ? dp[i - 2] % 1000000007 : 1) % 1000000007;
        }
      }
    }
    return dp[n - 1] % 1000000007;

  }
};

// { Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string str;
    cin >> str;
    Solution obj;
    int ans = obj.CountWays(str);
    cout << ans << "\n";
  }
  return 0;
}  // } Driver Code Ends