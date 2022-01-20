// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function
// function should print the required range
class Solution {
public:
  pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
  {
    //code here
    vector<pair<int, int>> arr;
    int i, j;
    for (i = 0; i < k; i++)
    {
      for (j = 0; j < n; j++)
      {
        arr.push_back({KSortedArray[i][j] , i});
      }
    }

    sort(arr.begin(), arr.end());

    int count = k;
    i = 0;
    j = 0;
    int size = arr.size();
    int min = INT_MAX;
    pair<int, int> answer;
    unordered_map<int, int> umap;


    //concept of sliding window used


    while (j < size)
    {
      pair<int, int> temp = arr[j];
      int val = temp.first;
      int id = temp.second;
      umap[id]++;
      if (umap.size() < count) j++;
      else if (umap.size() == count)
      {
        while (umap.size() == count)
        {
          //check if it is the smallest range
          if (arr[j].first - arr[i].first + 1 < min)
          {
            min = arr[j].first - arr[i].first + 1;
            answer = {arr[i].first, arr[j].first};
          }
          umap[arr[i].second]--;
          if (umap[arr[i].second] == 0)
          {
            umap.erase(arr[i].second);
          }
          i++;
        }
        j++;
      }
    }
    return answer;
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    int arr[N][N];
    pair<int, int> rangee;
    for (int i = 0; i < k; i++)
      for (int j = 0; j < n; j++)
        cin >> arr[i][j];
    Solution obj;
    rangee = obj.findSmallestRange(arr, n, k);
    cout << rangee.first << " " << rangee.second << "\n";
  }
  return 0;
}

// } Driver Code Ends