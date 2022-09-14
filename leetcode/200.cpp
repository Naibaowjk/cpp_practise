#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<char>> grid = {
        vector<char>{1,1,1,1,0},
        vector<char>{1,1,0,1,0},
        vector<char>{1,1,0,0,0},
        vector<char>{0,0,0,1,0}
    };
    int ret = 0;
    int m = grid.size();
    int n = grid[0].size();
    function<void(int,int)> dfs = [&](int i, int j)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!= 1) return ;
        grid[i][j] = 0;
        dfs(i-1,j);
        dfs(i+1,j);
        dfs(i,j-1);
        dfs(i,j+1);
    };
    for(int i = 0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (grid[i][j] == 1) {ret++; dfs(i,j);}
        }
    }
    cout<<ret<<endl;
    return 0;
}