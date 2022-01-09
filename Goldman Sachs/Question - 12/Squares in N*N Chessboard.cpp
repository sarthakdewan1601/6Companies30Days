class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        // code here
        long long int arr[N];
        long long int i,j,k;
        arr[0] = 1;
        for(i=1;i<N;i++)
        {
            arr[i] = ((i+1)*(i+1)) + arr[i-1];
        }
        return arr[N-1];
    }
};
