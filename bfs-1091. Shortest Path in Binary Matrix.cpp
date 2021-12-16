class Solution {
public:
    
       bool isvalid(vector<vector<int>>&grid,int i,int j,int n,int m){
           
           if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=0){
               return false;
           }
           return true;
       }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
     
        
        
          int n=grid.size();
          int m=grid[0].size();
         int moves[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
                       {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
          
        
           queue<pair<int,int>>q;
            if(grid[0][0]==1) return -1;
            if(grid[n-1][m-1]==1) return -1;
           q.push({0,0});
        
           int min_path=0;
          
           while(!q.empty()){
               
               
                 min_path++;
                int size=q.size();
               
                 while(size--){
                     
                     int x=q.front().first;
                     int y=q.front().second;
                         q.pop();
                      
                     
                     if(x==n-1 and y==m-1) return min_path;
                     for(int i=0;i<8;i++){
                         
                         if(isvalid(grid,x+moves[i][0],y+moves[i][1],n,m)){
                             
                             q.push({x+moves[i][0],y+moves[i][1]});
                             grid[x+moves[i][0]][y+moves[i][1]]=1;
                         }
                     }
                     
                     
                 }
               
           }
        
           return -1;
    }
};
