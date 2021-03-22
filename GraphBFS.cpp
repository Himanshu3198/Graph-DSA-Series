// simplest bfs implementation in cpp
// time complexity O(E+V)
#include <bits./stdc++.h>
#define v 4
using namespace std;

vector<int> adj[v];
void addEdge(vector<int> adj[], int s, int d)
{
  adj[s].push_back(d);
}

void bfs(int x)
{
  vector<bool> visit = {false};

  queue<int> q;
  q.push(x);
  visit[x] = true;

  while (!q.empty())
  {
    int a = q.front();

    cout << a << " ";
    q.pop();
    for (auto j = adj[a].begin(); j != adj[a].end(); j++)
    {
      if (!visit[*j])
      {
        visit[*j] = true;
        q.push(*j);
      }
    }
  }
}

int main()
{

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 0);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 3);
  bfs(2);
}
// expected output 2 0 3 1
