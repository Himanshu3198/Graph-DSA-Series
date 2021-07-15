// 841. Keys and Rooms

class Solution {
public:
    
    
      /*   the problem statement say that we have n rooms labeled as 0 to n-1  and we have to visit the all 
            the rooms. for visting the room we need a key  to unlock that room and we found key of others room in      
             current room  so basically we can visit a room only if have  a key this statement is repersent as graph 
             and its adjacent vertices represented in the form of key do simple dfs of this graph and later check if we have
            successfully visited the  all rooms or  not if yes then return true else false.
            */
void dfs(vector<vector<int>>& rooms,vector<int>&visit,int node){
        
      
      
        
        visit[node]=1;
        
        for(auto it:rooms[node]){
            
            if(visit[it]==0){
               dfs(rooms,visit,it);
            }
        }
    
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        vector<int>visit(n,0);
        
     
               dfs(rooms,visit,0);
       
         for(int i=0;i<n;i++){
               cout<<visit[i]<<" ";
           }
     
           for(int i=0;i<n;i++){
              if(visit[i]==0) return false;
           }
        
        return true;
    }
};
