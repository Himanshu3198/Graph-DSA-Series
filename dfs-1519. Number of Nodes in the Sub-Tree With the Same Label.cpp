class Solution {
public:  vector<int>res;
    
      vector<int> dfs(vector<vector<int>>& graph,int curr,vector<int>&vis,string &labels){
          
            vis[curr]=1;
            vector<int>freq(26,0);
            freq[labels[curr]-'a']=1;
          
         
          
          
            for(auto it:graph[curr]){
                  if(vis[it]) continue;
               
                    
                    vector<int>temp=dfs(graph,it,vis,labels);
                    
                    for(int i=0;i<26;i++){
                        freq[i]+=temp[i];
                    }
                
            }
           
          res[curr]=freq[labels[curr]-'a'];
          return freq;
          
            
      }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<vector<int>>graph(n+1,vector<int>());
        
        
         for(auto it:edges){
             
             graph[it[0]].push_back(it[1]);
               graph[it[1]].push_back(it[0]);
         }
        
        res.resize(n,1);
         vector<int>vis(n+1,0);
        dfs(graph,0,vis,labels);
        
        return res;
          
    }
};
