// Satisfiability of Equality Equations
class Solution {
public:    
    vector<int> parent;    
    int findParent(int p){
        return (parent[p]==p) ? p : parent[p] = findParent(parent[p]);
    }
    
    bool equationsPossible(vector<string>& equations) {   
        parent.assign(26,0);
        for(int i=0;i<26;i++)
            parent[i] = i;
        
        for(auto eq : equations){
            if(eq[1]=='=') {
                int x = findParent(eq[0]-'a');
                int y = findParent(eq[3]-'a');
                parent[x] = y ;
            }
        }
        
        for(auto eq : equations){
            if(eq[1]=='!') {
                if(findParent(eq[0]-'a') == findParent(eq[3]-'a'))
                   return false;
            }
        }
        return true;    
    }
};
