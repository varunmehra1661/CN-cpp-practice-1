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

class queueUsingLL
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    queueUsingLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Queue Empty!";
            return;
        }
        return head->data;
    }

    //insert an element
    void enqueue(T element)
    {
        Node<T> *newNode = new T(element);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    //delete an element
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Empty!";
            return;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};