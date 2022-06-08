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

void print ( Node * head)
{
    Node * temp= head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}

int main()
{
    Node *head=takeInputLevelWise();
    print(head);
}