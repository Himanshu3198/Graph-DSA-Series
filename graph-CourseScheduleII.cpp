// 210. Course Schedule II

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        
        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<indegree.size();i++){
             if(indegree[i]==0) q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            
            int t=q.front();
            q.pop();
            ans.push_back(t);
            
            for(int j=0;j<adj[t].size();j++){
                indegree[adj[t][j]]--;
                if(indegree[adj[t][j]]==0) q.push(adj[t][j]);
            }
            
        }
        
        if(ans.size()==numCourses) return ans;
        else{ ans.clear(); return ans;}
        
        
    
	
         
    }
};
