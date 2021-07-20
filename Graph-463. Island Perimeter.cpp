// 463. Island Perimeter

class Solution {
public:
    
     /* In this problem we need to find perimeter of island  it can be calculated by counting the numbers of 
        ones surrounded by zeros  ones represent land and zeros represent water so basically while we 
        applying  flood fill  when we counter zeoros it means it is a boundary of island 
        include it in permeter and also we go beyond the boundaries it also  water surrounded region
        include that also.*/
    
      int count;
    
      void dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
          
          if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==0){
              
              count++;
              return;
          }
             if(grid[i][j]==-1) return;
          
             grid[i][j]=-1;
           dfs(grid,i+1,j,n,m);
           dfs(grid,i-1,j,n,m);
           dfs(grid,i,j+1,n,m);
           dfs(grid,i,j-1,n,m);
          
      }
    int islandPerimeter(vector<vector<int>>& grid) {
        count=0;
        int n=grid.size();
        int m=grid[0].size();
        
        
        for(int i=0;i<n;i++){
            
        for(int j=0;j<m;j++){
            
            if(grid[i][j]==1){
                
                dfs(grid,i,j,n,m);
                break;
            }
            
        }
          
            
        }
          return count;
    }
};
