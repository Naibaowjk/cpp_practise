#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        int len = height.size();

        vector<int> left_bound(len,0);
        vector<int> right_bound(len,0);
        for (int i = 1; i < height.size()-1; i++)
        {
            left_bound[i] = height[i-1]>left_bound[i-1] ? height[i-1]:left_bound[i-1];
            right_bound[len-i-1] = height[len-i]>right_bound[len-i]? height[len-i] : right_bound[len-i];
        }
        for (int i = 0; i < len; i++)
        {
            int cur = min(left_bound[i],right_bound[i]) - height[i];
            if (cur < 0) cur = 0;
            ret+=cur;
        }
        
        return ret;
    }
};

int main()
{
    vector<int> height1{0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height2{4,2,0,3,2,5};
    Solution s;
    int ret1 = s.trap(height1);
    int ret2 = s.trap(height2);
    return 0;
}