#include <bits/stdc++.h>
#include "ClassLL.h"
using namespace std;

Node *takeInputLevelWise()
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
            tail = tail->next; //OR tail=newNode
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
    Node *fH = NULL;
    Node *fT = NULL;
    if (h1->data > h2->data)
    {
        fH = h2;
        fT = h2;
        h2 = h2->next;
    }
    else if (h1->data < h2->data)
    {
        fH = h1;
        fT = h1;
        h1 = h1->next;
    }
    while (h1 && h2)
    {
        if (h1->data > h2->data)
        {
            fT->next = h2;
            fT = h2;
            h2 = h2->next;
            h2->next = NULL;
        }
        else if (h1->data < h2->data)
        {
            fT->next = h1;
            fT = h1;
            h2 = h2->next;
            h2->next = NULL;
        }
    }
    if (h1)
    {
        fT->next = h1;
    }
    else if (h2)
    {
        fT->next = h2;
    }
    return fH;
}

Node *midPoint(Node *head)
{
    Node *slow = head, *fast = head->next;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
    // merge2sorted(head,slow);
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *p = midPoint(head);
    head = mergeSort(head);
    p = mergeSort(p);
    return merge2sorted(head, p);
}

int main()
{
    Node *head = takeInputLevelWise();
    print(head);
    mergeSort(head);
    print(head);
}