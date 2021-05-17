// Find if there is a path of more than k length from a source
// time complexity O(n!)
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>>adj[],int s,int d,int w){

    adj[s].push_back(make_pair(d,w));
    adj[d].push_back(make_pair(s,w));



}


bool solve(int src,int k,vector<pair<int,int>>adj[],vector<bool>&visit){
    visit[src]=true;


    if(k<=0){
        return true;
    }


    for(auto it:adj[src]){
        int u=it.first;
        int w=it.second;

        if(visit[u]==true){
            continue;
        }

        if(w>=k){
            return true;
        }

        if(solve(u,k-w,adj,visit)){
            return true;
        }
    }

    visit[src]=false;

    return false;
}


int main(){



     int v=9,src=0,k=60;
    vector<pair<int,int>>adj[v+1];

        addEdge(adj,0, 1, 4);
        addEdge(adj,0, 7, 8);
        addEdge(adj,1, 2, 8);
        addEdge(adj,1, 7, 11);
        addEdge(adj,2, 3, 7);
        addEdge(adj,2, 8, 2);
        addEdge(adj,2, 5, 4);
        addEdge(adj,3, 4, 9);
        addEdge(adj,3, 5, 14);
        addEdge(adj,4, 5, 10);
        addEdge(adj,5, 6, 2);
        addEdge(adj,6, 7, 1);
        addEdge(adj,6, 8, 6);
        addEdge(adj,7, 8, 7);

        vector<bool>visit(v+1,false);

        cout<<solve(0,k,adj,visit)<<"\n";




    return 0;
}