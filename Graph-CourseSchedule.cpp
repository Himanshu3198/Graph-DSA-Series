#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> &adj, vector<int> &vis, int curr)
{

      if(vis[curr]==2){
              return true;
          }
          
          vis[curr]=2;
          
          for(int j=0;j<adj[curr].size();j++){
              
              if(vis[adj[curr][j]]==0 or vis[adj[curr][j]]==2 ){
                  if(isCycle(adj,vis,adj[curr][j])){
                      return true;
                  }
              }
          }
          
          vis[curr]=1;
          return false;
}
bool solve(vector<vector<int>> &nums, int n)
{

        vector<vector<int>>adj(n);
        
        for(int i=0;i<nums.size();i++){
            adj[nums[i][0]].push_back(nums[i][1]);
        }
        
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++){
            
            if(vis[i]==0){
                if(isCycle(adj,vis,i)){
                    return false;
                }
            }
        }
        return true;
}

int main()
{

    vector<vector<int>> nums = {{1,0},{0,1}};

    cout << solve(nums, nums.size());
}