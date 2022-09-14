#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int ret = -1;
        if (len == 0) return ret;
        if (len == 1) return nums[0] == target? 0:-1;
        int left = 0;
        int right = len - 1;

        while(left < right)
        {
            int mid = (left + right)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid-1;
            else left = mid+1;
        }
        return ret;
    }
};

int main()
{
    vector<int> nums;
    int target;
    cout<<"Input nums vector: [,]:continue, [enter]:finish input"<<endl;
    int temp;
    while(cin>>temp)
    {
        nums.push_back(temp);
        if(cin.get() == '\n') break;
    }
    cout<<"Input target:"<<endl;
    while(cin>>target)
    {
        if(cin.get() == '\n') break;
    };
    Solution s;
    cout<<"result:"<<s.search(nums,target)<<endl;
    return 0;
}