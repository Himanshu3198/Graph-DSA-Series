// 1319. Number of Operations to Make Network Connected
//Time complexity O(E+V)
class Solution {
public:
    
     void dfs( vector<bool>&vis, map<int,vector<int>>&adj,int currIndex){
         
         vis[currIndex]=true;
         
         for(auto it:adj[currIndex]){
             if(vis[it]==false){
                 dfs(vis,adj,it);
             }
         }
     }
    int makeConnected(int n, vector<vector<int>>& connections) {
      
            map<int,vector<int>>adj;
          int edges=0;
     for(int i=0;i<connections.size();++i)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges += 1;
        }
        
        int component=0;
        vector<bool>vis(n,false);
        
        for(int i=0;i<n;i++){
            
            if(vis[i]==false){
                component++;
                dfs(vis,adj,i);
            }
        }
        
         if(edges<n-1){
             return -1;
         }
        int reductant=edges-((n-1)-(component-1));
        
          if(reductant>=component-1){
              return component-1;
          }
        return -1;
    }
};
