// Given the position of one queen at (a, b), write a program that will
// determine all posible placements of all other queens on the board
// such that no two queens attack each other. Display the output in
// lexicographical order.

#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int rows[9], n, a, b, line_counter;

bool CanPlace(int col, int row)
{
  for (int prev = 1; prev < col; ++prev) {
    if (rows[prev] == row || abs(rows[prev] - row) == abs(prev - col))
      return false;
  }

  return true;
}

void Backtrack(int col)
{
  for (int row = 1; row <= 8; ++row) {
    if (CanPlace(col, row)) {
      if (col == b && row != a) continue;

      rows[col] = row;

      if (col == 8 && rows[b] == a) { // Found one solution
        printf("%2d      %d", ++line_counter, rows[1]);

        for (int i = 2; i <= 8; ++i) printf(" %d", rows[i]);

        putchar('\n');
      }
      else Backtrack(col + 1);
    }
  }
}

int main()
{
  scanf("%d", &n);

  while (n--) {
    scanf("%d %d", &a, &b);
    memset(rows, 0, sizeof rows);
    line_counter = 0;

    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    Backtrack(1);

    if (n > 0) putchar('\n');
  }

  return 0;
}
