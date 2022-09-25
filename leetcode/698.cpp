#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool cmp(int i, int j)
    {
        return i>j;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        vector<bool> flag(k,false);
        bool ret = true;
        vector<int> part(k,0);
        int sum = 0;
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
        {
            sum+=*i;
        }
        int each_sum = sum / k;
        if (sum % k != 0 ) return false;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (part[j] == each_sum) {continue;}
                else if (part[j] + nums[i] <= each_sum){
                    part[j]+= nums[i];
                    flag[i] = true;
                    break;
                }
                else if(part[j]+ nums[i] > each_sum) continue;
            }
        }
        // check
        for (int i = 0; i <k ;i++) ret &= (part[i] == each_sum);
        if (ret == false) return false;
        for (int i = 0; i< nums.size(); i++) ret&= (flag[i] == true);
        return ret;
    }
};

int main()
{
    int k = 5;
    vector<int> nums{3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269};
    Solution s1;
    bool ret = s1.canPartitionKSubsets(nums,k);
    return 0;
}