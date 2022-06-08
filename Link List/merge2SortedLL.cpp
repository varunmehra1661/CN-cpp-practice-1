#include <bits/stdc++.h>
#include "ClassLL.h"
using namespace std;

Node *takeInputLL()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *merge2sorted(Node *h1, Node *h2)
{
    Node *fH = NULL, *fT = NULL;
    if (h1->data < h2->data)
    {
        fH = h1;
        fT = h1;
        h1 = h1->next;
    }
    else if (h1->data >= h2->data)
    {
        fH = h2;
        fT = h2;
        h2 = h2->next;
    }
    while (h1 && h2)
    {
        if (h1->data < h2->data)
        {
            fT->next = h1;
            fT = h1;
            h1 = h1->next;
            fT->next = NULL;
        }
        else if (h1->data >= h2->data)
        {
            fT->next = h2;
            fT = h2;
            h2 = h2->next;
            fT->next = NULL;
        }
    }
    if (h1)
        fT->next = h1;
    if (h2)
        fT->next = h2;

    return fH;
}

int main()
{
    Node *h1 = takeInputLL();
    Node *h2 = takeInputLL();
    print(h1);
    cout << endl;
    print(h2);
    cout << endl;
    Node *fH = merge2sorted(h1, h2);
    print(fH);
}