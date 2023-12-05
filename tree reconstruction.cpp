#include <iostream>
using namespace std;

struct Node
{
  Node *right;
  Node *left;
  int info;
};

static int treeSize, counter = 0, preIndex = 0;
static int *postOrder;

void postOrderTraversal(Node *node)
{
  if (node == NULL)
  {
    return;
  }
  else
  {
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    postOrder[counter++] = node->info;
  }
}

int findIndex(int *array, int start, int end, int value)
{
  int index = start;
  while (index <= end)
  {
    if (array[index] == value)
    {
      return index;
    }
    index++;
  }
  return -1; // Value not found
}

Node *buildTree(int *inOrder, int *preOrder, int start, int end)
{
  if (start > end)
  {
    return NULL;
  }

  Node *node = new Node();
  node->right = NULL;
  node->left = NULL;
  node->info = preOrder[preIndex++];

  if (start == end)
  {
    return node;
  }

  int inIndex = findIndex(inOrder, start, end, node->info);

  node->left = buildTree(inOrder, preOrder, start, inIndex - 1);
  node->right = buildTree(inOrder, preOrder, inIndex + 1, end);

  return node;
}

int main()
{
  int numTestCases;
  cin >> numTestCases;

  while (numTestCases--)
  {
    int numNodes;
    cin >> numNodes;

    treeSize = numNodes;
    counter = 0;
    postOrder = new int[treeSize];

    int *inOrder = new int[numNodes];
    int *preOrder = new int[numNodes];

    for (int i = 0; i < numNodes; i++)
    {
      cin >> preOrder[i];
    }

    for (int j = 0; j < numNodes; j++)
    {
      cin >> inOrder[j];
    }

    Node *root = buildTree(inOrder, preOrder, 0, numNodes - 1);

    postOrderTraversal(root);
    root = NULL;

    for (int k = 0; k < numNodes; k++)
    {
      if (k >= (numNodes - 1))
      {
        cout << postOrder[k] << "\n";
      }
      else
      {
        cout << postOrder[k] << " ";
      }
    }

    preIndex = 0;
  }

  return 0;
}