#include <bits/stdc++.h>
using namespace std;

struct TreapNode
{
    // Node Properties
    int key, priority;
    TreapNode *left, *right;

    TreapNode() {}

    // Constructor
    TreapNode(int key)
    {
        this->key = key;
        this->priority = rand();
        this->left = NULL;
        this->right = NULL;
    }
};

// Function used to search for a key in the Treap
TreapNode *search(TreapNode *root, int key)
{
    // If the key is in the root, return the root
    if (!root or root->key == key)
    {
        return root;
    }

    // Search the right sub tree if the key of the root node is less than the key that is being searched
    if (root->key < key)
    {
        return search(root->right, key);
    }

    // Search the left sub tree if the key of the root node is less than the key that is being searched
    if (root->key > key)
    {
        return search(root->left, key);
    }
}
int main(void)
{
    srand(time(NULL));

    //                           Treap Structure
    //
    //                            3
    //                          /   \
    //                        -4     7
    //                        / \   / \
    //                      -9   0  5  8
    //                            \     \
    //                             1     9

    // Create Treap Nodes
    TreapNode rootNode(3);
    TreapNode node1(-4);
    TreapNode node2(7);
    TreapNode node3(-9);
    TreapNode node4(0);
    TreapNode node5(5);
    TreapNode node6(8);
    TreapNode node7(1);
    TreapNode node8(9);

    // Create child nodes for rootNode
    rootNode.left = &node1;  // Parent(3), Leftchild(-4)
    rootNode.right = &node2; // Parent(3), Rightchild(7)

    // Create child nodes for node1
    node1.left = &node3;  // Parent(-4), Leftchild(-9)
    node1.right = &node4; // Parent(-4), Leftchild(0)

    // Create child nodes for node2
    node2.left = &node5;  // Parent(7), Leftchild(5)
    node2.right = &node6; // Parent(7), Leftchild(8)

    // Create child nodes for node4
    node4.right = &node7; // Parent(0), Rightchild(1)

    // Create child nodes for node6
    node6.right = &node8; // Parent(8), Rightchild(9)

    if (search(&rootNode, 2) != NULL)
    {
        cout << "Key found";
    }
    else
    {
        cout << "Key not found";
    }
}
