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

void dfs(int u)
{
  dfs_num[u] = DFS_BLACK;
  printf("%d ", u);

  for (int i = 0; i < (int)adj_list[u].size(); ++i) {
    ii v = adj_list[u][i];

    if (dfs_num[v.first] == DFS_WHITE) dfs(v.first);
  }
}

int main()
{
  int num_nodes, num_edges;
  scanf("%d %d", &num_nodes, &num_edges);

  if (num_nodes > 0 && num_edges > 0) {
    dfs_num.assign(num_nodes, 0);

    for (int i = 0; i < num_edges; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);

      adj_list[u].push_back(ii(v, 0));
      adj_list[v].push_back(ii(u, 0));
    }

    dfs(0);
    putchar('\n');
    dfs(5);
    putchar('\n');
    dfs(7);
    putchar('\n');
  }

  return 0;
}
