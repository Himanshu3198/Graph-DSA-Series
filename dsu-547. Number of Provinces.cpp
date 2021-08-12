// 547. Number of Provinces

class Solution {
public:
    
      vector<int>parent;
      vector<int>rank;
    
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
    int findCircleNum(vector<vector<int>>& nums) {
        
        int n=nums.size();
         parent.resize(n,-1);
          rank.resize(n,1);
        
          for(int i=0;i<n;i++){
              
              for(int j=i+1;j<n;j++){
                  
                  if(nums[i][j]==1){
                      
                      union_op(find(i),find(j));
                  }
              }
          }
        
          int cnt=0;
        
        for(int i=0;i<n;i++){
            if(parent[i]==-1) cnt++;
        }
        
        return cnt;
    }
};
