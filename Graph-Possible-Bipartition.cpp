// 886. Possible Bipartition


class Solution {
public:
    /* 
         Bipartition graph is a graph  when we colored it with two different colors then no adjacent vertex has same color .*/
    // dfs implentation
      bool dfs(vector<vector<int>>& adj,vector<int>&visit,int node,int curr_color){
          
             if(visit[node]!=0){
                 return visit[node]==curr_color;
             }
          
          visit[node]=curr_color;
          
             for(auto it:adj[node]){
                 
                 if(!dfs(adj,visit,it,-curr_color)){
                     return false;
                 }
             }
          
            
          return true;
      }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        
        
          // int n=dislikes.size();
        vector<int>visit(n+1,0);
        
          vector<vector<int>>adj(n+1);
        
        
        for(auto it:dislikes){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        
        for(int i=1;i<=n;i++){
            
            if( visit[i]==0 and !dfs(adj,visit,i,1)){
                return false;
            }
        }
        
        return true;
        
        
    }
  
  
  
};






 // bfs implementation

class Solution {
public:
    
    

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        
          vector<vector<int>>adj(n+1);
        
        
        for(auto it:dislikes){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        
        
        
           vector<int>visit(n+1,0);
        
        queue<int>q;
        for(int i=1;i<=n;i++){
            
            if(visit[i]==1 || visit[i]==-1){
                continue;
            }
            
            visit[i]=1;
            q.push(i);
        
        
        while(!q.empty()){
            
            int first=q.front();
            q.pop();
            
            for(int j:adj[first]){
                
               if(visit[j]==0){
                   visit[j]=visit[first]*-1;
                
                   q.push(j);
               }
                if(visit[first]==visit[j]){
                    return false;
                }
            }
        }
     
        
    }
           return true;
        
        
    }
};
