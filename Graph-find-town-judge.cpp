
// 997. Find the Town Judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        
        
        
          /* make vector pair of visit and visited  and mark it by iterate over trust vector then just iterate over this pair of vector and check if according to question judge would be the person who trust none and trusted by everyone therefore trusted should be n-1 and trust should be 0  if this condition satisfy return the index*/
          
         int size=trust.size();
        vector<pair<int,int>>arr(n+1,{0,0});
        
     
        
        for(int i=0;i<trust.size();i++){
            
              int s=trust[i][0];
              int d=trust[i][1];
            
                 arr[s].first+=1;
                arr[d].second+=1;
        }
        
           
        for(int i=1;i<=n;i++){
            
              if(arr[i].first==0 and arr[i].second==n-1) return i;
        }
        
        
     
        
        return -1;
    }
};
