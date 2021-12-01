class Solution {
public:
    
    
     vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
                    
                int row=meetings.size();
                int col=meetings[0].size();
         
         
                vector<vector<pair<int,int>>>g(n);
         
         
             for(int i=0;i<row;i++){
                 
                     
                     g[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
                     g[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
                 
             }
         
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         vector<int>vis(n,0);
         vector<int>res;
         pq.push({0,0});
         pq.push({0,firstPerson});
         
         
         
         while(!pq.empty()){
             
             auto [t,x]=pq.top();
             pq.pop();
             
             if(vis[x]) continue;
             
             vis[x]=1;
             
             for(auto &it:g[x]){
                 
                 if(vis[it.first]) continue;
                 if(it.second>=t){
                     
                     pq.push({it.second,it.first});
                 }
             }
         }
         
         
         for(int i=0;i<n;i++){
             
             if(vis[i]) res.push_back(i);
         }
         
         return res;
         
       
         
    
        
    }
};
