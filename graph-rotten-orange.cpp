// 994. Rotting Oranges

class Solution {
public:
    
    
    bool dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=1){
            return false;
        }
         return true;
      
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
           int count=0;
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  if(grid[i][j]==1) count++;
              }
          }
           
          if(count==0) return 0;
        
        queue<pair<int,int>>q;
        
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==2){
                    
                    grid[i][j]=3;
                    q.push({i,j});
                }
            }
        }
        
        int time=-1;
        
        
        while(!q.empty()){
            int q_size=q.size();
        for(int k=0;k<q_size;k++){
            
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            if(dfs(grid,i+1,j,n,m)){
                 grid[i+1][j]=3;
                
                  q.push({i+1,j});
            }
             if(dfs(grid,i-1,j,n,m)){
                 grid[i-1][j]=3;
                 q.push({i-1,j});
            }
             if(dfs(grid,i,j-1,n,m)){
                 grid[i][j-1]=3;
                 q.push({i,j-1});
            }
             if(dfs(grid,i,j+1,n,m)){
                 grid[i][j+1]=3;
                 q.push({i,j+1});
            }
        }
            
            time++;
            
        }
             for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
               if(  grid[i][j]==1) return -1;
                    
                 
            }
                 
        }
        
        return time;
    }
};
