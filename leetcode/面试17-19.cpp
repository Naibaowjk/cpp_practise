#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        vector<int> ret;
        int miss1 = 0, miss2 = 0;
        int sum_xor = 0;
        int n = nums.size()+2;
        for (int num: nums)
        {
            sum_xor ^= num;
        }
        for (int i = 1; i <= n; i++)
        {
            sum_xor ^= i;
        }
        int lowbits = (sum_xor == INT_MIN) ? sum_xor : (sum_xor&(-sum_xor));
        for (int num:nums)
        {
            if (num & lowbits) miss1 ^= num;
            else miss2 ^= num;
        }
        for (int i = 1; i<= n; i++)
        {
            if (i & lowbits) miss1 ^= i;
            else miss2 ^= i;
        }  
        ret.push_back(miss1);
        ret.push_back(miss2);  
        return ret;
    }
};

int main()
{
    vector<int> num1{1};
    vector<int> num2{2,3};
    return 0;
}