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
