#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        return s1.size() == s2.size() && (s1 + s1).find(s2) != string::npos;
    }
};


int main()
{
    string s1 = "--";
    string s2 = "--";
    Solution s;
    bool ret1 = s.isFlipedString(s1,s2);
    return 0;
}