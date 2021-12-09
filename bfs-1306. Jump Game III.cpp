//  dfs 
//  time & space complexity O(n)
class Solution {
public:
    
     bool solve(vector<int>&arr,int idx,vector<int>&vis){
         
         
         if(idx<0 or idx>=arr.size() ) return false;
         
          if(vis[idx]==1){
              return false;
          }
         if(arr[idx]==0) return true;
         
         
            vis[idx]=1;
         
         return solve(arr,idx+arr[idx],vis) || solve(arr,idx-arr[idx],vis);
     }
    bool canReach(vector<int>& arr, int start) {
    
           vector<int>vis(arr.size(),0);
        return solve(arr,start,vis);
     

    }
};
// bfs approach  
time & space comeplexity: O(n) 
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        
         queue<int>q;
        q.push(start);
        
        int n=arr.size();
        while(!q.empty()){
            int size=q.size();
             while(size--){
            int curr=q.front();
              q.pop();
               
              if(arr[curr]==0){
                  return true;
              }
                 if(arr[curr]<0) continue;
               
            if(curr+arr[curr]<n){
                q.push(curr+arr[curr]);
            }
            if(curr-arr[curr]>=0){
                q.push(curr-arr[curr]);
            }
            arr[curr]=-arr[curr];
                 
             }
        }
        
        return false;
    }
};
