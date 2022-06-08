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

Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *t1 = head;
    Node *t2 = head->next;
    while (t2 != NULL)
    {
        if (t1->data == t2->data)
        {
            t1->next = t2->next;
            Node *a = t2;
            t2 = t2->next;
            delete a;
        }
        else
        {
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    return head;
}

int main()
{
    Node *head = takeInputLL();
    print(head);
    removeDuplicates(head);
    print(head);
}