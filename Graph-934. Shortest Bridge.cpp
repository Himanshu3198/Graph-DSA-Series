// 934. Shortest Bridge

class Solution {
public:
    
      
    int dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=0){
            return 0;
        }
         return 1;
      
    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        
         queue<pair<int,int>>q;
        
        int zeros=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1){
                    
                    q.push({i,j});
                    
                    
                }
                else{
                    zeros++;
                }
            }
        }
        
          int level=0;
        while(!q.empty()){
            
            
            int size=q.size();
             
            
            while(size--){
                
                
                int i=q.front().first;
                int j=q.front().second;
                  q.pop();
                
              
                   if(dfs(grid,i+1,j,n,m)){
                 grid[i+1][j]=1;
                 q.push({i+1,j});
                 zeros--;
            }
             if(dfs(grid,i-1,j,n,m)){
                 grid[i-1][j]=1;
                 q.push({i-1,j});
                 zeros--;
            }
             if(dfs(grid,i,j-1,n,m)){
                 grid[i][j-1]=1;
                 q.push({i,j-1});
                 zeros--;
            }
             if(dfs(grid,i,j+1,n,m)){
                 grid[i][j+1]=1;
                 q.push({i,j+1});
                 zeros--;
            }
                
                
            }
              level++;
            
            cout<<zeros<<"zeros\n";
             if(zeros<=0){
                    
                    return level;
                }
            
          
        }
        
        
        
        return level;
        
        
    }
};
