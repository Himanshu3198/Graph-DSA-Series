class Solution
{
    public:

        bool isValid(int &i, int &j, int &n, int &m)
        {
            if (i >= 0 && i < n && j >= 0 && j < m) return true;
            return false;
        }
    void dfs(vector<vector < int>> &height, vector< vector< int>> &ocean, int i, int j, int last, int &n, int &m)
    {
        if (!isValid(i, j, n, m)) return;
        if (ocean[i][j] == 1) return;
        if (last > height[i][j]) return;
        ocean[i][j] = 1;

        dfs(height, ocean, i, j + 1, height[i][j], n, m);
        dfs(height, ocean, i - 1, j, height[i][j], n, m);
        dfs(height, ocean, i + 1, j, height[i][j], n, m);
        dfs(height, ocean, i, j - 1, height[i][j], n, m);
        return;
    }

    vector<vector < int>> pacificAtlantic(vector<vector < int>> &heights)
    {

        int n = heights.size(), m = heights[0].size();
        vector<vector < int>> pacific(n, vector<int> (m, 0)), atlantic(n, vector<int> (m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (i == 0 || j == 0)
                {
                    dfs(heights, pacific, i, j, heights[i][j], n, m);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == (n - 1) || j == (m - 1))
                {
                    dfs(heights, atlantic, i, j, heights[i][j], n, m);
                }
            }
        }

        vector<vector < int>> res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) res.push_back({ i,
                    j });
            }
        }
        return res;
    }
};
