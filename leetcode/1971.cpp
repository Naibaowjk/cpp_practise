#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fp;
    void init(int n)
    {
        for(int i = 0; i<n; i++)
        {
            fp.push_back(i);
        }
    }
    int find(int i)
    {
        if (fp[i] == i) return i;
        fp[i] = find(fp[i]);
        return fp[i];
    }

    void unionn(int i, int j)
    {
        int fp_i = find(i);
        int fp_j = find(j);
        fp[fp_i] = fp_j;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       
        bool ret = false;
        init(n);
        for(int i=0; i< edges.size(); i++)
        {

            unionn(edges[i][0],edges[i][1]);
        }
        if (find(source) == find(destination)) ret = true;
        return ret;
    }

};

int main()
{
    int n = 5;
    vector<vector<int>> edges = {{0,4}};
    int start = 0;
    int end = 4;
    Solution s;
    cout<<s.validPath(n,edges,start,end)<<endl;
    return 0;
}