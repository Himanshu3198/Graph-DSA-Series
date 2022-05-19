
//  time complexity O(n*m)
//  space complexity O(n*m)
class Solution {
public:
    
    int dp[201][201];
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool valid(int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m)return true;
        return false;
    }
    int dfs(vector<vector<int>>& mat,int i,int j,int n,int m){
        
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=1;
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            if( valid(x,y,n,m) && (mat[x][y]>mat[i][j]))
            dp[i][j]=max(dp[i][j],1+dfs(mat,x,y,n,m));
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        
        memset(dp,-1,sizeof(dp));
        int maxPath=0;
        
        for(int i=0;i<mat.size();i++){
            
            for(int j=0;j<mat[i].size();j++){
                
                maxPath=max(maxPath,dfs(mat,i,j,mat.size(),mat[i].size()));
            }
        }
        return maxPath;
    }
};
