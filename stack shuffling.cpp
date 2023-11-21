#include <iostream>
#include <stack>
using namespace std;

int main()
{

  int testcase;
  cin >> testcase;
  while (testcase--)
  {
    int *input;
    int num, d, size;
    cin >> size;
    input = new int[size];

    for (int i = 0; i < size; i++)
    {
      cin >> input[i];
    }
    cin >> num;

    while (num--)
    {
      int *arr = new int[size];
      stack<int> A, B, S;

      for (int i = 0; i < size; i++)
      {
        cin >> arr[i];
        A.push(input[i]);
      }

      int x = 0;
      while (!A.empty())
      {
        S.push(A.top());

        while (!S.empty() && S.top() == arr[x])
        {
          B.push(S.top());
          x++;
          S.pop();
        }
        A.pop();
      }
      
      if (S.empty())
        cout << "Aye" << endl;
      else
        cout << "Impossible" << endl;

      delete[] arr;
    }
    delete[] input;
  }
  return 0;
}
