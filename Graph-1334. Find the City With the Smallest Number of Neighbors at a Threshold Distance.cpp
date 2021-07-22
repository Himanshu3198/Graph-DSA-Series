// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distance){
        
        
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        
        
        for(int i=0;i<edges.size();i++){
            
            dp[edges[i][0]][edges[i][1]]=edges[i][2];
             dp[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        
        
        for(int k=0;k<n;k++){
            
            for(int i=0;i<n;i++){
                
                for(int j=0;j<n;j++){
                    
                    
                    if(dp[i][k]==INT_MAX or dp[k][j]==INT_MAX) continue;
                    
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        
        int ma=INT_MAX;
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            int count=0;
            
            for(int j=0;j<n;j++){
                
                if(i!=j and dp[i][j]<=distance){
                    count++;
                }
            }
            
            if(ma>=count){
                ma=count;
                ans=i;
            }
        }
        
        return ans;
        
    }
};
