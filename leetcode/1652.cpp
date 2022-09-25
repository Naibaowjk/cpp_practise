#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ret;
        if (k < 0)
        {
            k = -1 * k;
            for (int i = 0; i < n; i++)
            {
                int cur = 0;
                for (int j = 1; j <= k; j++)
                {
                    int index = (i - j)%n;
                    index = index < 0 ? index+n: index;
                    cur +=code[index];
                }
                ret.push_back(cur);
            }
        }
        else if (k == 0) ret = vector<int>(n,0);
        else
        {
            for (int i = 0; i < n; i++)
            {
                int cur = 0;
                for (int j = 1; j <= k; j++)
                {
                    int index = (i + j)%n;
                    cur +=code[index];
                }
                ret.push_back(cur);
            }
        }
        return ret;
    }
};


int main()
{
    vector<int> code1{5,7,1,4};
    vector<int> code2{1,2,3,4};
    vector<int> code3{2,4,9,3};
    int k1 = 3;
    int k2 = 0;
    int k3 = -2;

    Solution s1;
    vector<int> ret1 = s1.decrypt(code1,k1);
    vector<int> ret2 = s1.decrypt(code2,k2);
    vector<int> ret3 = s1.decrypt(code3,k3);

    return 0; 
}