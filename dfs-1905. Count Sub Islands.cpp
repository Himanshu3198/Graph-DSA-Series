class Solution {
public:
    
    
     void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,int j,int n,int m, bool &flag){
         
         
         
         if(i<0 or i>=n or j<0 or j>=m or grid2[i][j]!=1){
             
             return;
         }
         
         
         if(grid1[i][j]!=1){
             
             flag=false;
             // return;
         }
         
           grid2[i][j]=0;
         
           dfs(grid1,grid2,i+1,j,n,m,flag);
           dfs(grid1,grid2,i-1,j,n,m,flag);
           dfs(grid1,grid2,i,j+1,n,m,flag);
           dfs(grid1,grid2,i,j-1,n,m,flag);
         
         
         
     }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        
        
        int n=grid1.size();
        int m=grid1[0].size();
        
        
        
        int res=0;
        
        for(int i=0;i<n;i++){
           
            for(int j=0;j<m;j++){
                
                 bool flag=true;
                if(grid2[i][j]==1){
                    dfs(grid1,grid2,i,j,n,m,flag); 
                      if(flag){
                    res++;
                }
                }
              
                
       
            }
          
        }
        
        return res;
    }
};
