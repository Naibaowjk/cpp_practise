#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        bool ret = true;
        int index = 0;
        int len_arr = arr.size();
        int len_pieces = pieces.size();
        vector<bool> pieces_flag(len_pieces,false);
        while (index<len_arr)
        {
            bool is_match_cur = false;
            int cur = arr[index];
            for (int i = 0; i < len_pieces; i++)
            {
                if (!pieces_flag[i] && cur == pieces[i][0])
                {
                    bool is_match = true;
                    for (int j = 1; j < pieces[i].size(); j++)
                    {
                        is_match &= (arr[index +j] == pieces[i][j]);
                        if (!is_match) break;

                    }
                    if (is_match)
                    {
                        index = index + pieces[i].size();
                        pieces_flag[i] = true;
                        is_match_cur = true;
                    }
                } 
            }
            if (!is_match_cur) return false;
        }
        return ret;
    }
};

int main()
{
    vector<int> arr {15,88};
    vector<vector<int>> pieces {{88},{15}};
    Solution s;
    cout<<s.canFormArray(arr,pieces)<<endl;
    return 0;
}