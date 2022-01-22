// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << missingNumber(str) << endl;
    }
    return 0;
}
// } Driver Code Ends

long long sti(string s)
{
    long long x = 0;
    for (int i = 0; i < s.size(); i++)
        x = x * 10 + s[i] - '0';
    return x;
}
/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str)
{
    // Code here
    int n = str.length();
    int i, j, k;
    for (int len = 1; len <= 6; len ++)
    {
        string temp = "";
        i = 0;
        int l = len;
        while (i < n && l--)
        {
            temp += str[i++];
        }
        int prev = sti(temp);
        int miss;
        int flag = 0;
        int count = 0;
        temp = "";
        j = i;
        while (j < n)
        {
            temp += str[j++];
            if (prev + 1 == sti(temp))
            {
                prev = sti(temp);
                temp = "";
            }
            else if (prev + 2 == sti(temp))
            {
                count++;
                miss = prev + 1;
                prev = sti(temp);
                temp = "";
            }
            else if (prev < sti(temp))
            {
                flag = 1;
            }
        }
        if (count == 1 && flag == 0)
        {
            return miss;
        }
    }
    return -1;
}