#include <iostream>
#include <vector>
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

// Display the depth of every node
void displayDepths(Node* root, int depth)
{
    if (root == NULL)
        return;

    cout << "Node " << root->data
         << " -> Depth: " << depth << endl;

    displayDepths(root->left, depth + 1);
    displayDepths(root->right, depth + 1);
}

// Find the node and store its path
bool findPath(Node* root, int key, vector<int>& path)
{
    if (root == NULL)
        return false;

    path.push_back(root->data);

    if (root->data == key)
        return true;

    if (key < root->data)
    {
        if (findPath(root->left, key, path))
            return true;
    }
    else
    {
        if (findPath(root->right, key, path))
            return true;
    }

    path.pop_back();
    return false;
}

int main()
{
    Node* root = NULL;
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of nodes must be positive.";
        return 0;
    }

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nDepth of every node:\n";
    displayDepths(root, 0);

    cout << "\nEnter node to find: ";
    cin >> key;

    vector<int> path;

    if (findPath(root, key, path))
    {
        cout << "Path from root to node: ";

        for (int i = 0; i < (int)path.size(); i++)
        {
            cout << path[i];

            if (i < (int)path.size() - 1)
                cout << " -> ";
        }

        cout << "\nDepth of node " << key
             << " is: " << path.size() - 1 << endl;
    }
    else
    {
        cout << "Node not found in the tree." << endl;
    }

    return 0;
}
