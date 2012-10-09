#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define MAX_ROW 10
#define MAX_COL 10

int R, C;
char grid[MAX_ROW][MAX_COL];

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

// Label cell with intial label c1 as c2
// Return size of a component starting at (r, c)
int floodfill(int r, int c, char c1, char c2)
{
  if (r < 0 || r >= R || c < 0 || c >= C) return 0;
  if (grid[r][c] != c1) return 0;


  int ans = 1;
  grid[r][c] = c2;

  for (int d = 0; d < sizeof(dr) / sizeof(dr[0]); ++d)
    ans += floodfill(r + dr[d], c + dc[d], c1, c2);

  return ans;
}

int main()
{
  string input;
  cin >> R >> C;
  cin.ignore(1);

  for (int i = 0; i < R; ++i) {
    getline(cin, input);

    for (int j = 0; j < C; ++j) {
      grid[i][j] = input[j];
    }
  }

  int num_components = 0;

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (grid[i][j] == 'W') {
        printf("Component %d: ", ++num_components);
        printf("%d\n", floodfill(i, j, 'W', '.'));
      }
    }
  }

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      printf("%c", grid[i][j]);

      if (j < C - 1) putchar(' ');
      else putchar('\n');
    }
  }

  return 0;
}
