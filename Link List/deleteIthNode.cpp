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

Node *deleteIthNode(Node *head, int i)
{
    int count = 0;
    Node *temp = head;
    if (i == 0)
    {
        head = temp->next;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        temp->next = temp->next->next;
        return head;
    }
}

int main()
{
    Node *head = takeInputLL();
    print(head);
    int i;
    cout << "\nThe node you wanna delete posn :: ";
    cin >> i;
    deleteIthNode(head, i);
    print(head);
}