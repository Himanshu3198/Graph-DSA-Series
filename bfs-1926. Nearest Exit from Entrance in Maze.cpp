class Maze
{
    public:
        int row;
    int col;
    int step;
    Maze(int r, int c, int s)
    {
        row = r;
        col = c;
        step = s;
    }
};

class Solution
{

    public:
        bool reached(int r, int c, int n, int m)
        {
            if (r < 0 || c < 0 || r >= n || c >= m) return true;
            return false;
        }
    int nearestExit(vector<vector < char>> &maze, vector< int > &entrance)
    {

        int dx[4] = { -1,
            1,
            0,
            0
        };
        int dy[4] = { 0,
            0,
            -1,
            1
        };
        int n = maze.size(), m = maze[0].size();

        queue<Maze> q;
        set<vector<int>>st;
        for(int k=0;k<4;k++){
            
            if(reached(entrance[0]+dx[k],entrance[1]+dy[k],n,m)){
                st.insert({entrance[0]+dx[k],entrance[1]+dy[k]});
            }
        }
        q.push(Maze(entrance[0], entrance[1], 0));
        // maze[entrance[0]][entrance[1]]='*';
        long long int ans=LONG_MAX;
        while (!q.empty())
        {

            int size = q.size();
            
            while (size--)
            {

                int r = q.front().row;
                int c = q.front().col;
                int s = q.front().step;
                q.pop();
                if (reached(r, c, n, m)){
                      return s-1;                  
                }
                if (maze[r][c] == '+') continue;
                
                for (int k = 0; k < 4; k++)
                {

                    int xx = dx[k] + r;
                    int yy = dy[k] + c;
                    // if (xx==entrance[0] && yy==entrance[1]) continue;
                    if(st.count({xx,yy})) continue;
                    
                    q.push(Maze(xx, yy, s + 1));
                }
                maze[r][c] = '+';
            }
        }
        return ans;
    }
};
