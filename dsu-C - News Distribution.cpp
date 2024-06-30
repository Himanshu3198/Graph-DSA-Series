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
#define all(x)(x).begin(), (x).end()
#define MOD 1000000007 LL
#define MAX(a, b)((a) > (b) ? (a) : (b))
#define MIN(a, b)((a) < (b) ? (a) : (b))
#define ABS(x)((x) < 0 ? -(x) : (x))
#define setbits(x) __builtin_popcount(x)
#define vi vector < int >
    #define vl vector < long long int >
    #define vvi vector < vector < int >>
    #define vvl vector < vector < long long int >>
    #define INF 1e18
#define _Y puts("YES")
#define _N puts("NO")
#define showArr(v)\
for (auto it: v)\
    cout << it << " ";\
cout << E;
#define Print(ans) cout << ans << E;
#define sz(s) s.size();
#define Nitro()\
ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using namespace std;

int gcd(int a, int b) {

    if (b == 0) return a;
    return (b, a % b);
}
int lcm(int a, int b) {

    return (a * b) / gcd(a, b);
}
bool comp(const vector < int > & a,
    const vector < int > & b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
int visited[100005];



int findParent(vector < int > & parent, int x) {

    if (parent[x] == x) return x;

    return parent[x] = findParent(parent, parent[x]);
}

void union_op(vector < int > & parent, vector < int > & rank, int x, int y) {
    if (x == y) {
        return;
    }
    if (rank[x] > rank[y]) {

        parent[y] = x;
        rank[x] += rank[y];
    }
    else {
        parent[x] = y;
        rank[y] += rank[x];
    }
}

void solve()
{

    int n, m;
    cin >> n >> m;
    vector < int > parent(n + 1);
    vector < int > rank(n + 1);
    unordered_map < int, int > sz;
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rank[i] = 1;
    }

    while (m--) {
        int k;
        cin >> k;
        vector < int > frinds(k);
        for (int j = 0; j < k; j++) cin >> frinds[j];
        for (int j = 1; j < k; j++) {
            union_op(parent, rank, findParent(parent, frinds[0]), findParent(parent, frinds[j]));
        }
    }
    for(int i=1;i<=n;i++){
        cout<<rank[findParent(parent,i)]<<" ";
    }
    cout << E;
}

int main()
{
    Nitro();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
