class Solution {
public:
    long long dfs(vector<vector<int>>&graph,int node,vector<int>&vis){
        if(vis[node]==1) return 0;
        long long ans=0;
        vis[node]=1;
        for(auto &it:graph[node]){
            
           ans=ans+dfs(graph,it,vis);
        }
        return ans+1;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        long long ans=((long long)n*(n-1))/2;
       
        vector<vector<int>>graph(n);
        for(auto &it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
            long long curr=dfs(graph,i,vis);
            ans-=(((long long)curr*(curr-1))/2);
            }
        }
        return ans;
    }
};
