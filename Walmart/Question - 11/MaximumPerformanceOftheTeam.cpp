class Solution {
public:
    struct helper
    {
        int spd;
        int eff;
    };

    static bool compare(helper a, helper b)
    {
        if (a.eff > b.eff)
        {
            return true;
        }
        return false;
    }

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long int i, j;
        helper arr[n];
        for (i = 0; i < n; i++)
        {
            arr[i].spd = speed[i];
            arr[i].eff = efficiency[i];
        }
        sort(arr, arr + n, compare);
        // for(i=0;i<n;i++)
        // {
        //     cout<<arr[i].spd<<" "<<arr[i].eff<<endl;
        // }
        priority_queue<long int, vector<long int>, greater<long int>> pq; //for speed min-heap
        i = 0;
        j = 0;
        long int totalSpeed = 0;
        long int ans = INT_MIN;
        for (i = 0; i < n; i++)
        {
            if (pq.size() == k)
            {
                long int temp = pq.top();
                pq.pop();
                totalSpeed -= temp;
            }
            pq.push(arr[i].spd);
            totalSpeed += arr[i].spd;
            long performance =  totalSpeed * arr[i].eff;
            ans = max(ans, performance);
        }
        return ans % 1000000007;
    }
};