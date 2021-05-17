#include<bits/stdc++.h>
using namespace std;

#define v 7



void addEdge(vector<int>adj[],int s,int d){
        adj[s].push_back(d);
        adj[d].push_back(s);
}

int main(){

    vector<int>adj[v];

    addEdge(adj,0,1);
    addEdge(adj,0,2);
      addEdge(adj,1,3);
        addEdge(adj,3,4);
          addEdge(adj,4,5);
            addEdge(adj,5,6);



           vector<int>visit(v,false);


           for(int i=0;i<v;i++){
              if(visit[i]==false){
               for(auto it:adj[i]){

                   if(visit[it]==false){
                       visit[it]=true;
                       visit[i]=true;
                       break;
                   }
               }

              }
           }

           for(int i=0;i<v;i++){
               if(visit[i]){
                   cout<<i<<" ";
               }
           }
           cout<<"\n";





    return 0;



   
}
