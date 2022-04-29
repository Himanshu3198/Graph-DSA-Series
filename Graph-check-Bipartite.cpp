class Solution {
public:
    
   /* 
     A bipartite is a graph which can be divded into two different half
     to check given graph is bipartite we will mark vertex with 2 colors
     if there is no adjacent has same color then graph is bipartite otherwise
     no.
      time complexity O(E+V
      Space complexity O(V)
      */
    
     vector<int>color;
    bool dfs(int node,int &parentColor,vector<vector<int>>& graph){
        
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
        color.assign(n,0);
        int parentColor=-1;
        for(int i=0;i<n;i++){
            
            if(color[i]==0 and !dfs(i,parentColor,graph)) return false;
        }
        return true;
        
        
    }
};
