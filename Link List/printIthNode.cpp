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

int lengthOfLL(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void printIthNode(Node *head, int i)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (count == i)
        {
            cout << temp->data;
            return;
        }
        temp = temp->next;
        count++;
    }
    return;
}

int main()
{
    int i;
    Node *head = takeInputLL();
    print(head);
    cout << "\nNumber of Nodes = " << lengthOfLL(head);
    cout << "\nEnter the Node to be found :: ";
    cin >> i;
    printIthNode(head, i);
}