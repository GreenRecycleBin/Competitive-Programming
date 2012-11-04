#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int LongestCommonSubsequence(const string &a, const string &b)
{
  int matrix[a.size() + 1][b.size() + 1];

  for (int i = 0; i <= a.size(); ++i) matrix[i][0] = 0;
  for (int i = 0; i <= b.size(); ++i) matrix[0][i] = 0;

  for (int i = 1; i <= a.size(); ++i) {
    for (int j = 1; j <= b.size(); ++j) {
      if (a[i - 1] == b[j - 1]) matrix[i][j] = matrix[i - 1][j - 1] + 1;
      else matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j]);
    }
  }

  return matrix[a.size()][b.size()];
}

int main()
{
  string a("ACAATCC"), b("AGCATGC");

  printf("Longest common subsequence = %d\n", LongestCommonSubsequence(a, b));

  return 0;
}
