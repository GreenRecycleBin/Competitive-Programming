#include <map>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define DFS_WHITE 0
#define DFS_BLACK 1

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, vii> mivii;

vi dfs_num;
mivii adj_list;
vi topological_vector;

// Topological sort
void topological_sort(int u)
{
  dfs_num[u] = DFS_BLACK;

  for (int i = 0; i < (int)adj_list[u].size(); ++i) {
    ii v = adj_list[u][i];

    if (dfs_num[v.first] == DFS_WHITE) topological_sort(v.first);
  }

  topological_vector.push_back(u);
}

int main()
{
  int num_nodes, num_edges;
  scanf("%d %d", &num_nodes, &num_edges);

  if (num_nodes > 0 && num_edges > 0) {
    dfs_num.assign(num_nodes, 0);
    topological_vector.clear();

    for (int i = 0; i < num_edges; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);

      adj_list[u].push_back(ii(v, 0));
    }

    for (int i = 0; i < adj_list.size(); ++i) {
      if (dfs_num[i] == DFS_WHITE) topological_sort(i);
    }

    for (int i = topological_vector.size() - 1; i >= 0; --i) {
      printf("%d", topological_vector[i]);

      if (i > 0) putchar(' ');
      else putchar('\n');
    }
  }

  return 0;
}
