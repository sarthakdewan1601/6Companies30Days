class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long int product = 1;
        int i,j = 0;
        int count = 0;
        for(i=0;i<n;i++)
        {
            product *= a[i];
            
            while(product >= k && j <= i)
            {
                product /= a[j];
                j++;
            }
            
            count += (i-j+1);
        }
        return count;
    }
};
