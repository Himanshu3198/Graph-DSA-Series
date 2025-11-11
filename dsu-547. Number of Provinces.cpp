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

// python code 
class Solution:
    def find_parent(self,parent: List[int],x: int)->int:
        if x == parent[x]:
            return x
        parent[x] = self.find_parent(parent,parent[x])
        return parent[x]
    def union_op(self,parent:List[int],rank: List[int],x: int,y: int)->None:
        u = self.find_parent(parent,x)
        v = self.find_parent(parent,y)
        if u == v:
            return
        if rank[u]>rank[v]:
            parent[v] = u
        elif rank[v]>rank[u] :
            parent[u] = v
        else :
            parent[v] = u
            rank[u]  = rank[u] + 1


    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        parent = [ i for i in range(0,n)]
        rank = [0]*n

        for i in range(0,n):
            for j in range(1,n):

                if isConnected[i][j] == 1:
                    self.union_op(parent,rank,i,j)
        
        ans = set()

        for x in parent:
            ans.add(self.find_parent(parent,x))
        return len(ans)

    
        
