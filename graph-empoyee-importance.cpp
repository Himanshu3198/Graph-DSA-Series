// 690. Employee Importance

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
       void dfs(unordered_map<int,Employee*>&mp,int id ,int &sum){
           
           sum+=mp[id]->importance;
           for(auto x:mp[id]->subordinates){
               
               dfs(mp,x,sum);
           }
       }
    int getImportance(vector<Employee*> employees, int id) {
        
        
        unordered_map<int,Employee*>mp;
        
        for(auto it:employees){
            
            mp[it->id]=it;
        }
        
        int sum=0;
        
        dfs(mp,id,sum);
        
        return sum;
    }
};
