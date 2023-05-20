class Solution
{
    public:
        vector<int> findSmallestSetOfVertices(int n, vector<vector < int>> &edges)
        {

            unordered_map<int, vector < int>> graph;
            for (auto v: edges)
                graph[v[0]].push_back(v[1]);
            vector<int> indeg(n, 0);
            for (int i = 0; i < n; i++)
            {

                for (auto it: graph[i])
                {
                    indeg[it]++;
                }
            }
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                // cout << indeg[i] << " ";
                if (indeg[i] == 0) ans.push_back(i);
            }

            return ans;
        }
};
