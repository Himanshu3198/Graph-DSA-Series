class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
      unordered_map<int,vector<int>>graph;
      vector<int>indegree(quiet.size(),0);
      for(int i=0;i<richer.size();i++){
        graph[richer[i][0]].push_back(richer[i][1]);
        indegree[richer[i][1]]++;
      }
      queue<int>q;
      for(int i=0;i<quiet.size();i++){
         if(indegree[i]==0) q.push(i);
      }
      vector<int>ans(quiet.size(),0);
      for(int i=0;i<quiet.size();i++){
        ans[i]=i;
      }
      while(!q.empty()){
        int curr_node = q.front();
        q.pop();
        for(auto ngr_node:graph[curr_node]){
          indegree[ngr_node]--;
          if(indegree[ngr_node]==0) q.push(ngr_node);
          if(quiet[ans[ngr_node]]>quiet[ans[curr_node]]){
            ans[ngr_node]=ans[curr_node];
          }
        }
        
      }
      return ans;
  
    }
};
