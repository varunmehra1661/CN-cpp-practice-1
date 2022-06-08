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
Node *evenAterOdd(Node *head)
{
    Node *oddH = NULL;
    Node *oddT = NULL;
    Node *evenH = NULL;
    Node *evenT = NULL;

    while (head)
    {
        if (head->data % 2 == 0)
        {
            if (evenH == NULL)
            {
                evenT = head;
                evenH = head;
            }
            head = head->next;
            evenT->next = head;
            evenT = head;
            evenT->next = NULL;
        }
        else
        {
            if (oddH == NULL)
            {
                oddH = head;
                oddT = head;
            }
            head = head->next;
            oddT->next = head;
            oddT = head;
            oddT->next = NULL;
        }
    }
    if (evenH == NULL)
    {
        return oddH;
    }
    else if (oddH == NULL)
    {
        return evenH;
    }
    evenT->next = NULL;
    oddT->next = NULL;
    oddT->next = evenT;
    return oddH;
}
int main()
{
    Node *head = takeInputLL();
    Node *newH = evenAterOdd(head);
    print(newH);
}