// 695. Max Area of Island

class Solution {
public:
    
    
       int dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis , int i,int j,int n,int m){
           
           
           if(i<0 or i>=n or j<0 or j>=m or vis[i][j] or !grid[i][j] ){
               return 0;
           }
           
           vis[i][j]=true;
           
           return 1+dfs(grid,vis,i+1,j,n,m)+
                   dfs(grid,vis,i-1,j,n,m)+
               dfs(grid,vis,i,j+1,n,m)+
               dfs(grid,vis,i,j-1,n,m);
       }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
        int maxArea=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(!vis[i][j] and grid[i][j]){
                    
                    int curArea=dfs(grid,vis,i,j,n,m);
                    
                    maxArea=max(maxArea,curArea);
                }
            }
        }
        
        return maxArea;
    }
};
