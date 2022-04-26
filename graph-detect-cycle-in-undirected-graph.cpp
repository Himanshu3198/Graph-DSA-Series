
//  method 1  dsu 
    int findPar(int x,vector<int>&parent){
          if(parent[x]==x) return x;
          return parent[x]=findPar(parent[x],parent);
      }
      void union_op(int x,int y,vector<int>&parent,vector<int>&rank){
           x=findPar(x,parent);
           y=findPar(y,parent);
           if(x==y) return;
           if(x>y){
               parent[y]=x;
               rank[x]+=1;
           }else{
               parent[x]=y;
               rank[y]+=1;
           }
      }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
           vector<int>rank(V,0),parent(V);
           vector<int>vis(V,0);
           for(int i=0;i<V;i++) parent[i]=i;
           for(int i=0;i<V;i++){
               vis[i]++;
               for(auto &it:adj[i]){
                   if(vis[it]) continue;
                   if(findPar(it,parent)==findPar(i,parent)) return true;
                   else union_op(i,it,parent,rank);
               }
           }
           return false;
    }

// detect cycle in undirected graph    
bool isCyclic(vector<int>adj[],vector<int>visit,int curr,int V){
        
        if(visit[curr]==2){
            return true;
        }
        
        visit[curr]=1;
        
        for(auto it:adj[curr]){
            
            if(visit[it]==1){
                
                visit[it]=2;
                
            }
            else{
                
                if(isCyclic(adj,visit,it,V)){
                    
                    return true;
                }
            }
        }
        
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    
	    
	    vector<int>visit(V,0);
	    
	    
	    for(int i=0;i<V;i++){
	          visit[i]=1;
	        for(auto it:adj[i]){
	            
	            if(isCyclic(adj,visit,it,V)){
	                return true;
	            }
	        }
	        
	    }
	    
	    return false;
	}
