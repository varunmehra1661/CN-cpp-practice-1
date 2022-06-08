#include <bits/stdc++.h>
#include "classTreeNode.h"
using namespace std;

treeNode<int> *takeInputLL()
{
    // data for the root node
    int rootData;
    cout << "Root ka data :";
    cin >> rootData;

    // creating a tree node around it
    treeNode<int> *root = new treeNode<int>(rootData);

    // creating a queue to store the pending treenodes
    queue<treeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    // taking out the first node naming it as front
    // deleting the first node from our queue
    while (pendingNodes.size() != 0)
    {
        treeNode<int> *fr = pendingNodes.front();
        pendingNodes.pop();

        // creating children of the first node
        cout << "Enter the number of children of " << fr->data << " : ";
        int childnum;
        cin >> childnum;
        // cout << endl;
        for (int i = 0; i < childnum; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << fr->data << " : ";
            cin >> childData;
            // cout << endl;
            treeNode<int> *child = new treeNode<int>(childData);

            // linking root->children
            fr->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int height(treeNode<int> *root)
{
    int max = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int test = height(root->children[i]);
        if (max < test)
        {
            max = test;
        }
    }
    return max + 1;
}

int main()
{
    treeNode<int> *root = takeInputLL();
    cout << "Height of the tree :: " << height(root);
}