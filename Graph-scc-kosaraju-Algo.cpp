//  kosaraju's alogorithm for strongly connected graph
// time complexity O(e+v) 
#include<bits/stdc++.h>
#define V 5
using namespace std;

vector<int>adj[V];
vector<int>rev[V];


void addEdge(int s,int d)
{

    adj[s].push_back(d);
}
void transpose(){

for(int i=0;i<V;i++){
    for(auto it:adj[i]){
      rev[it].push_back(i);
    }
}

}
void dfs1(int node,stack<int>&st,vector<bool>&visit){
    visit[node]=true;
    for(int it:adj[node]){
          if(!visit[it]){
              dfs1(it,st,visit);
          }
    }
    st.push(node);
}
void dfs2(int curr,vector<bool>&visit){
    cout<<curr<<" ";
    visit[curr]=true;
    for(int j:rev[curr]){
          if(!visit[j]){
              dfs2(j,visit);
          }
    }
}

void kosaraju(){
    vector<bool>visit(V,false);
    stack<int>st;

    for(int i=0;i<V;i++){

        if(!visit[i]){
            dfs1(i,st,visit);
        }
    }
    transpose();
    for(int i=0;i<V;i++){
        visit[i]=false;
    }
    cout<<"strongly connected components are\n";

    while(!st.empty()){
    int curr=st.top();
    st.pop();
    if(visit[curr]==false){
        dfs2(curr,visit);
        cout<<" \n";
    }
    }
}


int main(){
  
    addEdge(1,0);
    addEdge(0,2);
    addEdge(2,1);
    addEdge(0,3);
    addEdge(3,4);  
    kosaraju();

    return 0;

    

}