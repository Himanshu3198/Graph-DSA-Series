// 399. Evaluate Division

class Solution {
public:
    
    
     void dfs(string s,string d,map<string,vector<pair<string,double>>>mp, set<string>&visit,double &ans,double temp){
         
         if(visit.find(s)!=visit.end()==true){
             
             return;
         }
         else{
             
             
             
             visit.insert(s);
             
             if(s==d){
                 ans=temp;
                 return;
             }
             else{
                 
                   for(auto it:mp[s]){
                 
                 dfs(it.first,d,mp,visit,ans,temp*it.second);
             }
                 
             }
             
           
         }
         
     
     }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& que) {
        
        
        
        map<string,vector<pair<string,double>>>mp;
        
        int i=0;
        for(int i=0;i<eq.size();i++){
            
            mp[eq[i][0]].push_back({eq[i][1],val[i]});
           mp[eq[i][1]].push_back({eq[i][0],1/val[i]});
            
       
        }
        
        vector<double>res;
        double ans;
        
       
        
        for(auto it:que){
            
             set<string>visit;
               ans=-1.0;
            
             string s=it[0];
            string d=it[1];
            if(mp.find(s)!=mp.end())
                dfs(s,d,mp,visit,ans,1.0);
                
            res.push_back(ans);
            
        }
        
        return res;
        
    }
};
