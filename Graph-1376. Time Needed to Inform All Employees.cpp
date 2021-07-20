1376. Time Needed to Inform All Employees
// bfs approach
class Solution {
public:
    
    
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int>adj[1000001];
        
        
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
              adj[manager[i]].push_back(i);
        }
        
        int total=0;
        
        
        queue<int>q;
        vector<int>res(n,0);
        
        q.push(headID);
        
        
        while(!q.empty()){
            
            
            int size=q.size();
            
            while(size--){
                
                int cur=q.front();
                
                 q.pop();
                
                
            int prev=informTime[cur];
                
                
                for(auto it:adj[cur]){
                    
                    q.push(it);
                    res[it]=res[cur]+prev;
                }
            }
        }
        
        
        return *max_element(res.begin(),res.end());
 
      
        
        
    }
};


// dfs approach


class Solution {
public:
    
    
     int dfs(vector<int>adj[],int headID,vector<int>&informTime){
        
        
         int maxi=0;
        
        
        for(auto it:adj[headID]){
          maxi=max(maxi, dfs(adj,it,informTime));
        }
         
           return informTime[headID]+maxi;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int>adj[1000001];
        
        
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
              adj[manager[i]].push_back(i);
        }
        
        int total=0;
        
        
      total=  dfs(adj,headID,informTime);
        
        return total;
        
      
        
        
    }
};
