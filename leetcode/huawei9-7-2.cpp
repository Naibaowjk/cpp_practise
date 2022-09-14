#include <bits/stdc++.h>
using namespace std;

// 过程有问题，还需要判断一次最小值，再return那里。不想改了。
void bfs(vector<vector<char>> &vec, int m, int n, queue<pair<int,int>> &q, vector<vector<int>> &flag, vector<vector<bool>> &flag2, vector<vector<int>> &dp)
{
    int qi = 0;
    int q_size = q.size();
    while(!q.empty())
    {
        qi = 0;
        q_size = q.size();
        while(qi < q_size)
        {
            qi++;
            pair<int,int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            int last_ori = flag[i][j];
            if (flag2[i][j]) continue;
            flag2[i][j] = true;
            if (vec[i][j] == 'X') {dp[i][j] = -1; continue;}    
            if (vec[i][j] == 'E') return;
            // 向上
            if (i > 0){
                if(flag2[i-1][j] == false) dp[i-1][j] = (last_ori == 2 || last_ori == -1) ? dp[i][j] + 1 : dp[i][j] + 2;
                flag[i-1][j] = 2;
                q.push(pair<int,int>(i-1,j));
            }
            // 向下
            if (i < m-1){
                if(flag2[i+1][j] == false) dp[i+1][j] = (last_ori == 3 || last_ori == -1) ? dp[i][j] + 1 : dp[i][j] + 2;
                flag[i+1][j] = 3;
                q.push(pair<int,int>(i+1,j));
            }
            // 向左
            if (j > 0){
                if(flag2[i][j-1] == false) dp[i][j-1] = (last_ori == 4 || last_ori == -1) ? dp[i][j] + 1 : dp[i][j] + 2;
                flag[i][j-1] = 4;
                q.push(pair<int,int>(i,j-1));
            }
            // 向右
            if (j < n-1){
                if(flag2[i][j+1] == false) dp[i][j+1] = (last_ori == 5 || last_ori == -1) ? dp[i][j] + 1 : dp[i][j] + 2;
                flag[i][j+1] = 5;
                q.push(pair<int,int>(i,j+1));
            }  
        }
    }

}

int main()
{
    int m, n;
    int s_m, s_n;
    int e_m, e_n;
    cin>>m>>n;
    char temp;
    vector<vector<char>> vec(m, vector<char>(n,'N'));
    vector<vector<int>> flag(m, vector<int>(n, -1));
    vector<vector<int>> dp(m, vector<int>(n,0));
    vector<vector<bool>> flag2(m,vector<bool>(n,false));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            vec[i][j]=temp;
            if (temp == 'S')
            {
                s_m = i;
                s_n = j;
            }
            if (temp == 'E')
            {
                e_m = i;
                e_n = j;
            }
        }
    }    
    queue<pair<int,int>> q;
    q.push(pair<int,int>(s_m,s_n));
    bfs(vec,m,n,q,flag,flag2,dp);
    cout<<dp[e_m][e_n]<<endl;
    return 0;
}