1791. Find Center of Star Graph
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
     
        int n=0;
        
        
          for(int i=0;i<edges.size();i++){
            
            n=max({n,edges[i][0],edges[i][1]});
        }
        vector<int>in(n+1,0);
     
        cout<<n;
     
        
        for(int i=0;i<edges.size();i++){
            
                  for(auto x:edges[i]){
                      
                      in[x]++;
                  }
        }
        
        
        for(int i=0;i<in.size();i++){
            
            if(in[i]==n-1){
                
                return i;
            }
        }
        
        return -1;
        
      
    }
};
