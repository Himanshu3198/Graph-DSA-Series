class Solution {
public:
      
 int solve(string s1,string s2){

    int n=s1.length();
      queue<string>q;
      unordered_map<string,int>m;
      q.push(s1);
      int count =-1;
      while(!q.empty()){
        count++;
        int sz=q.size();
        for(int i=0;i<sz;i++){
          string s=q.front();
          q.pop();
          if(s==s2) return count;
          for(int j=count;j<s.length();j++){
            for(int k=j+1;k<s.length();k++){
            swap(s[j],s[k]);
            if(m.find(s)==m.end() && s[count]==s2[count]){
              q.push(s);
              m[s]=1;
            }
            swap(s[j],s[k]);
            
          }
          
          
        }
        
        } 
        
        
      }
      
      return count;
      
      
      
  
  
  
  }
  
    int kSimilarity(string s1, string s2) {
    
     int i=0;
      string ss="";
      string target="";
      while(i<s1.length()){
          if(s1[i]!=s2[i]){
            ss+=s1[i];
            target+=s2[i];
          }
        i++;
        
      }
      
      
    return solve(ss,target);
      

    }

};
