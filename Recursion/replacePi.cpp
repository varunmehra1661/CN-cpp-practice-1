#include <bits/stdc++.h>
using namespace std;

void helper(char input[], int sizE)
{
    if (sizE == 0)
    {
        return;
    }
    if (input[0] == 'p')
    {
        if (input[1] == 'i')
        {
            for (int i = sizE; i > 1; i--)
            {
                input[i + 2] = input[i];
            }
            input[0] = '3';
            input[1] = '.';
            input[2] = '1';
            input[3] = '4';
            sizE = sizE + 2;
        }
    }
    return helper(input + 1, sizE - 1);
}

char replacePi(char input[])
{
    int sizE = strlen(input) - 1;
    helper(input, sizE);
}

int main()
{

    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input;
}