1254. Number of Closed Islands

class Solution {
public:
    /*  this problem is basically based on flood fill algorhitm  only thing we have to do is
        
        just mark all zeros two zeros  because of this only those zeros will left which 
        are surrounded by only ones in four direction. 
        
    
    
    */
      
       void dfs(vector<vector<int>>&grid,int x,int y,int n,int m){
           
           if(x<0 or x>=n  or y<0 or y>=m or grid[x][y]==1 ){
               return;
           }
           
           
              grid[x][y]=1;
              
           
              dfs(grid,x+1,y,n,m);
              dfs(grid,x-1,y,n,m);
              dfs(grid,x,y+1,n,m);
              dfs(grid,x,y-1,n,m);
           
           
           
           
       }
    int closedIsland(vector<vector<int>>& grid) {
        
           int n=grid.size();
          
         int m=grid[0].size();
        
        int count=0;
        
           for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                
                      if(i==0 or j==0 or i==n-1 or j==m-1 ){
                          
                          dfs(grid,i,j,n,m);
                      }
            }
        }
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
            
                
                if(grid[i][j]==0 ){
                    
                    dfs(grid,i,j,n,m);
                    count++;
                }
            }
        }
        
        
        return count;
        
        
    }
};
