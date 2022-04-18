class Solution {
public:
    
     int dx[4]={-1,1,0,0};
     int dy[4]={0,0,-1,1};
    bool isValid(vector<vector<int>>&grid,int i,int j,int n,int m){
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==1) return true;
       return false;
    }
    int dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(!isValid(grid,i,j,n,m)) return 0;
         grid[i][j]=0;
         int ans=0;
         for(int k=0;k<=3;k++){
             int x=dx[k]+i;
             int y=dy[k]+j;
             ans+=dfs(grid,x,y,n,m);
         }
         return ans+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    maxArea=max(maxArea,dfs(grid,i,j,n,m));    
            }
        }
        return maxArea;  
    }
};
