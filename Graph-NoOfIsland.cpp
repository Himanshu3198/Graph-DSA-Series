#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

 


  void mark_visited(vector<vector<char>>&grid,int i,int j,int rows,int cols){
         
         if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j]!='1'){
             return;
         }
         else{
             grid[i][j]='2';
             
              mark_visited(grid,i+1,j,rows,cols);
              mark_visited(grid,i,j+1,rows,cols);
              mark_visited(grid,i-1,j,rows,cols);
              mark_visited(grid,i,j-1,rows,cols);
              mark_visited(grid,i+1,j+1,rows,cols);
              mark_visited(grid,i-1,j-1,rows,cols);
              mark_visited(grid,i+1,j-1,rows,cols);
              mark_visited(grid,i-1,j+1,rows,cols);
               
              
             
         }
         
     }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        
              int rows=grid.size();
        if(rows==0){
            return 0 ;
        }
        int cols=grid[0].size();
        int count_island=0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                      
                    mark_visited(grid,i,j,rows,cols);
                    count_island++; 
                }
            }
        }
        return count_island;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends