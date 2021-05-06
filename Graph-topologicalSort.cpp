
/* 
    Topological sort in graph
    first make vector for record degree of vertex and obviously there must be 

    one vertex whose degree is  equal to zero  now make a queue and push vertex with zero degree  

	now apply bfs on it pop the front vertex and  print it  then  decrease the  count of degree at current vertex while traversing neighbour 

	 vertex now if degree become  zero on particular vertex push it into the queue.    */
#include <bits/stdc++.h>
using namespace std;

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

			cout<<in[i]<<" ";
		}
		cout<<"\n";


	    
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


		for(auto it:res){

			cout<<it<<" ";
		}
		cout<<"\n";

       
    }
    
    return 0;
}  

// 1
// 6 6
// 5 0
// 4 0
// 5 2
// 4 1
// 2 3
// 3 1
//               degree  2 2 1 1 0 0
// 4 5 0 2 3 1
