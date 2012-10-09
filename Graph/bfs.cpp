#include <map>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

#define DFS_WHITE 0
#define DFS_BLACK 1

typedef vector<int> vi;
typedef map<int, vi> mivi;
typedef map<int, int> mii;
typedef queue<int> qi;

mivi adj_list;
mii dist;
qi q;

// Perform breadth first traverse and calculate distance from root at the same time
void bfs(int s)
{
  q = qi();
  dist.clear();
  q.push(s);
  dist[s] = 0;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    printf("%d ", u);

    for (int i = 0; i < adj_list[u].size(); ++i) {
      int v = adj_list[u][i];

      if (dist.find(v) == dist.end()) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

int main()
{
  int num_nodes, num_edges;
  scanf("%d %d", &num_nodes, &num_edges);

  if (num_nodes > 0 && num_edges > 0) {
    for (int i = 0; i < num_edges; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);

      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
    }

    bfs(35);
    putchar('\n');

    for (mii::iterator it = dist.begin(); it != dist.end(); ++it) {
      printf("Distance from %d to %d: %d\n", 35, it->first, it->second);
    }
  }

  return 0;
}
