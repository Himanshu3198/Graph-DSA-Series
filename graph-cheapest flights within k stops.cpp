
// 787. Cheapest Flights Within K Stops 
//  bellman ford algorhithm
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     
                 vector<int>dist(n,INT_MAX);
        
        
        
              dist[src]=0;
        
        
           for(int i=0;i<=k;i++){
               
               vector<int>curr(dist);
               for(int i=0;i<flights.size();i++){
                   
                   
                   int s=flights[i][0];
                   
                   int d=flights[i][1];
                   
                   int w=flights[i][2];
                   
                   
                   if(dist[s]!=INT_MAX){
                       curr[d]=min(curr[d],dist[s]+w);
                   }
               }
               dist=curr;
           }
        
           return dist[dst]==INT_MAX?-1:dist[dst];

    }
};
