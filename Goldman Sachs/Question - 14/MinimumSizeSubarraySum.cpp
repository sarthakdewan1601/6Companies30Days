class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0,j = 1,k,n = nums.size();
        int answer = INT_MAX;
        if(nums[0] >= target) return 1;
        int count = 2;
        int sum = nums[0];
        int flag = 0;
        while(i <= j && j < n && i < n)
        {
            if(flag == 0) sum += nums[j];
            if(sum >= target)
            {
                answer = min(answer,count);
                sum -= nums[i];
                i++;
                count--;
                flag = 1;
            }
            else
            {
                flag = 0;
                count++;
                j++;
            }
        }
        if(answer == INT_MAX) return 0;
        return answer;
    }
};
