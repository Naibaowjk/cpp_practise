/*
 * @lc app=leetcode.cn id=1694 lang=cpp
 *
 * [1694] 重新格式化电话号码
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        string ret;
        int len = number.size();
        vector<int> nums;
        for (int i = 0; i < len; i++)
        {
            if (number[i] >= '0' && number[i] <= '9')
            {
                nums.push_back(number[i] - '0');
            }
        }
        int left = nums.size();
        int len_nums = left;
        while(left > 0)
        {
            if (left >4 )
            {
                ret+=to_string(nums[len_nums-left])+ \
                    to_string(nums[len_nums-left+1])+ \
                    to_string(nums[len_nums-left+2]) + "-";
                left-=3;
            }
            else if (left == 4)
            {
                ret+=to_string(nums[len_nums-left])+ \
                    to_string(nums[len_nums-left+1])+ "-" +\
                    to_string(nums[len_nums-left+2]) + \
                    to_string(nums[len_nums-left+3]);
                left-=4;
            }
            else
            {
                for (int i = 0; i < left; i++)
                {
                    ret+=to_string(nums[len_nums-left+i]);
                }
                left = 0;
            }
        }
        return ret;
    }
};
// @lc code=end

