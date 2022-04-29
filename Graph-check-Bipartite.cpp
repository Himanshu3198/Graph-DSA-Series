class Solution {
public:
    
     vector<int>color;
    bool dfs(int node,int parentColor,vector<vector<int>>& graph){
        
        if(color[node]!=0){
            return color[node]!=parentColor;
        }
        color[node]=-parentColor;
        for(auto it:graph[node]){
            if(!dfs(it,color[node],graph)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        color.assign(n+1,0);
        for(int i=0;i<n;i++){
            
            if(!dfs(i,-1,graph)) return false;
        }
        return true;
        
        
    }
};
