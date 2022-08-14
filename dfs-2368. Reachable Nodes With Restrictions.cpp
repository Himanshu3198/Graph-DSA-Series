class Solution {
public:
    int dfs(vector<vector<int>>&graph,vector<int>&visit,int node){
        if(visit[node]) return 0;
        visit[node]=1;
        int count=1;
        for(auto it:graph[node]){
             if(!visit[it])
                 count+=dfs(graph,visit,it);
        }
        return count;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
             vector<vector<int>>graph(n);
             for(auto it:edges){
                 graph[it[0]].push_back(it[1]);
                 graph[it[1]].push_back(it[0]);
             }
            vector<int>visit(n,0);
            for(auto it:restricted) visit[it]=1;
            return dfs(graph,visit,0);
          
    }
};
