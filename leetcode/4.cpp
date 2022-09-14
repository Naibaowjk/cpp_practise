#include <bits/stdc++.h>
using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left_1 = 0;
        int left_2 = 0;
        int right_1 = nums1.size() - 1;
        int right_2 = nums2.size() - 1;
        while(left_1<right_1 && left_1<right_1)
        {
             
        }
        double ret = 0;

        return ret;
	}
};


int main(int argc, char *argv[])
{
	vector<int> nums1 = {0};
	vector<int> nums2 = {1};
	
	Solution solution;
	double ret = solution.findMedianSortedArrays(nums1, nums2);
	return 0;
}
