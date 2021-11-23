class Solution {
public:
        vector<int>parent,rank;
         int find(int x){
          
          if(parent[x]==-1) return x;
          
          return parent[x]=find(parent[x]);
      }
    
   void union_op(int x,int y){
        
           if(x==y){
               return;
           }
        
        if(rank[x]>rank[y]){
            parent[y]=x;
            rank[x]+=rank[y];
        }
       else{
           parent[x]=y;
           rank[y]+=rank[x];
       }
    }
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        parent.resize(100002,-1);
        rank.resize(100002,1);
        
        for(auto it:nums){
            
            
            for(int i=2;i<=sqrt(it);i++){
                
                if(it%i==0){
                    
                    union_op(find(it),find(i));
                     union_op(find(it),find(it/i));
                }
            }
        }
        
     
        unordered_map<int,int>mp;
        
        int res=0;
        
        for(auto it:nums){
            
            int sameParent=find(it);
            
            res=max(res,1+mp[sameParent]);
            mp[sameParent]+=1;
        }
        
        return res;
        
        
    }
};
