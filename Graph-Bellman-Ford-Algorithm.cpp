// Bellman ford algorithm
// time complexity O(EV)

#include<bits/stdc++.h>
using namespace std;

#define MAXE 10000
#define MAXN 100


int main(){

    int node, edge, src;
    int d[MAXN], edge_u[MAXE], edge_v[MAXE], edge_cost[MAXE];
    cin>>node>>edge>>src;

    for(int i = 0; i <node; i++) {
        d[i] =INT_MAX;

    }
        d[src] = 0; // distance to source is 0
    for(int i = 0; i < edge; i++)
    {
        cin>>edge_u[i]>>edge_v[i]>>edge_cost[i];
    }
    bool neg_cycle = false;
    for(int step = 0; step < node; step++)
    {
        bool updated = false;
        for(int i = 0; i < edge; i++)
        {
            int u = edge_u[i], v = edge_v[i], w = edge_cost[i];
           if(d[u] + edge_cost[i] < d[v])
           {
               updated = true;
               if(step==node) neg_cycle = true; //if we can update in n'th step, there is a negative cycle
              d[v] = d[u] + edge_cost[i];
           }
        }
        if(updated == false) break; // if we can't update in a or any step, no need to try anymore
    }

    if(neg_cycle == false)
    {
        printf("No negative Edge Found\n Distance to node: \n");
        for(int i = 1; i <node; i++) cout<<i<<"  "<<d[i]<<endl;
    }
    else
        cout<<"Negative cycle detected\n";
    return 0;

}

// Test Case

// 3 3 0
// 0 1 2
// 1 2 3
// 2 1 -2
// No negative Edge Found
//  Distance to node:
// 1  2
// 2  5

