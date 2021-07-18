// 1654. Minimum Jumps to Reach Home


class Solution {
public:
    
    
    
       /*   
           problem: we have reach at home which is distance x from 0   by jumping forward 
           and backward direction and we cannot jump twice in  a row  and  in problem also given sum 
           forbidden  distance  from where  we cannot move further so we can do it easily by bfs first take set and 
           insert  forbidden distance nums in it for checking now take visited array with two parameters int which is
           distance and second bool which tells that this distance is already visited or not if we not take visited array
           then infinite  or tle case can be arrived . now just push  intitially distance 0 in q and  apply the two opeation 
           by adding cur element of q with forward and backward jumps  and check the following condition if curr is equal to x then return 
           steps else if went through all forbiden distance and not able to find min steps then return -1
            
          */
    int minimumJumps(vector<int>& nums, int a, int b, int x) {
        
          unordered_set<int> set;
        
        
        for(auto it:nums){
            set.insert(it);
        };
        
        vector<vector<int>>visited(2,vector<int>(10000));
        
        queue<pair<int,bool>>q;
        
        q.push({0,false});
        
        visited[0][0]=1;
        visited[1][0]=1;
        
        int ans=0;
        while(!q.empty()){
            
            
            int qsize=q.size();
            
            while(qsize--){
                
                int curr=q.front().first;
                int flag=q.front().second;
                
                  q.pop();
                   
                
                 if(curr==x){
                     return ans;
                 }
                
                int forward=curr+a;
                int backward=curr-b;
                
                if(forward<10000 and visited[0][forward]==false and !set.count(forward)){
                    q.push({forward,false});
                    visited[0][forward]=true;
                }
                
                
                
                if(backward>=0 and visited[1][backward]==false and !set.count(backward) and !flag){
                    
                    q.push({backward,true});
                    
                    visited[1][backward]=true;
                }
                
            
            }
            ans++;
        }
        
        return -1;
        
        
     
        
    }
};
