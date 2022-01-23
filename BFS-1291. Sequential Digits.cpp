class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        
       
         
        
           vector<int>res;
         queue<pair<int,int>>q;
        set<int>st;
        
        
        q.push({0,1});
        
        
        while(!q.empty()){
            
            
            auto [num,idx]=q.front();
            q.pop();
            
            bool flag=false;
            
          
            for(int i=idx;i<=9;i++){
                
                
                num=num*10+i;
                
                
                if(num>=low and num<=high){
                    
                    if(st.find(num)==st.end()){
                         
                    res.push_back(num);
                        st.insert(num);
                    
                    q.push({0,idx+1});
                        flag=true;
                    }
                
                }
                
            }
            
            if( !flag and idx<9){
                q.push({0,idx+1});
            }
        }
        
        sort(res.begin(),res.end());
        return res;
     
    } 
};
