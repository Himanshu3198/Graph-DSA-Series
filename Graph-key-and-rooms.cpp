// 841. Keys and Rooms

class Solution {
public:
    
void dfs(vector<vector<int>>& rooms,vector<int>&visit,int node){
        
      
        /*   the problem statement say that we have n rooms numbered as 0 t0 n-1  and we have visit the all 
             rooms for visting the room we need key to unlock the room and we found key of others room in      
             current room  so basically we can visit a room if have key this statement is repersent as graph 
             and its adjacent vertices in the form of key do simple dfs and later check if we have
             visited all rooms or  not if yes then return true else false.
            */
        
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
