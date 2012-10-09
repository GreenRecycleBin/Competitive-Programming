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
typedef priority_queue<int> pqi;

mivi adj_list;
mii incoming_degree;
qi q;
pqi pq;

void topological_sort(int num_nodes)
{
  for (int i = 0; i < num_nodes; ++i) {
    if (incoming_degree.find(i) == incoming_degree.end()) pq.push(i);
  }

  while (!pq.empty()) {
    int u = pq.top(); pq.pop();
    printf("%d ", u);

    for (int i = 0; i < adj_list[u].size(); ++i) {
      if (--incoming_degree[adj_list[u][i]] == 0)
        pq.push(adj_list[u][i]);
    }

    adj_list[u].clear();
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
      ++incoming_degree[v];
    }

    topological_sort(num_nodes);
    putchar('\n');
  }

  return 0;
}
