802. Find Eventual Safe States


class Solution {
public:
    
    
    
    /*  
         basically we have to include the edges which are notthe  part of the cycles that can be done easily
         using dfs   mark 0 as unvisited nodes ,1 as last visited nodes and 2 as safe node which are not part of 
         any cycle   after completion of dfs just iterate through visit vector and add the edges to result  which are safe (2)*/
    
    
    
    
    bool isCyclic(vector<vector<int>>& graph,vector<int>&visit,int curr,int V){
        
        if(visit[curr]==2){    // safe nodes 
            return true;
        }
        
        if(visit[curr]==1) {   // second time visited 
            return false;
        }
        
        visit[curr]=1;   // first time visited 
        
        for(auto it:graph[curr]){
            
            if(!isCyclic(graph,visit,it,V)){
                return false;
            }
        }
        visit[curr]=2;   // if we reach to this statement then its means the current node is safe 
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V=graph.size();
         vector<int>visit(V,0);
	    
	    
	    for(int i=0;i<V;i++){
	      
	    
	            
	            if(isCyclic(graph,visit,i,V)){
	                
	            }
	        
	        
	    
	    }
        
        for(int i=0;i<V;i++){
            cout<<visit[i]<<" ";
        }
        
        vector<int>res;
        
          for(int i=0;i<V;i++){
          if(visit[i]==2) res.push_back(i);
        }
        
        
        return res;
        
        
        
        
    }
};
