// Segment tree implementation to solve Range Min Query (RMQ) questions
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

void st_build(vi &st, const vi &a, int vertex, int left, int right)
{
  if (left == right) {
    st[vertex] = left;
  }
  else {
    int vertex_left = 2 * vertex, vertex_right = 2 * vertex + 1;
    st_build(st, a, vertex_left, 0, (left + right) / 2);
    st_build(st, a, vertex_right, (left + right) / 2 + 1, right);

    int index_min_left = st[vertex_left], index_min_right = st[vertex_right];
    int min_left = a[index_min_left], min_right = a[index_min_right];
    st[vertex] = min_left < min_right ? index_min_left : index_min_right;
  }
}

void st_create(vi &st, const vi &a)
{
  int size = (int)(2 * pow(2.0, floor((log((double)a.size()) / log(2.0) + 1))));
  st.assign(size, 0);
  st_build(st, a, 1, 0, (int)a.size() - 1);
}

// Return index of the minimum from left to right in vector a
int st_rmq(vi &st, const vi &a, int vertex, int left, int right, int i, int j)
{
  if (i > right || j < left) return -1; // current segment outside query range
  if (left >= i && right <= j) return st[vertex];

  int index_min_left =
        st_rmq(st, a, 2 * vertex, left, (left + right) / 2, i, j),
      index_min_right =
        st_rmq(st, a, 2 * vertex + 1, (left + right) / 2 + 1, right, i, j);

  if (index_min_left == -1) return index_min_right;
  if (index_min_right == -1) return index_min_left;

  return (a[index_min_left] <= a[index_min_right] ? index_min_left : index_min_right);
}

// Overload for shorter argument list
int st_rmq(vi &st, const vi &a, int i, int j)
{
  return st_rmq(st, a, 1, 0, (int)a.size() - 1, i, j);
}

int main()
{
  int arr[7] = {8, 7, 3, 9, 5, 1, 10};
  vi a(arr, arr + 7), st;
  st_create(st, a);

  cout << "RMQ(1, 3) = " << st_rmq(st, a, 1, 3) << endl;
  cout << "RMQ(4, 6) = " << st_rmq(st, a, 4, 6) << endl;

  return 0;
}
