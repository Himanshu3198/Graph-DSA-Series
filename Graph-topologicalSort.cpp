#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    
	    vector<int>ans;
	    vector<int>in(V,0);
	    queue<int>q;
	    
	    for(int i=0;i<V;i++){
	        
	        for(auto x:adj[i]){
	            
	            in[x]++;
	        }
	    }
	    
	   for(int i=0;i<V;i++){
	       if(in[i]==0){
	           q.push(i);
	       }
	   }
	   while(!q.empty()){
	       int top=q.front();
	       q.pop();
	       ans.push_back(top);
	       
	       for(auto x:adj[top]){
	              in[x]--;
	           if(in[x]==0){
	               q.push(x);
	               
	           }
	       }
	   }
	   return ans;
	    
	    
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends