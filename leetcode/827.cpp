#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> area;
        vector<vector<int>> flag(m,vector<int>(n,0));
        int cur_flag = 1;
        int ret = 1;
        function<int(int i, int j)> get_add = [&](int i, int j)
        {
            unordered_map<int,int> map_flag;
            if (i>0 && map_flag.find(flag[i-1][j]) == map_flag.end()) map_flag[flag[i-1][j]] = area[flag[i-1][j]];
            if (j>0 && map_flag.find(flag[i][j-1]) == map_flag.end()) map_flag[flag[i][j-1]] = area[flag[i][j-1]];
            if (i<m-1 && map_flag.find(flag[i+1][j]) == map_flag.end()) map_flag[flag[i+1][j]] = area[flag[i+1][j]];
            if (j<n-1 && map_flag.find(flag[i][j+1]) == map_flag.end()) map_flag[flag[i][j+1]] = area[flag[i][j+1]];
            int ret = 1;
            for(auto iter = map_flag.begin(); iter != map_flag.end(); iter++) ret += iter->second;
            return ret;
        };
        for(int i = 0; i< m; i++)
        {
            for (int j = 0; j<n ; j++)
            {
                if (grid[i][j] == 1)
                {
                    area.push_back(dfs(grid,flag,i,j,cur_flag));
                    cur_flag++;
                }
            }
        }
        for(int i = 0; i<area.size();i++)
        {
            ret = ret>area[i]? ret:area[i];
        }
        for(int i = 0; i< m; i++)
        {
            for (int j = 0; j<n ; j++)
            {
                if (grid[i][j] == 0)
                {
                    int cur_add =  get_add(i,j);
                    ret = ret>cur_add? ret: cur_add;
                }
            }
        }
        return ret;
    }
    int dfs(vector<vector<int>>& grid, vector<vector<int>> &flag, int i, int j, int cur_flag)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i == -1 || j == -1 || i == m || j == n ) return 0;
        if (grid[i][j] == 0) return 0;
        if (grid[i][j] == 2) return 0;
        grid[i][j] = 2;
        flag[i][j] = cur_flag;
        return 1 + dfs(grid, flag, i-1, j , cur_flag) + dfs(grid, flag, i+1, j , cur_flag) + dfs(grid, flag, i, j-1 , cur_flag) + dfs(grid, flag, i, j+1 , cur_flag);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid {vector<int>{0,0}, vector<int>{0,1}};
    cout<<s.largestIsland(grid)<<endl;
    return 0;
}