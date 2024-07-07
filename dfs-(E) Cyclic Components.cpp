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
#define mod 1000000007LL
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
ll visited[10000005];

bool isCycle;


void dfs(unordered_map<ll,vector<ll>>&graph,ll node){
   if(visited[node]==1) return;
   visited[node]=1;
   if(graph[node].size()!=2){
       isCycle=false;
   }
   for(auto &ngbr:graph[node]){
       if(visited[ngbr]==0) dfs(graph,ngbr);
   }
}


void solve()

{
    ll ans,n,m,k;
    unordered_map<ll,vector<ll>>graph;
    cin>>n>>m;
    while(m--){
        
        ll u,v;
        cin>>u>>v;
        // cout<<u<<","<<v<<E;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(visited,0,sizeof(visited));
    ans=0;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            isCycle=true;
            dfs(graph,i);
            if(isCycle) ans++;
        }
          
    }
    
    Print(ans);
    
   
 
  
    
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
