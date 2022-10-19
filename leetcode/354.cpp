#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    static bool cmp(vector<int> v1, vector<int> v2)
    {
        int area1 = v1[0] * v1[1];
        int area2 = v2[0] * v2[1];
        return area1 < area2;
    }
    bool is_wula(vector<int> v1, vector<int> v2)
    {
        bool ret = true;
        ret = (v1[0] < v2[0]) && (v1[1] < v2[1]);
        return ret;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int len = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cmp);
        int ret = 1;
        vector<int> dp(len,1);
        for (int i = 1; i < len; i++)
        {
            for (int j = i-1; j > 0; j--)
            {
                if(is_wula(envelopes[j],envelopes[i]))
                {
                    dp[i] = max(dp[i], dp[j]+1);
                    ret = max(ret,dp[i]);
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] == b[0] ? a[1] > b[1]: a[0] < b[0];
        });
        vector<int> dp; //长度为 i+1 的地方 最小的数字
        for(const auto &e: envelopes) {
            auto p = lower_bound(dp.begin(), dp.end(), e[1]);  //二分查找第一个大于等于的地方
            if(p == dp.end()) dp.push_back(e[1]);
            else *p = e[1];
        }
        return dp.size();
    }
};

int main()
{
    vector<vector<int>> envelopes1{{5,4},{6,4},{6,7},{2,3}};
    vector<vector<int>> envelopes2{{1,1},{1,1},{1,1}};

    Solution s1;
    int ret1 = s1.maxEnvelopes(envelopes1);
    int ret2 = s1.maxEnvelopes(envelopes2);
}