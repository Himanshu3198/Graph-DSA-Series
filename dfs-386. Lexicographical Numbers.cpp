class Solution {
public:
    
      vector<int>res;
    
    void solve(int n,int curr){
        
        if(curr>n){
            return;
        }
        
        res.push_back(curr);
        
        for(int j=0;j<=9;j++){
            
            solve(n,curr*10+j);
        }
        
       
        
    }
    vector<int> lexicalOrder(int n) {
        
        
        
        
        for(int i=1;i<=9;i++){
            
            solve(n,i);
        }
        
        return res;
    }
};
