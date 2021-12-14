class Solution {
public:
     #define ll long long int
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        
          int n=bombs.size();
          vector<vector<ll>>adj(n);
        
        for(int i=0;i<n;i++){
               ll x1=bombs[i][0];
               ll y1=bombs[i][1];
              
            for(int j=0;j<n;j++){
                 if(i==j) continue; 
                ll x2=bombs[j][0];
                ll y2=bombs[j][1];
       ;
                
                     ll xx=abs(x2-x1),yy=abs(y2-y1);
                ll dist=(xx*xx+yy*yy);
                ll r=(ll)bombs[i][2]*(ll)bombs[i][2];
                if(dist<=r){
                    
                    adj[i].push_back(j);
                }
                
            }
        }
        
          queue<int>q;
          int res=1;
        for(int i=0;i<n;i++){
            
            vector<int>vis(n,0);
            int count=0;
            q.push(i);
        
            while(!q.empty()){
                
                int size=q.size();
               
                while(size--){
                    
                    int curr=q.front();
                    q.pop();
                
                     vis[curr]=1;
                      count++; 
                    
                    
                    for(auto it:adj[curr]){
                    
                        if(!vis[it]){
                            
                            vis[it]=1;
                            q.push(it);
                            
                        }
                    }
                  
                }
            }
            
            res=max(res,count);
            
       
        }
        
        return res;
    }
};
