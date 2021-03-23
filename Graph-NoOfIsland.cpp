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
}






void DFSRec(vector<int> A[], int N, int M, int i, int j)
{
    A[i][j] = 2;
    
    //Right Side
    if(j+1 < M)
    {
        if(A[i][j+1] == 1)
        {
            DFSRec(A, N, M, i, j+1);
        }
    }
    
    //Left Side
    if(j-1 >= 0)
    {
        if(A[i][j-1] == 1)
        {
            DFSRec(A, N, M, i, j-1);
        }
    }
    
    //Up side
    if(i-1 >= 0)
    {
        if(A[i-1][j] == 1)
        {
            DFSRec(A, N, M, i-1, j);
        }
    }
    
    //Down side
    if(i+1 < N)
    {
        if(A[i+1][j] == 1)
        {
            DFSRec(A, N, M, i+1, j);
        }
    }
    
    //South East
    if(i+1 < N && j+1 < M)
    {
        if(A[i+1][j+1] == 1)
        {
            DFSRec(A, N, M, i+1, j+1);
        }
    }
    
    //South West
    if(i+1 < N && j-1 >= 0)
    {
        if(A[i+1][j-1] == 1)
        {
            DFSRec(A, N, M, i+1, j-1);
        }
    }
    
    //North West
    if(i-1 >= 0 && j-1 >= 0)
    {
        if(A[i-1][j-1] == 1)
        {
            DFSRec(A, N, M, i-1, j-1);
        }
    }
    
    //North East
    if(i-1 >= 0 && j+1 < M)
    {
        if(A[i-1][j+1] == 1)
        {
            DFSRec(A, N, M, i-1, j+1);
        }
    }
}

int findIslands(vector<int> A[], int N, int M) 
{
    int count = 0;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(A[i][j] == 1)
            {
                DFSRec(A, N, M, i, j);
                count++;
            }
        }
    }
    
    return count;
}
