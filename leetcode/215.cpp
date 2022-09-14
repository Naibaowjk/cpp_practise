#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool compare(int a, int b){return a>b;}
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),compare);
        return nums[k-1];
    }
};