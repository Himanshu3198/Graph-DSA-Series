// surrounded region using dfs/flood fill algorithm

class Solution {
public:
    
    // dfs for all possible for direction 
    void dfs(vector<vector<char>>& board,int i,int j,int row,int col){
        
        if(i<0 or i>=row or j<0 or j>=col or board[i][j]!='O'){
            return;
        }
        board[i][j]='H';
        
        dfs(board,i-1,j,row,col);
        dfs(board,i+1,j,row,col);
        dfs(board,i,j-1,row,col);
        dfs(board,i,j+1,row,col);
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        
        // checking for first and last row
        for(int i=0;i<col;i++){
            
            if(board[0][i]=='O'){
               dfs(board,0,i,row,col);
            }
             if(board[row-1][i]=='O'){
                 dfs(board,row-1,i,row,col);
            }
            
            
        }
        
          

        
          // checking for first and last col
        for(int i=0;i<row;i++){
            
            if(board[i][0]=='O'){
             dfs(board,i,0,row,col);
            }
              if(board[i][col-1]=='O'){
                  dfs(board,i,col-1,row,col);
            }
            
        }
        
    
        
        
        for(int i=0;i<row;i++){
            
            for(int j=0;j<col;j++){
                
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                
                if(board[i][j]=='H'){
                    board[i][j]='O';
                }
            }
        }
        
        
        
        
    }
};
