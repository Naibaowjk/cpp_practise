#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int,int> fa;
    vector<int> rank;
    int find(int i)
    {
        if(fa[i] == i) return i;
        fa[i] = find(fa[i]);
        return fa[i];
    }
    void merge(int i, int j)
    {
        if (fa.find(j) != fa.end()) 
        {
            fa[i] = find(j);
        }
    }
    int longestConsecutive(vector<int>& nums) {
        int ret=0;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            if (fa.find(nums[i]) == fa.end()) fa[nums[i]] = nums[i];
        }
        for(int i = 0; i < len; i++)
        {
            merge(nums[i], nums[i]+1);
        }
        for(int i = 0; i < len; i++) 
        {
            fa[nums[i]] = find(nums[i]);
            ret = ret < (fa[nums[i]]-nums[i]+1) ? fa[nums[i]]-nums[i]+1 : ret;
        }
        rank = vector<int>(len,1);
        
        return ret;
    }
};

int main()
{
    vector<int> nums;
    int temp;
    char temp_c;
    cin>>temp_c;
    while(cin>>temp)
    {
        nums.push_back(temp);
        if (cin.get() == ']') break;
    }
    Solution s;
    cout<< s.longestConsecutive(nums) << endl;
    return 0;
}