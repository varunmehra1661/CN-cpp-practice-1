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

Node *deleteN(Node *head, int M, int N)
{

    Node *t1 = head;
    Node *t2 = t1->next;
    while (t1 && t2)
    {
        int c1 = 1, c2 = 1;
        while (c1 == M)
        {
            t1 = t1->next;
            c1++;
        }
        t2 = t1->next;
        while (c2 == N)
        {
            t2 = t2->next;
            c2++;
        }
        t2 = t2->next;
        t1->next = t2;
        t1 = t2;
    }
    return head;
}