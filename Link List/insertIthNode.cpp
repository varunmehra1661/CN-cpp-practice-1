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

Node *insertIthNode(Node *head, int idata, int i)
{
    int count = 0;
    Node *temp = head;
    Node *newNode = new Node(idata);
    if (i == 0)
    {
        newNode->next = head;
        // head = newNode;
        return newNode;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }

    return head;
}

int main()
{
    Node *head = takeInputLL();
    print(head);
    int idata, i;
    cout << "\nEnter the node to be inserted :: ";
    cin >> idata;
    cout << "\nEnter the posn of the new Node :: ";
    cin >> i;
    insertIthNode(head, idata, i);
    print(head);
}