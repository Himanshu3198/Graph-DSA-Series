#include <bits/stdc++.h>
using namespace std;
int V=4;
vector<int>adj[4];
void addEdge(vector<int>adj[],int s,int d){
    adj[s].push_back(d);
}


unordered_map<int,int> white,gray,black;


int flag=0;
void dfs(int u, vector<int> adj[])
{
    gray[u]=1;
    int i,j;
    for(i=0;i<adj[u].size();i++)
    {
       if(black[adj[u][i]])continue;
       if(gray[adj[u][i]]){flag=1;}
       else
       dfs(adj[u][i],adj);
    }
    black[u]=1;
    gray[u]=0;
}
bool isCyclic()
{

    flag=0;
    for(int i=0;i<V;i++)
    {
        if(gray[i]==0)
        {
            dfs(i,adj);
        }
    }
    gray.clear();
    black.clear();
    return flag;
}



int main() {

	
     addEdge(adj,0,1);
      addEdge(adj,0, 2);
      addEdge(adj,1, 2);
      addEdge(adj,2, 0);
      addEdge(adj,2, 3);
      addEdge(adj,3, 3);

      if(isCyclic()){
          cout<<"graph contain cycle\n";
      }
      else{
          cout<<"graph does not contain any cycle\n";
      }
      return 0;
	
	return 0;
}  



