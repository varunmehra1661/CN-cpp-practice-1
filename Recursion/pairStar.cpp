#include <bits/stdc++.h>
using namespace std;

void helper(char input[], int len)
{
    if (len == 0)
        return;

    if (input[0] == input[1])
    {
        for (int i = len; i > 0; i--)
        {
            input[i + 1] = input[i];
        }
        input[1] = '*';
        len = len + 1;
    }
    return helper(input + 1, len - 1);
}

void pairStar(char input[])
{
    int len = strlen(input);
    helper(input, len);
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input;
}