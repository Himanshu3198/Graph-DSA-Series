839. Similar String Groups
class Solution {
public:
    
      bool isSimilar(string a,string b){
          
          if(a.length()!=b.length()){
              return false;
          }
          
          int count=0;
          
          for(int i=0;i<a.length();i++){
              
              if(a[i]!=b[i]){
                  count++;
              }
              if(count>2){
                  return false;
              }
          }
          
          if(count==2 or count==0){
              return true;
          }
          
          return false;
                
      }
    
       void dfs(vector<string>&strs,set<string>&vis,string cur){
           
           
           if(vis.count(cur)){
               return;
           }
           vis.insert(cur);
           
           for(int i=0;i<strs.size();i++){
               
               if(isSimilar(cur,strs[i])){
                   
                   dfs(strs,vis,strs[i]);
               }
           }
           
       }
    int numSimilarGroups(vector<string>& strs) {
        
        set<string>vis;
        
        int res=0;
        for(string str:strs){
            
            if(!vis.count(str)){
                
                dfs(strs,vis,str);
                res++;
            }
            
        }
        
        
        return res;
        
        
    }
};
