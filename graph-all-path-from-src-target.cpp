// 797. All Paths From Source to Target


class Solution {
public:
    
    
    
    void dfs(vector<vector<int>>&graph,vector<vector<int>>&res,vector<int>v,int src,int dst){
        
         v.push_back(src);
        
        
          if(src==dst){
              
              res.push_back(v);
              return;
          }
        
           
          for(auto it:graph[src]){
              
              dfs(graph,res,v,it,dst);
          }
        
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
     
           vector<vector<int>>res;
        
          int n=graph.size();
        
              if(n==0){
                  return res;
              }
        
         int src=0,dst=n-1;
        
        vector<int>v;
        
        dfs(graph,res,v,src,dst);
        
        return res;
    }
};
