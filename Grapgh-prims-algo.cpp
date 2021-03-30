//prim's algorhitm

#include<bits/stdc++.h>
#define V 6
using namespace std;
// find min vertex
int giveMinVertex(vector<int>&dist,vector<bool>&setMst){

    int mini=INT_MAX;
    int vertex;

    for(int i=0;i<V;i++){
        if(setMst[i]==false && dist[i]<mini){
            vertex=i;
            mini=dist[i];
        }
    }
    return vertex;
}


void findMST(int graph[V][V]){

    int parent[V];    //track mst
    vector<int>dist(V,INT_MAX);
    vector<bool>setMst(V,false);


    parent[0]=-1;
    dist[0]=0;


    // traverse v-1 edges

    for(int i=0;i<V-1;i++){

        int U=giveMinVertex(dist,setMst);

        for(int j=0;j<V;j++){

            if(graph[U][j]!=0 && setMst[j]==false && graph[U][j]<dist[j] ){
                dist[j]=graph[U][j];
                parent[j]=U;
            }
        }
    }


    for(int i=1;i<V;i++){

        cout<<"U->V: "<<parent[i]<<"-> "<<i<<" wt = "<<graph[parent[i]][i]<<"\n";
    }


}


int main(){

    int  graph[V][V]= { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };

    findMST(graph);
    return 0;                    
}