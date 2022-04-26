
/* Kruskal's Algo
   step 1 sort the edges by increasing order of their weight 
   step 2 use dsu to check if  curr edges making cycle or not if not then include its weight in minimum spanning tree cost
   t.c O(ElogE)+O(E*4*alpha)
*/
#include<bits/stdc++.h>
using namespace std;


struct node{
      int u;
      int v;
      int wt;
      node(int _u,int _v,int _w){
          u=_u;
          v=_v;
          wt=_w;
      }
};

bool cmp(node &a,node &b){
    return a.wt<b.wt;
}

int findPar(int x,vector<int>&parent){

    if(parent[x]==x) return x;
    return parent[x]=findPar(parent[x],parent);
}

void union_op(int x,int y,vector<int>&rank,vector<int>&parent){

     x=findPar(x,parent);
     y=findPar(y,parent);
    if(x==y) return;

    if(rank[x]>rank[y]){

        parent[y]=x;
        rank[x]+=1;
    }else{
        parent[x]=y;
        rank[y]+=1;
    }

}

int main(){

     vector<node>graph;
     graph.push_back(node(0,1,2));
     graph.push_back(node(1,2,3));
     graph.push_back(node(0,3,6));
     graph.push_back(node(3,1,8));
     graph.push_back(node(1,4,5));
     graph.push_back(node(2,4,7));
     
     int n=5;
     vector<int>parent(n),rank(n,0);
     int minCost=0;
     for(int i=0;i<n;i++) parent[i]=i;
     vector<node>mst;
     for(auto &it:graph){

         if(findPar(it.u,parent)!=findPar(it.v,parent)){
            mst.push_back(node(it.u,it.v,it.wt));
            minCost+=it.wt;
            union_op(it.u,it.v,rank,parent);
         }
     }

     cout<<"Minimum Spanning Tree Cost "<<minCost<<"\n";

     for(auto &it:mst) cout<<it.u<<"--"<<it.v<<" wt->"<<it.wt<<"\n";




}
