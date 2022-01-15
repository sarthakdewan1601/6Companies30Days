// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    //Function to find list of all words possible by pressing given numbers.
    void helper(int a[] , int n , unordered_map<int, string> &umap, int index,
                vector<string> &answer, string &curr)
    {
        //base case
        if (index >= n)
        {
            answer.push_back(curr);
            return;
        }

        //rest of the code if base case is not satisfied
        for (auto ch : umap[a[index]])
        {
            curr.push_back(ch);
            helper(a, n, umap, index + 1, answer, curr);
            curr.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> answer;
        string curr = "";
        helper(a, n, mp, 0, answer, curr);
        return answer;
    }
};


// { Driver Code Starts.

int main() {

    int T;

    cin >> T; //testcases

    while (T--) { //while testcases exist
        int N;

        cin >> N; //input size of array

        int a[N]; //declare the array

        for (int i = 0; i < N; i++) {
            cin >> a[i]; //input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector <string> res = obj.possibleWords(a, N);
        for (string i : res) cout << i << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends