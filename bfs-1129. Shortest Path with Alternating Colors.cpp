class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
           
           vector<vector<int>>Radj(n);
           vector<vector<int>>Badj(n);
        
          vector<pair<int,int>>res(n,{INT_MAX,INT_MAX});
         res[0]={0,0};
        
          for(auto it:redEdges){
              
              Radj[it[0]].push_back(it[1]);
          }
          for(auto it:blueEdges){
              
              Badj[it[0]].push_back(it[1]);
          }
        
           queue<pair<int,int>>q;
        
           q.push({0,1})  ; // red edges
            q.push({0,-1}) ;// blue edges
               
               int currDist=0;
               while(!q.empty()){
                   
                   
                   
                     int size=q.size();
                   while(size--){
                       
                       auto [node,edge]=q.front(); q.pop();
                       
                       
                       if(edge==1){
                           
                           for(auto it:Radj[node]){
                               
                               if(res[it].first>currDist+1){
                                   
                                   q.push({it,-1});
                                   res[it].first=currDist+1;
                               }
                               
                           }
                           
                       }else{
                           
                           
                           for(auto it:Badj[node]){
                               
                                    if(res[it].second>currDist+1){
                                        q.push({it,1});
                                        res[it].second=currDist+1;
                                    }
                           }
                           
                       }
                   }
                    currDist++;
                   
                   
                   
               }
        
        
           vector<int>ans(n);
        
           for(int i=0;i<n;i++){
               
             int  mini=min(res[i].first,res[i].second);
               
               ans[i]=mini==INT_MAX?-1:mini;
               
           }
        
        return ans;
    }
};
