// brute force
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> ss(supplies.begin(),supplies.end());
        bool f=true;
        int n=recipes.size();
        vector<int> vis(n,false);
        vector<string> res;
        while(f){
            f=false;
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                bool t=true;
                for(string &s:ingredients[i]){
                    if(ss.find(s)==ss.end()){
                        t=false;
                        break;
                    }
                }
                if(t){
                    f=true;
                    ss.insert(recipes[i]);
                    vis[i]=true;
                    res.push_back(recipes[i]);
                }
            }
        }
        return res;
    }
};



// optimized  topological sort 
//  time complexity O(E+V) +(N*M) N=Recipes M=Ingredient

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        
             unordered_set<string>set;
        
        for(auto it:supplies){
            set.insert(it);
        }
        
        unordered_map<string,vector<string>>adj;
         int n=ingredients.size();
        
           unordered_map<string,int>indegree;
          
          for(auto it:recipes){
              indegree[it]=0;
          }
        
        for(int i=0;i<n;i++){
            
            
            for(int j=0;j<ingredients[i].size();j++){
                
                if(set.find(ingredients[i][j])==set.end()){
                    
                    adj[ingredients[i][j]].push_back(recipes[i]);
                     indegree[recipes[i]]++;
                }
            }
        }
        
        
//         topological sorting 
        
          queue<string>q;
        
        for(auto it:recipes){
            if(indegree[it]==0){
                q.push(it);
            }
        }
        vector<string>res;
        while(!q.empty()){
            
            int size=q.size();
            
            while(size--){
                
                auto curr=q.front();
                 q.pop();
                res.push_back(curr);
                
                for(auto it:adj[curr]){
                    
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }
                
                
            }
        }
        
        return res;
         
    }
};
