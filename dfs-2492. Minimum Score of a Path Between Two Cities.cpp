class Solution {
public:
    void dfs(int node,unordered_map<int,vector<pair<int,int>>>&g,vector<int>&vis,int &ans){
        
        vis[node]=1;
        for(auto it:g[node]){
            ans=min(ans,it.second);
             if(!vis[it.first]){
                 dfs(it.first,g,vis,ans);
             }
           
        }
          
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>vis(n+1,0);
        unordered_map<int,vector<pair<int,int>>>g;
        for(auto &it:roads){
            g[it[0]].push_back({it[1],it[2]});
            g[it[1]].push_back({it[0],it[2]});
        }
        int ans=INT_MAX;
        dfs(1,g,vis,ans);
        return ans;
    }
};
