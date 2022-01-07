class Solution {
  public:
    int findPosition(int n , int m , int k) {
        // code here
        int temp = n-k+1;
        int temp2 = m - temp;
        if(m+k <= n+1)
        {
            return m+k-1;
        }
        else
        {
            int ans = temp2%n;
            if(ans == 0)
            {
                return n;
            }
            else
            {
                return ans;
            }
        }
    }
};
