#include <bits/stdc++.h>
using namespace std;
int V=4;
vector<int>adj[4];
void addEdge(vector<int>adj[],int s,int d){
    adj[s].push_back(d);
}

    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        // approach is to use topological sort because we graph have cycle  
        //  then then indegree of of all nodes will not be zeros
        
        
        vector<int>indegree(V,0);
        
        
        for(int i=0;i<V;i++){
            
            for(auto it:adj[i]){
                
                indegree[it]++;
            }
        }
        
         queue<int>q;
        for(int i=0;i<V;i++){
            
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int count=0;
        
        
        while(!q.empty()){
            
            auto curr=q.front(); q.pop();
            count++;
            
            for(auto &it:adj[curr]){
                indegree[it]--;
                
                if(indegree[it]==0)q.push(it);
                
            }
        }
        
        
        
        return  count!=V;
        
        
        
    }


int main() {

	
     addEdge(adj,0,1);
      addEdge(adj,0, 2);
      addEdge(adj,1, 2);
      addEdge(adj,2, 0);
      addEdge(adj,2, 3);
      addEdge(adj,3, 3);

      if(isCyclic()){
          cout<<"graph contain cycle\n";
      }
      else{
          cout<<"graph does not contain any cycle\n";
      }
      return 0;
	
	return 0;
}  



