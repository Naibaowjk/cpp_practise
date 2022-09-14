#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &vec, vector<int> &vec_dis, int cur, int dis, vector<bool> &flag)
{
    
    if (flag[cur]) return;
    flag[cur] = true;
    vec_dis[cur] = dis;
    dis++;
    for(int i = 0; i < vec[cur].size(); i++)
    {
        dfs(vec, vec_dis, vec[cur][i], dis, flag);
    }
}

int main()
{
    int n,m,temp;
    int start,end;
    
    cin>>n;
    cin>>m;
    vector<vector<int>> top(n,vector<int>{});
    vector<bool> flag(n,false);
    vector<int> vec_dis(n,-1);
    for(int i = 0; i<m; i++)
    {
        vector<int> vec;
        int cur;
        cin>>cur;
        while(cin>>temp)
        {
            top[cur].push_back(temp);
            top[temp].push_back(cur);
            if (cin.get()=='\n') break;
        }
    }
    cin>>start>>end;
    dfs(top, vec_dis, start ,0, flag);
    cout<< vec_dis[end]<<endl;
}