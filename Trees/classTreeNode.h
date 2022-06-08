#include <bits/stdc++.h>
using namespace std;

template <typename T>

class treeNode
{
public:
    T data;
    vector<treeNode<T> *> children;

    // constructor
    treeNode(T data)
    {
        this->data = data;
    }

    // destructor
    ~treeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};