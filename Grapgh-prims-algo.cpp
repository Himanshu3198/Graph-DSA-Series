//prim's algorithm using adjencey matrix
//time complexity O(E^2)

#include<bits/stdc++.h>
#define V 6
using namespace std;
// find min vertex
int giveMinVertex(vector<int>&dist,vector<bool>&setMst){

    int mini=INT_MAX;
    int vertex;

    for(int i=0;i<V;i++){
        if(setMst[i]==false && dist[i]<mini){
		//updating mini variable when getting smaller dist in entire dist array
            vertex=i;
            mini=dist[i];
        }
    }
    return vertex;
}


void findMST(int graph[V][V]){

    int parent[V];    //track mst
    vector<int>dist(V,INT_MAX);   //storing  and updating weights
    vector<bool>setMst(V,false);    //keep track of included Mst


    parent[0]=-1;  // initialize source as -1
    dist[0]=0;       // source weight as 0


    // traverse v-1 edges

    for(int i=0;i<V-1;i++){

        int U=giveMinVertex(dist,setMst);  // find minimum edge vertex
        setMst[U]=true;  // mark min. vertex as true;

        for(int j=0;j<V;j++){
      
		  // updating the new smaller edge weight  from source to desitination
		  // when weight is not ,not include in mst,and new distance is less than previous distance
            if(graph[U][j]!=0 && setMst[j]==false && graph[U][j]<dist[j] ){
		    
		    // this is updating part
                dist[j]=graph[U][j];
		    // include in parent for tracking mst
                parent[j]=U;
            }
        }
    }


    for(int i=1;i<V;i++){
         //print the mst
	    // as mention parent[i] represent source and index i represent destination  and graph[parent[i][i] represent weight
        cout<<"U->V: "<<parent[i]<<"-> "<<i<<" wt = "<<graph[parent[i]][i]<<"\n";
    }


}


int main(){
     // matrix representation of graph i.e graph[1][3]=1 means 1->3 wt 1
    int  graph[V][V]= { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };
    // function call
    findMST(graph);
    return 0;                    
}
