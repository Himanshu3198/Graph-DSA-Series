class Solution {
public:
    
       /* In this question we can make graph of pairs  which have one edge common  and can do 
          swaping any number of times so the  group of  edges will be in sorted order .
          
          Time complexity O(E+V+Vlog(V));
          Vlog(V) for sorting the same group edges
          space complexity O(E+V)
         
          */
      void dfs(vector<int>graph[],vector<bool>&vis,vector<int>&index,vector<char>&letters,int node,string &s){
          
          if(vis[node]==true) return;
           vis[node]=true;
           letters.push_back(s[node]);
           index.push_back(node);
          for(auto it:graph[node]){
              
              if(vis[it]==false){
                  dfs(graph,vis,index,letters,it,s);
              }
          }
      }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
     
           int n=s.size();
           vector<int>graph[n];
           for(int i=0;i<pairs.size();i++){
               int s=pairs[i][0];
               int d=pairs[i][1];
               graph[s].push_back(d);
               graph[d].push_back(s);
           }
        
           vector<bool>vis(n,false);
           for(int i=0;i<n;i++){
                 vector<int>index;
                 vector<char>letters;
               for(auto it:graph[i]){
                   
                   if(vis[it]==false){
                       
                       dfs(graph,vis,index,letters,it,s);
                   }
                   
               }
                sort(index.begin(),index.end());
                sort(letters.begin(),letters.end());
               for(int j=0;j<index.size();j++){
                   
                   s[index[j]]=letters[j];
               }
                
           }
        
        return s;
    }
};

class Solution {
public:
    
    int findPar(int x,vector<int>&parent){
        if(parent[x]==x) return x;
        return parent[x]=findPar(parent[x],parent);
    }
    void union_op(int u,int v,vector<int>&parent,vector<int>&rank){
        int x=findPar(u,parent);
        int y=findPar(v,parent);
        if(x==y) return;
        if(rank[x]>rank[y]){
            parent[y]=x;
            rank[x]+=1;
        }else{
            parent[x]=y;
            rank[y]+=1;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
            int n=s.size();
            vector<int>rank(n,0);
            vector<int>parent(n);
            for(int i=0;i<n;i++) parent[i]=i;
            for(int i=0;i<pairs.size();i++){
                int u=pairs[i][0];
                int v=pairs[i][1];
                union_op(u,v,parent,rank); 
            }
            unordered_map<int,vector<int>>mp;
            for(int i=0;i<n;i++){
                 mp[findPar(i,parent)].push_back(i);
            }
             
           for(auto it:mp){
            
               vector<int>index;
               vector<char>letters;
               for(auto v:it.second){
                   letters.push_back(s[v]);
                   index.push_back(v);
               }
               sort(index.begin(),index.end());
               sort(letters.begin(),letters.end());
                 for(int i=0;i<index.size();i++){
                     s[index[i]]=letters[i];
                 }
           }
          return s;
    }
};
