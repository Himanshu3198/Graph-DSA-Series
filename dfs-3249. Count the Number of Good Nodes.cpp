class Solution {
public:
    int goodNodes;
    int dfs(unordered_map<int,vector<int>>&graph,int parent,int node){
        int subtree=0;
        vector<int>childList;
        for(auto &nbr:graph[node]){
            if(nbr==parent) continue;
            int size=(1+dfs(graph,node,nbr));
            subtree+=size;
            childList.push_back(size);
        }
        set<int> st(childList.begin(),childList.end());
        if(st.size()<=1) goodNodes++;
        return subtree;
        
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>graph;
        int n = edges.size();
        goodNodes=0;
        for(int i=0;i<n;i++){
             graph[edges[i][0]].push_back(edges[i][1]);
             graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(graph,-1,0);
        return goodNodes;
    }
};
