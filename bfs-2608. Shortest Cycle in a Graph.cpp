class Solution {
public:

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        
      int ans = INT_MAX;
    vector<vector<int>>graph(n);
         for(auto &it:edges){
             graph[it[0]].push_back(it[1]);
             graph[it[1]].push_back(it[0]);
         }

    for (int i = 0; i < n; i++) {
 
        vector<int> dist(n,INT_MAX);
 
        vector<int> parent(n, -1);
 
        dist[i] = 0;
        queue<int> q;
 
        q.push(i);
 
        while (!q.empty()) {
 
            int curr = q.front();
            q.pop();
 
            for (int ngbr : graph[curr]) {
 
                if (dist[ngbr] == INT_MAX) {
 
                    dist[ngbr] = 1 + dist[curr];
 
                    parent[ngbr] = curr;
 
                    q.push(ngbr);
                }
 
                else if (parent[curr] != ngbr and parent[ngbr] != curr)
                    ans = min(ans, dist[curr] + dist[ngbr] + 1);
            }
        }
    }
 
    return ans==INT_MAX?-1:ans;
                                      
  }
};
