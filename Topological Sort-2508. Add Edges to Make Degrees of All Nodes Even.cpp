class Solution
{
    public:
        bool isPossible(int n, vector<vector < int>> &edges)
        {
            set<pair<int, int>> seenEdge;
            vector<int> indge(n + 1, 0);
            for (auto &it: edges)
            {
                int x = it[0];
                int y = it[1];
                if (x > y) swap(x, y);
                seenEdge.insert({ x,
                    y });
                indge[x]++;
                indge[y]++;
            }
            vector<int> oddEdge;
            for (int i = 1; i <= n; i++)
            {
               	// cout<<i<<" "<<indge[i]<<"\n";
                if (oddEdge.size() > 4) return false;
                if (indge[i] % 2 == 1) oddEdge.push_back(i);
            }
           	// for(auto it:oddEdge) cout<<it<<" ";
            int even = n - oddEdge.size(), k = 2;
            if (oddEdge.size() == 0) return true;
            if (oddEdge.size() % 2 == 1) return false;
            if (oddEdge.size() == 2)
            {

                int x = oddEdge[0];
                int y = oddEdge[1];
                if (x > y) swap(x, y);
                if (!seenEdge.count({ x,
                        y })) return true;
                for (int i = 1; i <= n; i++)
                {
                    if (i == x || i == y) continue;
                    int z = i, temp_z = i, temp_x = x, temp_y = y;
                    if (temp_x > temp_z) swap(temp_x, temp_z);
                    if (temp_y > z) swap(temp_y, z);
                    if (!seenEdge.count({ temp_x,
                            temp_z }) && !seenEdge.count({ temp_y,
                            z })) return true;
                }
                return false;
            }
            else if (oddEdge.size() == 4)
            {
                sort(oddEdge.begin(), oddEdge.end());
                int a = oddEdge[0];
                int b = oddEdge[1];
                int c = oddEdge[2];
                int d = oddEdge[3];

                if (!seenEdge.count({ a,
                        b }) && !seenEdge.count({ c,
                        d })) return true;
                else if (!seenEdge.count({ a,
                        c }) && !seenEdge.count({ b,
                        d })) return true;
                else if (!seenEdge.count({ b,
                        c }) && !seenEdge.count({ a,
                        d })) return true;
                return false;
            }
            return false;
        }
};
