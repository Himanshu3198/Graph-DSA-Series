class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(); 
        queue<pair<int, int>> q; 
        vector<vector<bool>> seen(n, vector<bool>(1 << n, false)); 
        
        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i);
            seen[i][1 << i] = true;  
        }
        
        int ans = 0; 
        while (q.size()) {
            for (int k = q.size(); k; --k) {
                auto [i, mask] = q.front(); q.pop(); 
                if (mask == (1 << n) - 1) return ans;  
                for (auto& ii : graph[i]) 
                    if (!seen[ii][mask | (1 << ii)]) {
                        q.emplace(ii, mask | (1 << ii));
                        seen[ii][mask | (1 << ii)] = true; 
                    }
            }
            ++ans; 
        }
        return ans; 
    }
};
