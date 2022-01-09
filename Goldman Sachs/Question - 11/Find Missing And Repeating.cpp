class Solution{
  public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int i,j,k;
        int *ans = new int[2];
        for(i=0;i<n;i++)
        {
            if(arr[abs(arr[i]) - 1] < 0)
            {
                ans[0] = abs(arr[i]);
            }
            else
            {
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            }
        }
        for(i = 0; i < n ; i++)
        {
            if(arr[i] > 0)
            {
                ans[1] = i+1;
            }
        }
        return ans;
    }
};
