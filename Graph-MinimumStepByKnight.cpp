// Steps by Knight
// Expected Time Complexity: O(N2).
// Expected Auxiliary Space: O(N2).


/* Author 
     himanshu3198
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

     
    bool valid(int x, int y, int n){
    if(x>=0 && x<n && y>=0 && y<n)return true;
    else return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    
	      int x1=KnightPos[0];
	      int y1=KnightPos[1];
	      
	      int x2=TargetPos[0];
	      int y2=TargetPos[1];
	    
          int xcord[] = {2,1,-1,-2};
    int ycord[] = {1,2,2,1};
    
    vector< vector<int> > board(N, vector<int>(N, -1) );
    queue< pair<int,int> >  q;
    
    q.push(make_pair(x1-1,y1-1));
    board[x1-1][y1-1] ++;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x==(x2-1) && y == (y2-1) ){
            return board[x][y];
        }
        
        for(int i=0; i<4; i++){
            int xnew = x + xcord[i];
            int ynew = y + ycord[i];
            if(valid(xnew, ynew, N) && board[xnew][ynew]==-1){
                board[xnew][ynew] = board[x][y] + 1;
                q.push(make_pair(xnew, ynew));
            }
            
            ynew = y - ycord[i];
            if(valid(xnew, ynew,N) && board[xnew][ynew]==-1){
                board[xnew][ynew] = board[x][y] + 1;
                q.push(make_pair(xnew, ynew));
            }
        }
        
    }
    return -1;
	    
	    
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  
