// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends
class Solution {
public:
    //You need to complete this fucntion
    //int mod = 1000000007;

    // long long helper(int long long n,int long long r)
    // {
    //     if(r == 0)
    //     {
    //         return 1;
    //     }
    //     long long res = (pow(n,r/2));
    //     res = ((res%mod)*(res%mod))%mod;
    //     if(r%2 == 0)
    //     {
    //         return res%mod;
    //     }
    //     else
    //     {
    //         return ((res%mod)*(n%mod))%mod;
    //     }
    // }

    long long power(long long int n, long long int r)
    {
        //Your code here
        // return helper(n,r)%mod;
        if (r == 1) return n % mod;
        if (r == 0) return 1;

        long long int ans = 1;
        long long temp = power(n, r / 2) % mod;

        if (r % 2 != 0)
        {
            ans = (ans * n) % mod;
        }
        return (ans * ((temp * temp) % mod)) % mod;
    }

};

// { Driver Code Starts.

// compute reverse of a number
long long rev(long long n)
{
    long long rev_num = 0;
    while (n > 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n = n / 10;
    }
    return rev_num;
}




int main()
{
    int T;
    cin >> T; //testcases

    while (T--)
    {
        long long N;
        cin >> N; //input N

        long long R = 0;

        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans = ob.power(N, R);
        cout << ans << endl;
    }
}  // } Driver Code Ends