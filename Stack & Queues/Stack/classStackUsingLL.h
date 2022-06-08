#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class StackUsingLL
{
    Node<T> *head;
    int size;

public:
    StackUsingLL()
    {
        head = NULL;
        size = 0;
    }

    int size()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    //insert an element
    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    //delete an element
    T pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    T top()
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }
};
