
/*
 author:himanshu3198

*/
#include <bits/stdc++.h>
#define ll long long int
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, n) for (int i = (n); i >= 0; i--)
#define fst first
#define snd second
#define E "\n"
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007LL
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define setbits(x) __builtin_popcount(x)
#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long int>>
#define INF 1e18
#define _Y puts("YES")
#define _N puts("NO")
#define showArr(v)         \
    for (auto it : v)      \
        cout << it << " "; \
    cout << E;
#define Print(ans) cout << ans << E;
#define sz(s) s.size();
#define Nitro()                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

vector<int> color;
bool dfs(vector<vector<int>> &graph, int &parentColor, int node)
{

    if (color[node] != 0)
    {
        return color[node] != parentColor;
    }
    color[node] = -parentColor;
    for (auto it : graph[node])
    {

        if (!dfs(graph, color[node], it))
            return false;
    }
    return true;
}
void solve()
{
    ll n, m;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int s, d;
        cin >> s >> d;
        graph[s].push_back(d);
        graph[d].push_back(s);
        
    }
    color.assign(n + 1, 0);
    int parentColor = -1;
    for (int i = 1; i <= n; i++)
    {
        if(graph[i].size()>2){
            _N;
            return;
        }
        if (color[i] == 0 && !dfs(graph, parentColor, i))
        {
            _N;
            return;
        }
    }
    _Y;
}

int main()
{
    Nitro();
    int t = 1;
    cin >> t;

    while (t--)
    {

        solve();
    }

    return 0;
}
