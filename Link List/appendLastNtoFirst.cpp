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

int length(Node *head)
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

Node *appendLastN(Node *head, int N)
{
    Node *curr = head;
    int len=length(head);
    int count=0,i=len-N;
    while (curr!=NULL && count < i-1)
    {
        curr=curr->next;
        count++;
    }
    Node *head2=curr->next;
    curr->next=NULL;
    Node *tail=head2;
    while (tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=head;
    
    head=head2;
    return head;

}

int main()
{
    Node *head = takeInputLL();
    print(head);
    int N;
    cout << "\nEnter the last N Nodes :: ";
    cin >> N;
    Node *h2=appendLastN(head, N);
    print(h2);
}