#include <bits/stdc++.h>
#include "classTreeNode.h"
using namespace std;
// treeNode<int> *takeInputLevelWise()
// {
//     int rootData;
//     cin >> rootData;
//     treeNode<int> *root = new treeNode<int>(rootData);

//     queue<treeNode<int> *> pendingNodes;

//     pendingNodes.push(root);
//     while (pendingNodes.size() != 0)
//     {
//         treeNode<int> *front = pendingNodes.front();
//         pendingNodes.pop();
//         int numChild;
//         cin >> numChild;
//         for (int i = 0; i < numChild; i++)
//         {
//             int childData;
//             cin >> childData;
//             treeNode<int> *child = new treeNode<int>(childData);
//             front->children.push_back(child);
//             pendingNodes.push(child);
//         }
//     }

//     return root;
// }

treeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);
    queue<treeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        treeNode<int> *fr = pendingNodes.front();
        pendingNodes.pop();
        int childNum;
        cin >> childNum;
        for (int i = 0; i < childNum; i++)
        {
            int childData;
            cin >> childData;
            treeNode<int> *child = new treeNode<int>(childData);
            fr->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

bool isPresent(treeNode<int> *root, int x)
{
    if (root->data == x)
        return true;

    for (int i = 0; i < root->children.size(); i++)
    {
        bool smallans = isPresent(root->children[i], x);
        if (smallans == true)
            return true;
    }

    return false;
}

// bool isPresent(TreeNode<int> *root, int x)
// {
//     queue<TreeNode<int> *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         TreeNode<int> *front = q.front();
//         q.pop();
//         if (front->data == x)
//         {
//             return true;
//         }
//         for (int i = 0; i < front->children.size(); i++)
//         {
//             q.push(front->children[i]);
//         }
//     }
//     return false;
// }

int main()
{
    treeNode<int> *root = takeInputLevelWise();
    int x;
    cin >> x;
    cout << (isPresent(root, x) ? "true" : "false");
}