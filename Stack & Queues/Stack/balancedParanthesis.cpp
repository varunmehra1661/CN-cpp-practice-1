#include <bits/stdc++.h>
#include <stack>
#include <cstring>
using namespace std;

bool isBalanced(char *exp)
{
    stack<char> s;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (s.empty() && (exp[i] == ']' || exp[i] == '}' || exp[i] == ')'))
        {
            return false;
        }

        if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
        {
            s.push(exp[i]);
        }

        if (exp[i] == ']')
        {
            if (s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        if (exp[i] == '}')
        {
            if (s.top() == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        if (exp[i] == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char s[50];
    cin >> s;
    if (isBalanced(s)  )
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    
    
    // isBalanced(s);
}