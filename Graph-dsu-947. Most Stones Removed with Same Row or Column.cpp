// dsu 
class Solution {
public:
      vector<int>rank;
      vector<int>parent;
    
    int find(int x){
        
        if(parent[x]==x) return x;
        
        return parent[x]=find(parent[x]);
    }
    
    void union_op(int x,int y){
        
        
        if(rank[x]>rank[y]){
            
            parent[y]=parent[x];
        }
        else if(rank[x]<rank[y]){
            parent[x]=parent[y];
        }
        else{
            
            parent[x]=parent[y];
            rank[y]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        
        int n=stones.size();
        rank.resize(n);
        parent.resize(n);
        
        
        for(int i=0;i<n;i++){
            
            parent[i]=i;
            rank[i]=1;
        }
        
        int count=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]){
                    
                    union_op(find(i),find(j));
                }
            }
        }
        
        for(int i=0;i<n;i++){
            
            if(parent[i]==i) count++;
        }
    
   
        return n-count;
    }
};


//------------------------------------------------- dfs-----------------------------------------------------------------
class Solution {
public:
    
    void dfs(int idx,vector<int>&vis,vector<vector<int>>&stones){
        
         int x=stones[idx][0];
         int y=stones[idx][1];
        
           vis[idx]=1;
        
        for(int j=0;j<stones.size();j++){
            
            if(vis[j]==0 and (stones[j][0]==x or stones[j][1]==y)){
                
                dfs(j,vis,stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        
            int n=stones.size();
        
        vector<int>vis(n,0);
        
         int count=0;
        
        for(int i=0;i<stones.size();i++){
     
            
             if(vis[i]==0){
                 count++;
                 
                 dfs(i,vis,stones);
             }
        }
        
        return n-count;
    }
};
