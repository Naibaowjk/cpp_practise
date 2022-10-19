#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return ;
        int end = 0;
        bool is_change = false;
        for (int i=len-2; i>=end; i--)
        {
            int min_val = INT_MAX;
            int min_index = -1;
            for (int j = i+1; j<len; j++)
            {
                if (nums[j] > nums[i])
                {
                    min_val = min(nums[j], min_val);
                    min_index = j;
                }
            }
            if (min_index != -1)
            {
                int temp = nums[i];
                nums[i] = nums[min_index];
                nums[min_index] = temp; 
                is_change = true;
                sort(nums.begin()+i+1, nums.end(), less<int>());
                return;
            }
        }
        sort(nums.begin(), nums.end(), less<int>());
    }
};

int main()
{
    vector<int> nums{1,2,3};
    Solution s1;
    s1.nextPermutation(nums);
    return 0;
}