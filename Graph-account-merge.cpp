

class Solution {
public:
    
    
    /* problem say that we need to merge the that email id which have same email and name 
    it can be present in different groups so we have to find it and merge it using dfs 
    first map graph acoording to index and email address note:we cannot connects
    the names to the email
    if we do so then it will return only same name and email thats why we need make connection 
    according to its row index we connect all same email to same row then just do dfs of this
    graph and check if we find same email in different group then merge it with its parent group*/
    
    unordered_map<string,int>visit;
     unordered_map<string,vector<string>>mp;
    
    
      void dfs(string s,vector<string>&ans){
          
          
           visit[s]=1;
          
          if(count(s.begin(),s.end(),'@')){
              
              ans.push_back(s);
          }
          
          for(string it:mp[s]){
              
              
             if(!visit[it]){
                 
                 dfs(it,ans);
             }
          }
      }
    vector<vector<string>> accountsMerge(vector<vector<string>>& ac) {
        
        
        
        for(int i=0;i<ac.size();i++){
            
            string s=to_string(i);
            
            
            for(int j=1;j<ac[i].size();j++){
             
                 mp[s].push_back(ac[i][j]);
                mp[ac[i][j]].push_back(s);
            }
            
           
        }
        
        vector<vector<string>>res;
        
        for(int i=0;i<ac.size();i++){
            
            
            string s1=to_string(i);
            
            if(!visit[s1]){
                
                vector<string>ans;
                
                ans.push_back(ac[i][0]);
                
                dfs(s1,ans);
                
                sort(ans.begin()+1,ans.end());
                
                
                res.push_back(ans);
                
                
            }
        }
        
        return res;
    }
};
