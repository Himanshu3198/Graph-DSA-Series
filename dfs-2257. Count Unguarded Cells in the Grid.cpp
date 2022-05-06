
/* Brute force
   Time Complexity O(n*m)
   Space Complexity O(n*m)
*/
static const auto _____ = []()
{
    // fast IO code : this I understand
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution
{
public:
    void dfs(vector<vector<int>> &mat, int x, int y, int n, int m)
    {

        for (int i = x - 1; i >= 0; i--)
        {
            if (mat[i][y] == 0 or mat[i][y] == 1)
                break;

            mat[i][y] = 3;
        }
        for (int i = x + 1; i < n; i++)
        {
            if (mat[i][y] == 0 or mat[i][y] == 1)
                break;

            mat[i][y] = 3;
        }

        for (int j = y - 1; j >= 0; j--)
        {
            if (mat[x][j] == 0 or mat[x][j] == 1)
                break;

            mat[x][j] = 3;
        }
        for (int j = y + 1; j < m; j++)
        {
            if (mat[x][j] == 0 or mat[x][j] == 1)
                break;

            mat[x][j] = 3;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {

        vector<vector<int>> mat(m, vector<int>(n, 2));
        for (int i = 0; i < walls.size(); i++)
        {

            int x = walls[i][0];
            int y = walls[i][1];
            mat[x][y] = 0;
        }

        for (int i = 0; i < guards.size(); i++)
        {
            int x = guards[i][0];
            int y = guards[i][1];
            mat[x][y] = 1;
        }

        for (auto it : guards)
        {

            int x = it[0];
            int y = it[1];
            dfs(mat, x, y, m, n);
        }

        int res = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
                res += (mat[i][j] == 2);
            }
            cout << "\n";
        }
        return res;
    }
};
