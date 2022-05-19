class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool valid(int i,int j,int n,int m,vector<vector<bool>>& vis){
        if(i>=0 && i<n && j>=0 && j<m && !vis[i][j])return true;
        return false;
    }
    int bfs(vector<vector<int>>&matrix,int n,int m,int i,int j){
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        priority_queue<vector<int>>q;
        q.push({0,i,j});
        
        int res=0;
        while(!q.empty()){
            
            int size=q.size();
           
            while(size--){
                
            auto [i,j,path]=q.top();
                q.pop();
                  // i=v[1],j=v[2];
                // int path=v[0]+1;
                res=max(res,path);
                vis[i][j]=true;
                 for(int k=0;k<4;k++){
                     int x=dx[k]+i;
                     int y=dy[k]+j;
                if(valid(x,y,n,m,vis) && matrix[x][y]>matrix[i][j]){
                       q.push({x,y,path});
                }
            }
          
        }
    }
        return res;   
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
           int n=matrix.size();
           int maxPath=0;
           for(int i=0;i<n;i++){
               int m=matrix[i].size();
               for(int j=0;j<m;j++){
                   cout<<matrix[i][j]<<" ";
               maxPath=max(maxPath,(bfs(matrix,n,m,i,j)));
               }
               cout<<"\n";
           }
           return maxPath;       
    }
};
