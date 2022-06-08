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
    Node *tail = head;
    while (tail != NULL)
    {
        count++;
        tail = tail->next;
    }
    return count;
}
Node *printrevLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallAns = printrevLL(head->next);
    Node *temp = smallAns;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallAns;
}
Node *midPoint(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome(Node *head)
{
    Node *slow = head;
    stack<int> s;
    while (slow != NULL)
    {
        s.push(slow->data);
        slow = slow->next;
    }
    while (head != NULL)
    {

                int i = s.top();

        // Pop the element
        s.pop();

        // Check if data is not
        // same as popped element
        if (head->data != i)
        {
            return false;
        }

        // Move ahead
        head = head->next;
    }

    return true;
}

int main()
{
    Node *head = takeInputLL();
    // print(head);
    bool ans = isPalindrome(head);
    if (ans)
        cout << "true";
    else
        cout << "false";
}