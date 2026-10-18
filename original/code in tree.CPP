#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

// Insert a node into the BST
Node* insert(Node* root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Calculate the depth of a specified node
int findDepth(Node* root, int key, int depth)
{
    if (root == NULL)
        return -1;

    if (root->data == key)
        return depth;

    if (key < root->data)
        return findDepth(root->left, key, depth + 1);

    return findDepth(root->right, key, depth + 1);
}

int main()
{
    Node* root = NULL;
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Enter node to find depth: ";
    cin >> key;

    int depth = findDepth(root, key, 0);

    if (depth == -1)
        cout << "Node not found in the tree.";
    else
        cout << "Depth of node " << key
             << " is: " << depth;

    return 0;
}
