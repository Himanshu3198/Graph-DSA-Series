#define ll long long 
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       
           vector<int>indeg(n,0);
           ll ans=0LL,val=n;
        
           for(auto it:roads){
               
               int x=it[0];
               int y=it[1];
               indeg[x]++;
               indeg[y]++;
           }
           // for( auto it:indeg) cout<<it<<" ";
           // cout<<"\n";
           priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
           for(int i=0;i<n;i++){
               pq.push({indeg[i],i});
           }
           while(!pq.empty()) {
               
               int sec=pq.top().second;
               int fir=pq.top().first;
               indeg[sec]=val;
               // cout<<sec<<" "<<indeg[sec]<<"\n";
               val--;
               pq.pop();
               
           }
          for(auto it:roads){
               
               int x=it[0];
               int y=it[1];
               ans+=(indeg[x]+indeg[y]);
           }
           return ans;
        
          
        
    }
};
