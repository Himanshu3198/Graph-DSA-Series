


// 909. Snakes and Ladders
class Solution {
public:

    
     pair<int,int> findCoordinate(int curr,int n){
        int row = n-(curr-1)/n-1;
        int col = (curr-1)%n;
        if(row%2 == n%2)
            return {row,n-1-col};
        else
            return {row,col};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
          int n=board.size();
        
        vector<vector<bool>> vis(n,vector<bool>(n));
        
 
        
        queue<int> q;
        q.push(1);
        vis[n-1][0]=true;
        int step=0;
        
        while(!q.empty()){
            
            
            int qsize=q.size();
            
            for(int it=0;it<qsize;it++){
                 
                int x=q.front();
                q.pop();
                
                if(x==n*n){
                    return step;
                }
                for(int k=1;k<=6;k++){
                    
                    if(x+k>n*n){
                        break;
                    }
                    
                    pair<int,int> pos=findCoordinate(x+k,n);
                    
                     int row=pos.first;
                    int col=pos.second;
                    
                    
                      if(vis[row][col]==true){
                          continue;
                      }
                          vis[row][col]=true;
                        if(board[row][col]==-1){
                           
                           q.push(k+x);
                       }
                    else{
                        q.push(board[row][col]);
                    }
                }
            }
            step++;
            
        }
        
        
         return -1;
        
    }
};
