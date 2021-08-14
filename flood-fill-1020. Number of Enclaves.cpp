1020. Number of Enclaves
class Solution {
public:
    
    
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
        
          if(i<0 or i>=n or j<0 or j>=m  or !grid[i][j] ){
               return ;
           }
        
          grid[i][j]=0;
        
                   dfs(grid,i+1,j,n,m);
                   dfs(grid,i-1,j,n,m);
                   dfs(grid,i,j+1,n,m);
                   dfs(grid,i,j-1,n,m);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
    
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(i==0 or j==0 or i==n-1 or j==m-1){
                    
                    if(grid[i][j]==1 ){
                        dfs(grid,i,j,n,m);
                    }
                }
            }
        }
        
        int count=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1) count++;
            }
        }
        
        return count;
    }
};
