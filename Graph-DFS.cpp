#include <bits/stdc++.h>
#define V 4;
using namespace std;

vector<int>adj[4];

void addEdge(vector<int> adj[], int s, int d)
{
  adj[s].push_back(d);
}

void solve(int v,bool visited[]){
  visited[v]=true;
  cout<<v<<" ";
  for(auto it=adj[v].begin();it!=adj[v].end();it++){
    if(!visited[*it]){
      solve(*it,visited);
    }
  }
}
void dfs(int v){
   bool *visited=new bool[4];
    for(int i=0;i<4;i++)
     visited[i]=false;

    solve(v,visited);
}




int main()
{
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 0);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 3);
  dfs(2);

  return 0;
}
