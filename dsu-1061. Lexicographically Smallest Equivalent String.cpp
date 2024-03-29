class Solution
{
    public:
    vector<int> parent, rank;
    int find(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void union_op(int x, int y)
    {
        if (x == y) return;
        if (rank[x] > rank[y])
        {
            parent[y] = x;
            rank[x] += 1;
        }
        else
        {
            parent[x] = y;
            rank[y] += 1;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {

        int n = 26;
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < 26; i++)
            parent[i] = i;
        int sz = s1.size();
        for (int i = 0; i < sz; i++)
        {
            union_op(find(s1[i] - 'a'), find(s2[i] - 'a'));
        }
        string res = "";
        for (int i = 0; i < baseStr.size(); i++)
        {

            int x = find(baseStr[i] - 'a');
            char ans = 'z';
            for (int i = 0; i < 26; i++)
            {
                if (parent[i] == x)
                {
                    char c = char(i + 'a');
                    ans = min(ans, c);
                }
            }
            res += ans;
        }
        return res;
    }
};
