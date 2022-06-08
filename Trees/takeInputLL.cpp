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

void printTreeLL(treeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<treeNode<int> *> pendingQ;
    pendingQ.push(root);
    while (pendingQ.size() != 0)
    {
        treeNode<int> *front = pendingQ.front();
        cout << front->data << ":";
        pendingQ.pop();
        for (int i = 0; i < root->children.size(); i++)
        {
            pendingQ.push(root->children[i]);

            if (root->children.size() - 1 != i)
            {
                cout << root->children[i]->data << ",";
            }
            else
            {
                cout << root->children[i]->data;
            }
        }
        root = pendingQ.front();
        cout << endl;
    }
}

int main()
{
    treeNode<int> *root = takeInputLL();
    // printTree(root);
    printTreeLL(root);
}