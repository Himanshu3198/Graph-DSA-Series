
 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
    
        
        vector<int>visit(V,0);
        
        queue<int>q;
        for(int i=0;i<V;i++){
            
            if(visit[i]==1 || visit[i]==-1){
                continue;
            }
            
            visit[i]=1;
            q.push(i);
        
        
        while(!q.empty()){
            
            int first=q.front();
            q.pop();
            
            for(int j:adj[first]){
                
               if(visit[j]==0){
                   visit[j]=visit[first]*-1;
                   // visit[j]=-1;
                   q.push(j);
               }
                if(visit[first]==visit[j]){
                    return false;
                }
            }
        }
     
        
    }
           return true;
	    
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends