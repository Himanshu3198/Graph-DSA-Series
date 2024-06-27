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
 
 int gcd(int a,int b){

    if(b==0) return a;
    return (b,a%b);
 }
 int lcm(int a,int b){

    return (a*b)/gcd(a,b);
 }
 bool comp(const vector<int>&a,const vector<int>&b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]<b[0];
}
int visited[100005];
int dfs(unordered_map<int,vector<int>>&graph,vector<int>&isCat,int m,int parentNode,int totalCat){
    if(isCat[parentNode-1]==1){
        totalCat++;
    }else totalCat=0;
    if(totalCat>m) return 0;
    visited[parentNode]=1;
    int count=0;
    bool isLeaf=true;
    for(auto &ngbrNode:graph[parentNode]){
      
        if(visited[ngbrNode]==-1){
            isLeaf=false;
                count+=dfs(graph,isCat,m,ngbrNode,totalCat);
        }
        
    }
    if(isLeaf) return count+1;
    return count;
}
void solve()
{
     
  int n,m;
  cin>>n>>m;
  vector<int>isCat;
  for(int i=0;i<n;i++){
      int input;
      cin>>input;
      isCat.push_back(input);
  }
  unordered_map<int,vector<int>>graph;
  for(int i=1;i<n;i++){
      int u,v;
      cin>>u>>v;
      graph[u].pb(v);
      graph[v].pb(u);
  }
  memset(visited,-1,sizeof(visited));
  
  int totalCat=0;
  if(isCat[1]) totalCat++;
  cout<<dfs(graph,isCat,m,1,0)<<E;
  
       
}
 
int main()
{
    Nitro();
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
