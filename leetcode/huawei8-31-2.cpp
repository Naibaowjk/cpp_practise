#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int x, y, t;
    node() {}
    node(int a, int b, int c) : x(a), y(b), t(c) {}
    bool operator<(const node &a) const
    {
        return t > a.t;
    }
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int g[30][30], vis[30][30];
int n, m, ans = 0;
priority_queue<node> q;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> g[i][j];
            if (g[i][j] == 2)
            {
                vis[i][j] = 1;
                q.push(node(i, j, 0));
            }
        }
    }
    while (!q.empty())
    {
        node cur = q.top();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int tx = cur.x + dx[i];
            int ty = cur.y + dy[i];
            if (tx < 0 || ty < 0 || tx >= n || ty >= n || vis[tx][ty] || g[tx][ty] == 1)
                continue;
            if (g[tx][ty] == 3)
            {
                ans = cur.t + 1;
                break;
            }
            vis[tx][ty] = 1;
            if (g[tx][ty] == 4)
                q.push(node(tx, ty, cur.t + 3));
            else if (g[tx][ty] == 6)
            {
                q.push(node(tx, ty, cur.t + 1));
                for (int j = 0; j < 4; ++j)
                {
                    int xx = tx + dx[j];
                    int yy = ty + dy[j];
                    if (g[xx][yy] == 1)
                        g[xx][yy] = 0;
                }
            }
            else
                q.push(node(tx, ty, cur.t + 1));
        }
        if (ans)
            break;
    }
    cout << ans;
    return 0;
}