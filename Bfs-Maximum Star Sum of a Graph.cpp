class Solution
{
    public:
        int maxStarSum(vector<int> &vals, vector<vector< int>> &edges, int k)
        {

            int n = vals.size();
           	// vector < int>ans(n,0);
            int res = INT_MIN;
            if (n == 1)
            {
                return vals[0];
            }
            unordered_map<int, vector < int>> mp;
            for (auto it: edges)
            {
                if (vals[it[1]] > 0)
                    mp[it[0]].push_back(vals[it[1]]);
                if (vals[it[0]] > 0)
                    mp[it[1]].push_back(vals[it[0]]);
            }
            for (auto it: mp)
            {

                priority_queue<int, vector < int>, greater < int>> pq;
                for (auto v: it.second)
                {

                    pq.push(v);
                    if (pq.size() > k)
                    {
                        pq.pop();
                    }
                }
                int currAns = vals[it.first];

                while (!pq.empty())
                {

                    currAns += pq.top();
                    pq.pop();
                }
                int cur = vals[it.first];
                currAns = max(currAns, cur);
                res = max(res, currAns);
            }
            for (auto it: vals)
            {
                res = max(res, it);
            }

            return res;
        }
};
