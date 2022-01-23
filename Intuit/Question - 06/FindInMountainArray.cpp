/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch1(MountainArray &mountainArr, int start, int end, int &ind, int target)
    {
        while (start <= end)
        {
            // cout<<start<<" "<<end<<endl;
            int mid = start + (end - start) / 2;
            // cout<<mid<<endl;
            int ele = mountainArr.get(mid);
            if (ele == target)
            {
                //cout<<"Yes"<<endl;
                ind = mid;
                return ind;
            }
            else if (ele < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
    int binarySearch2(MountainArray &mountainArr, int start, int end, int &ind, int target)
    {
        while (start <= end)
        {
            // cout<<start<<" "<<end<<endl;
            int mid = start + (end - start) / 2;
            // cout<<mid<<endl;
            int ele = mountainArr.get(mid);
            if (ele == target)
            {
                //cout<<"Yes"<<endl;
                ind = mid;
                return ind;
            }
            else if (ele > target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = 0;
        int n = mountainArr.length();
        int end = n - 1;
        while (peak != end)
        {
            int mid = peak + (end - peak) / 2;
            int ele = mountainArr.get(mid);
            if (ele < mountainArr.get(mid + 1))
                peak = mid + 1;
            else if (ele > mountainArr.get(mid + 1))
                end = mid;
        }
        // cout<<peak<<endl;
        //iterate in first half
        int start = 0;
        end = peak;
        int ind = -1;
        ind = binarySearch1(mountainArr, start, end, ind, target);
        if (ind != -1)
        {
            return ind;
        }
        start = peak + 1;
        end = n - 1;
        ind = binarySearch2(mountainArr, start, end, ind, target);
        return ind;
    }
};