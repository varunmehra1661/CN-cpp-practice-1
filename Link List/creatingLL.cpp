#include <bits/stdc++.h>
#include "ClassLL.h"
using namespace std;

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
    // Dynam
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    print(head);
}
