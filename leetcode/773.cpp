#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,int> map;
    queue<pair<string,int>> q;
    vector<vector<int>> lookup{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
    string result = "123450";
    string get_state(vector<vector<int>> &board)
    {
        string ret = "";
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ret += '0' + board[i][j];
            }
            
        }
        return ret;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        
        string init_state = get_state(board);
        map[init_state] = 0;
        q.push(pair<string,int>(init_state,0));
        while(!q.empty())
        {
            pair<string, int> cur = q.front();
            q.pop();
            string cur_state = cur.first;
            int cur_step = cur.second;
            if ( strcmp(cur_state.c_str(), result.c_str()) == 0) return cur_step;
            int index_zero = cur_state.find('0');
            for (int i = 0; i < lookup[index_zero].size(); i++)
            {
                string next_state = cur_state;
                swap(next_state[index_zero], next_state[lookup[index_zero][i]]);
                if ( map.find(next_state) == map.end() )
                {
                    q.push(pair<string,int>(next_state,cur_step+1));
                    map[next_state] = cur_step+1;
                }
            }
        }
        return -1;
    }

};

int main()
{
    vector<vector<int>> board1 = {{1,2,3},{4,0,5}};
    vector<vector<int>> board2 = {{1,2,3},{5,4,0}};
    Solution s;
    int ret1 = s.slidingPuzzle(board1);
    int ret2 = s.slidingPuzzle(board2);
    return 0;
}