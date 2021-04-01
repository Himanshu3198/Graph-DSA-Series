//  search in a maze based on flood fill graph
// time complexity O(n^2)^4
#include <bits/stdc++.h>
using namespace std;
vector<string> v;
#define MAX 1000
void dfs(int m[4][4], int sr, int sc, int rows, int cols, string ans, vector<vector<int>> &vis)
{

    if (sr >= rows || sr < 0 || sc >= cols || sc < 0)
    {
        return;
    }

    else if (m[sr][sc] == 0 or vis[sr][sc] == 1)
    {
        return;
    }
    else if (sr == rows - 1 && sc == cols - 1)
    {
        v.push_back(ans);
        return;
    }
    vis[sr][sc] = 1;

    dfs(m, sr - 1, sc, rows, cols, ans + 'U', vis);
    dfs(m, sr + 1, sc, rows, cols, ans + 'D', vis);
    dfs(m, sr, sc + 1, rows, cols, ans + 'R', vis);
    dfs(m, sr, sc - 1, rows, cols, ans + 'L', vis);
    vis[sr][sc] = 0;
}

vector<string> solve(int m[4][4], int n)
{

    string ans = "";
    int sr = 0;
    int sc = 0;
    vector<vector<int>> vis(MAX,vector<int>(MAX));



    dfs(m, sr, sc, n, n, ans, vis);

    sort(v.begin(), v.end());
    return v;
}
int main()
{
    int n = 4;
    int m[4][4] = {{1, 0, 0, 0},
                   {1, 1, 0, 1},
                   {1, 1, 0, 0},
                   {0, 1, 1, 1}};

    vector<string> result;

    result = solve(m, 4);

    for (auto it : result)
    {
        cout << it << " ";
    }
}
