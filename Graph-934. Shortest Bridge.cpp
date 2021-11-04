// 934. Shortest Bridge

class Solution {
public:
      queue<pair<int,pair<int,int>>>q;
      void dfs1(vector<vector<int>>&grid,int i,int j,int n,int m){
          if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=1){
            return;
        }
          
          grid[i][j]=2;
          q.push({0,{i,j}});
          
          dfs1(grid,i+1,j,n,m);
           dfs1(grid,i-1,j,n,m);
           dfs1(grid,i,j+1,n,m);
           dfs1(grid,i,j-1,n,m);
            
          
      }
        int dfs2(vector<vector<int>>&grid,int i,int j,int n,int m){
        
        if(i<0 or i>=n or j<0 or j>=m ){
            return 0;
        }
         return 1;
      
    }
 
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        
          bool flag=false;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1){
                    dfs1(grid,i,j,n,m);
                    q.push({0,{i,j}});
                    flag=true;
                    break;
                    
                }
                
            }
           if (flag){
                break;
            }
        }
        
           int dx[4]={1,-1,0,0};
        
           int dy[4]={0,0,1,-1};
        while(!q.empty()){
            
            
            int size=q.size();
             
            
            while(size--){
                
                int level=q.front().first;
                int i=q.front().second.first;
                int j=q.front().second.second;
                  q.pop();
                
                
                
                for(int k=0;k<4;k++){
                    
                    if(dfs2(grid,i+dx[k],j+dy[k],n,m)==1){
                         
                        if(grid[i+dx[k]][j+dy[k]]==0){
                            
                            grid[i+dx[k]][j+dy[k]]=2;
                            q.push({level+1,{i+dx[k],j+dy[k]}});
                        }
                        
                        else if(grid[i+dx[k]][j+dy[k]]==1){
                              return level;
                        }
                    }
                    
                    
                }
                
                

            }
            
                
                
            }
           
    
        
        return -1;
        
        
    }
};
