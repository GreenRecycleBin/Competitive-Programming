#include <cstdio>
#include <string>

using namespace std;

// Return the size of the longest palindrom subsequence of a string
// by deleting some of its characters
int LongestPalindromeSubsequence(const string &s, int left, int right)
{
  if (left == right) {
    return 1;
  }
  else if (left + 1 == right) {
    if (s[left] == s[right]) return 2;

    return 1;
  }
  else if (s[left] == s[right]) {
    return 2 + LongestPalindromeSubsequence(s, left + 1, right - 1);
  }
  else {
    return max(LongestPalindromeSubsequence(s, left, right - 1),
        LongestPalindromeSubsequence(s, left + 1, right));
  }
}

int LongestPalindromeSubsequence(const string &s)
{
  return LongestPalindromeSubsequence(s, 0, s.size() - 1);
}

int main()
{
  string s("abeeddddeabe");
  printf("Longest palindrome subsequence of %s has length = %d\n", s.c_str(),
         LongestPalindromeSubsequence(s));

  return 0;
}
