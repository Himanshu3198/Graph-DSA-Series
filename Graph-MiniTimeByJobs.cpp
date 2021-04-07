#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000

vector<int>result(MAXSIZE);
vector<int>degree(MAXSIZE,0);
vector<int>graph[MAXSIZE];



void addEdge(int u,int v){
    graph[u].push_back(v);
    degree[v]++;
}

void solve(int n,int m){
      queue<int>q;

      for(int i=1;i<=n;i++){
          if(degree[i]==0){
              q.push(i);
              result[i]=1;
          }
      }

      while(!q.empty()){

          int cur=q.front();
            q.pop();

          for(int it:graph[cur]){
              degree[it]--;
              if(degree[it]==0){

                  q.push(it);
                  result[it]=result[cur]+1;
              }
          }

      }

      for(int i=1;i<=n;i++){
          cout<<result[i]<<" ";
      }
      cout<<"\n";
}

int main(){
    int n=10,m=13;
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);
    solve(n,m);

}

