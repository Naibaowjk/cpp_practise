#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ret;
        map<int,int> map_s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map_s.find(nums[i]) != map_s.end()) map_s[nums[i]]++;
            else map_s[nums[i]] = 1;
        }
        vector<pair<int,int>> v_sort;
        for(map<int,int>::iterator it = map_s.begin(); it != map_s.end(); it++)
        {
            v_sort.push_back(make_pair(it->first,it->second));
        }
        sort(v_sort.begin(), v_sort.end(), cmp);
        for(int i = 0; i<v_sort.size();i++)
        {
            for(int j = 0; j<v_sort[i].second; j++) 
            {
                ret.push_back(v_sort[i].first);
            }
        }
        return ret;
    }

    static bool cmp(pair<int,int> a, pair<int,int> b)
    {
        if (a.second == b.second) return a.first > b.first;
        else return a.second < b.second;
    }
};

int main()
{
    vector<int> nums = {1,1,2,2,2,3};
    Solution s;
    s.frequencySort(nums);
    return 0;
}