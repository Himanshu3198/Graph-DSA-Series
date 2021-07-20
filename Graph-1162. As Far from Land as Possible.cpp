// 1162. As Far from Land as Possible
class Solution {
public:
    
     bool isSafe(int i,int j,int n,vector<vector<int>>&grid){
         
         if(i<0 or i>=n or j<0 or j>=n or grid[i][j]!=0){
             
             return false;
         }
         
         return true;
     }
    
    
    int bfs(vector<vector<int>>&grid, queue<pair<int,int>>&q,int n){
      
        int max_distance=0;
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        
        
        
        while(!q.empty()){
            
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            
            
            
            for(int k=0;k<4;k++){
                
                int xx=dx[k]+x;
                int yy=dy[k]+y;
                
                if(isSafe(xx,yy,n,grid)){
                    
                    
                    q.push({xx,yy});
                    
                    grid[xx][yy]=grid[x][y]+1;
                    
                    max_distance=max(max_distance,grid[xx][yy]);
                }
            }
            
        }
        
        
        return max_distance-1;
    
        
        
    }
    int maxDistance(vector<vector<int>>& grid) {
     
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
         int n=grid.size();
        
       
        
        
        
        
        queue<pair<int,int>>q;
        
        
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    
                    q.push({i,j});
                }
            }
        }
        
        
        return bfs(grid,q,n);
        
        
        
            
    }
};
