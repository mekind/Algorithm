#include <iostream>

using namespace std;

int N;

void sol(int a, int b)
{
}

int main()
{
  cin >> N;

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
      sol(i, j);
    cout << "\n";
  }

  return 1;
}