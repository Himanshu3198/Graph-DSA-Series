#include<bits/stdc++.h>
using namespace std;

  void addEdge(vector<int>adj[],int s,int d){
       adj[s].push_back(d);
       adj[d].push_back(s);
  }


  void printGraph(vector<int>adj[],int V){

       for(int i=0;i<V;i++){

           cout<<i<<" :" ;

           for(auto it:adj[i]){
              cout<<"->"<<it;
           }
           cout<<"\n";

       }
  }

int main(){

    int v=5;
    vector<int>adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj,v);

}

// representation of graph
// 0 :->1->4
// 1 :->0->2->3->4
// 2 :->1->3
// 3 :->1->2->4
// 4 :->0->1->3