#include <cstdio>
#include <string>

using namespace std;

int LongestPalindrome(const string &s, int left, int right)
{
  if (left == right) return 1;
  else if (left + 1 == right && s[left] == s[right]) return 2;

  if (s[left] == s[right])
    return 2 + LongestPalindrome(s, left + 1, right - 1);
  else
    return max(LongestPalindrome(s, left + 1, right),
               LongestPalindrome(s, left + 1, right + 1));
}

int LongestPalindrome(const string &s)
{
  return LongestPalindrome(s, 0, s.size() - 1);
}

int main()
{
  string s("NEVERODDOREVEN");
  printf("Longest palindrome of %s has length = %d\n", s.c_str(),
         LongestPalindrome(s));

  return 0;
}
