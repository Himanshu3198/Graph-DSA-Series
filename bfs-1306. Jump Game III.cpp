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
