DFS
Runtime: 632 ms
Memory Usage: 229.5 MB

class Solution {
public:
    
    
      bool dfs(vector<vector<int>>&adj,vector<int>&vis,int start, int end){
          
          
            if(vis[start]==1){
                return false;
            }
          
          if(start==end){
              return true;
          }
          
          vis[start]=1;
          for(auto it:adj[start]){
              if(dfs(adj,vis,it,end)){
                 return   true ;
              }
          }
          
          return false;
      }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
     
        
          
         
        vector<vector<int>>graph(n);
        
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
             graph[it[1]].push_back(it[0]);
        }
        
        
        vector<int>vis(n,0);
            
            
           return dfs(graph,vis,start,end);
        
        
    }
};
BFS
Runtime: 1336 ms
Memory Usage: 166.4 MB

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
     
        
         
        vector<vector<int>>graph(n);
        
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
             graph[it[1]].push_back(it[0]);
        }
        
        
        queue<int>q;
        q.push(start);
        vector<int>vis(n,0);
        while(!q.empty()){
            
            
            int size=q.size();
            
            while(size--){
                
                auto curr=q.front(); q.pop();
                if(vis[curr]) break;
                vis[curr]=1;
                if(curr==end){
                    return true;
                }
                
                for(auto &it:graph[curr]){
                    
                    if(!vis[it]){
                        q.push(it);
                    }
                }
                
            }
        }
        
        return false;
        
        
    }
};
DSU
Fastest Runtime: 424 ms
Memory Usage: 128 MB

class Solution {
public:
    
      vector<int>parent;
      vector<int>rank;
    
      int find(int x){
          
          if(parent[x]==-1){
              return x;
          }
          return parent[x]=find(parent[x]);
      }
    
      void union_op(int x,int y){
          
          if(x==y){
              return;
          }
          if(rank[x]>rank[y]){
              parent[y]=x;
              rank[x]+=1;
          }else{
              parent[x]=y;
              rank[y]+=1;
          }
         
      }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
     
        
           parent.resize(n,-1);
          rank.resize(n);
          for(int i=0;i<n;i++){
              rank[i]=1;
          }
        
        
        for(auto it:edges){
            
            union_op(find(it[0]),find(it[1]));
        }
        
        return find(start)==find(end);
    }
};
