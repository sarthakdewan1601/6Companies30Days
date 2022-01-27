class Solution {
public:
   static bool compare_function(string str1, string str2)
   {
      int n1 = str1.length(), n2 = str2.length();

      if (n1 < n2)
         return true;
      if (n2 < n1)
         return false;

      // If lengths are same
      for (int i = 0; i < n1; i++)
      {
         if (str1[i] < str2[i])
            return true;
         if (str1[i] > str2[i])
            return false;
      }

      return false;
   }
   string kthLargestNumber(vector<string>& nums, int k) {
      int n = nums.size();
      int i, j;
      sort(nums.begin(), nums.end(), compare_function);
      // for(i = 0; i< n;i++)
      // {
      //     cout<<nums[i]<<" ";
      // }
      // cout<<endl;
      return nums[n - k];
   }
};