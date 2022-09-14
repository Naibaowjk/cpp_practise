#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

    }
};

int main()
{
    // 假设建筑是按顺序输入的
    int temp_int;
    char temp_char;
    cin.get(); // '['
    vector<vector<int>> buildings;
    int index = 0;
    while(cin.get() == '[')
    {
        while(cin>>temp_int)
        {
            buildings[index].push_back(temp_int);
            if(cin.get() == ']') break;
        }
        index++;
        if (cin.get() == ']') break;
    } 
    Solution s;
    vector<vector<int>> ret = s.getSkyline(buildings);
    return 0;
}
