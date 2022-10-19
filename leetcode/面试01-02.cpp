#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        map<char,int> m1;
        for (int i = 0; i < s1.size(); i++)
        {
            if (m1.find(s1[i]) !=  m1.end()) m1[s1[i]]++;
            else m1[s1[i]] = 1;
        }
        for (int i = 0; i < s2.size(); i++)
        {
            if (m1.find(s2[i]) == m1.end()) return false;
            m1[s2[i]]--;
            if (m1[s2[i]] < 0) return false;
        }
        return true;
    }
};

int main()
{
    string s11 = "abc", s21 = "bca";
    string s12 = "abc", s22 = "bad";
    string s13 = "abb", s23 = "aab";
    Solution s1;
    bool ret1 = s1.CheckPermutation(s11,s21);
    bool ret2 = s1.CheckPermutation(s12,s22);
    bool ret3 = s1.CheckPermutation(s13,s23);
    return 0;
}