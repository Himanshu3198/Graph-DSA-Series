class node
{

    public:
        string s;
    int t;
    node(string _s, int _t)
    {
        s = _s;
        t = _t;
    }
};
class Solution
{
    public:
        int minMutation(string start, string end, vector<string> &bank)
        {

            set<string> st = { bank.begin(),
                bank.end()
            };
            for (auto i: st) cout << i << " ";
            queue<node> q;
            q.push(node(start, 0));
            vector<char> v = { 'A',
                'C',
                'G',
                'T' };

            while (!q.empty())
            {

                int size = q.size();
                while (size--)
                {
                    string curr = q.front().s;
                    int t = q.front().t;
                    q.pop();
                    if (curr == end) return t;
                    for (int i = 0; i < 8; i++)
                    {
                        char temp = curr[i];
                        for (int j = 0; j < 4; j++)
                        {

                            curr[i] = v[j];
                            if (st.count(curr))
                            {
                                st.erase(curr);
                                q.push(node(curr, t + 1));
                            }
                            curr[i] = temp;
                        }
                    }
                }
            }
            return -1;
        }
};
