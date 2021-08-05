310. Minimum Height Trees

class Solution {
public:
    
    /* the idea is to use khan's algorithm (topological sort) in this question 
     two nodes may have same height else rest of have one basically  we have two 
     find the indgree of all nodes  if nodes having indgree 1 then they the are not
     contributing anything two deteriming the height so we removed it and also
     decresee  their count from their children after all the proess we will only 
     left with one or two nodes that would be our answer
     */ 
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
     
        
         vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        vector<int>res;
        
        
        for(auto it:edges){
            
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
            indeg[it[0]]++;
            
            indeg[it[1]]++;
        }
           
        
        
        if(n==1){
            return {0};
        }
        if(n==2){
            
            res.push_back(edges[0][0]);
            res.push_back(edges[0][1]);
            
            return res;
        }
        
      
        
        
        for(auto it:indeg){
            cout<<it<<" ";
        }
        
        
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            
             if(indeg[i]==1){
                 q.push(i);
                 indeg[i]--;
             }
        }
        
        
        
        while(!q.empty()){
            
            
            int size=q.size();
            res.clear();
            
            while(size--){
                
                int cur=q.front();
                
                res.push_back(cur);
                q.pop();
                
            
                for(auto it:adj[cur]){
                    
                    indeg[it]--;
                    
                    if(indeg[it]==1){
                       
                        q.push(it);
                    }
                    
                }
            }
        }
        
        return res;
        
        
        
    }
};
