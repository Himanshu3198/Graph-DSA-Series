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

     
       int dx[8]={2,2,-2,-2,1,1,-1,-1};
       int dy[8]={1,-1,1,-1,2,-2,2,-2};
       bool isValid(int i,int j,int n,int m){
           if(i>=0 and j>=0 and i<n and j<m){
               return true;
           }
           return false;
       }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	      int level=0;
	       queue<pair<int,int>>q;
	       vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	       q.push({KnightPos[0],KnightPos[1]});
	        vis[KnightPos[0]][KnightPos[1]]=1;
	       while(!q.empty()){
	           
	           int size=q.size();
	           while(size--){
	                int i=q.front().first;
	                int j=q.front().second;
	                    q.pop();
	               for(int k=0;k<8;k++){
	                    int x=i+dx[k];
	                    int y=j+dy[k];
	                    if(x==TargetPos[0] and  y==TargetPos[1]) return level+1;
	                    if(isValid(x,y,N,N)==1){
	                        if(vis[x][y]==0){
	                             vis[x][y]=1;
	                            q.push({x,y});
	                        }
	                       
	                    }
	               }
	               
	           }
	               level++;
	       }
	       
	       return 0;
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
