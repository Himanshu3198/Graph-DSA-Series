310. Minimum Height Trees



    
    /* the idea is to use khan's algorithm (topological sort) in this question 
       we need to find the minimum height of the tree  or a  node  which have a minimum distance from that node 
        to any node, so there can be one node if no's of nodes are odd otherwise if even nodes then there can be
        two which have the same minimum distance to all nodes and for the   optimal approach   we will use topological sorting
         two find that nodes 
     */ 

     


//   bruteforce  
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        
              // vector<int>indgree(n,0);
        
             vector<int>adj[n];
        
           for(int i=0;i<edges.size();i++){
               
               
                 adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
           }
        
        
           queue<int>q;
        
           int min_height=INT_MAX;
        
        
           vector<int>res(n);
        
        
          for(int i=0;i<n;i++){
              
              
              q.push(i);
               int curr_hei=0;
                vector<int>vis(n,0);
                  vis[i]=1;
              while(!q.empty()){
                  
                  int size=q.size();
                  curr_hei++;
                  
                 
                  while(size--){
                      
                      
                      int top=q.front();
                        q.pop();
                         vis[top]=1;
                       for(auto it:adj[top]){
                           
                           if(!vis[it]){
                               q.push(it);
                           }
                       }
                  }
                  
              }
              
              min_height=min(min_height,curr_hei-1);
              res[i]=curr_hei-1;
          }
        
             for(auto it:res) cout<<it<<" ";
        
          vector<int>ans;
         for(int i=0;i<n;i++){
             
             if(res[i]==min_height){
                 ans.push_back(i);
             }
         }
        
        return ans;
        
                
    }
};
 // optimal o(n)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        
                  if(n==1) return {0};        
          
        
             vector<int>adj[n];
              vector<int>indgree(n,0);
           for(int i=0;i<edges.size();i++){
               
               
                 adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
               
                indgree[edges[i][0]]++;
                indgree[edges[i][1]]++;
           }
        
        
           queue<int>q;
        
           for(int i=0;i<n;i++){
               
               if(indgree[i]==1){
                   q.push(i);
               }
           }
        
        
            vector<int>res;
        
           while(!q.empty()){
               
               
                    int size=q.size();
                    vector<int>temp;
                  
                   while(size--){
                       
                       
                       int curr=q.front();
                       
                          q.pop();
                        temp.push_back(curr);
                       
                       for(auto it:adj[curr]){
                           
                           indgree[it]--;
                           if(indgree[it]==1){
                               q.push(it);
                           }
                       }
                   }
               
                   res=temp;
           }
        
        
        return res;
           
        
        
       
                
    }
};
