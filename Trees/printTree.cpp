#include <bits/stdc++.h>
#include "classTreeNode.h"
using namespace std;

void printTree(treeNode<int> *root)
{
    // edge case to handle NULL vector
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    treeNode<int> *root = new treeNode<int>(10);
    treeNode<int> *node1 = new treeNode<int>(20);
    treeNode<int> *node2 = new treeNode<int>(30);

    // linking root->children
    root->children.push_back(node1);
    root->children.push_back(node2);

    // print function call
    printTree(root);
}