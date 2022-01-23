//  Time Complexity O(n)

class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        
        int n=arr.size();
        if(n==1) return 0;
        unordered_map<int,vector<int>>mp;
        
        
        for(int i=0;i<n;i++){
            
            mp[arr[i]].push_back(i);
        }
        
     
         queue<pair<int,int>>q;
        
          q.push({0,0});
            
           int res=n;
         vector<int>vis(n,0);
          while(!q.empty()){
              
              
             
              int size=q.size();
              
              while(size--){
                  
              auto [idx,step]=q.front();
               q.pop();
                  
                  if(idx==(n-1)){
                      
                      res=min(res,step);
                     
                  }
                  if(vis[idx]){
                      break;
                  }
                  vis[idx]=1;
                  if(idx-1>=0){
                      
                      q.push({idx-1,step+1});
                  }
                  
                  if(idx+1<n){
                      q.push({idx+1,step+1});
                  }
                  
                  vector<int>temp=mp[arr[idx]];
                  
                  
                  if(temp.size()>0){
                      
                      
                      
                      for(int i=0;i<temp.size();i++){
                          if(temp[i]!=idx) 
                          q.push({temp[i],step+1});
                      }
                                            

                      mp[arr[idx]].clear();
                  }
                  
              }
                   
          }
        
        return res;
    }
};
