#include <iostream>
#include <stack>
#include <string>
using namespace std;

class QueueUsingTwoStacks
{
private:
  stack<int> stack_enqueue;
  stack<int> stack_dequeue;

public:
  void enqueue(int item)
  {
    stack_enqueue.push(item);
  }

  int dequeue()
  {
    if (stack_enqueue.empty() && stack_dequeue.empty()){
      return -1;
    }
    if (stack_dequeue.empty())
    {
      while (!stack_enqueue.empty())
      {
        stack_dequeue.push(stack_enqueue.top());
        stack_enqueue.pop();
      }
    }
    int frontItem = stack_dequeue.top();
    stack_dequeue.pop();
    return frontItem;
  }

  int peek()
  {
    if (stack_enqueue.empty() && stack_dequeue.empty()){
      return -1;
    }
    if (stack_dequeue.empty())
    {
      while (!stack_enqueue.empty())
      {
        stack_dequeue.push(stack_enqueue.top());
        stack_enqueue.pop();
      }
    }
    return stack_dequeue.top();
  }

  void clear()
  {
    while (!stack_enqueue.empty())
    {
      stack_enqueue.pop();
    }
    while (!stack_dequeue.empty())
    {
      stack_dequeue.pop();
    }
  }
};

int main()
{

  QueueUsingTwoStacks queue;

  while (true)
  {
    int numOperations;

    if (!(cin >> numOperations))
    {
      break;
    }
    queue.clear();

    for (int i = 0; i < numOperations; i++)
    {
      string operation;
      cin >> operation;

      if (operation == "add")
      {
        int x;
        cin >> x;
        queue.enqueue(x);
      }

      else if (operation == "poll")
      {
        int popped = queue.dequeue();
        // if (popped != -1)
        //   {
        //       cout << popped << endl;
        //   }
      }

      else if (operation == "peek")
      {
        int result = queue.peek();
        if (result != -1)
        {
          cout << result << endl;
        }
      }
    }
  }

  return 0;
}

