#include <iostream>
#include <string>
#include <stack>
using namespace std;

class stack
{
private:
    long long int arr[100000];
    int top = -1;

public:
    stack()
    {
        for (int i = 0; i < 100000; i++)
        {
            arr[i] = 0;
        }
    }

    int Top()
    {
        if (!empty())
            return arr[top];
    }

    bool empty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    void push(int value)
    {
        top++;
        arr[top] = value;
    }

    int pop()
    {
        int pop_value = arr[top];
        arr[top] = 0;
        top--;
        return pop_value;
    }

    int size()
    {
        return (top + 1);
    }
};

int main()
{
    int T, N, top_pos, i, j, k;

    cin >> T;

    for (i = 0; i < T; i++)
    {
        stack X;
        long long int temp, X_max = 0, X_temp;
        cin >> N;
        long long int *input = new long long int[N];
        int j = 0;

        while (j < N)
        {
            cin >> input[j];
            j++;
        }

        for (k = 0; k < N;)
        {
            if (X.empty() == true || input[X.Top()] <= input[k])
            {
                X.push(k);
                k++;
            }

            else
            {
                top_pos = X.Top();
                temp = input[top_pos];
                X.pop();

                if (X.empty() == true)
                    X = temp * k;

                else
                    X = temp * (k - (X.Top()) - 1);

                if (X_temp > X_max)
                    X_max = X_temp;
            }
        }

        while (!X.empty())
        {
            top_pos = X.Top();
            temp = input[top_pos];
            X.pop();

            if (X.empty() == true)
                X_temp = temp * k;

            else
                X_temp = temp * (k - (X.Top()) - 1);

            if (X_temp > X_max)
                X_max = X_temp;
        }

        cout << X_max << endl;
    }

    return 0;
}
