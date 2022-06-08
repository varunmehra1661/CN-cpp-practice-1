#include <bits/stdc++.h>
using namespace std;

int helper(char input[], int len)
{
    int b = input[0] - 48;
    if (len == 1)
    {
        return b;
    }
    return (b * pow(10, len - 1) + helper(input + 1, len - 1));
}

int stringToNumber(char input[])
{
    int len = strlen(input);
    return helper(input, len);
}

int main()
{

    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}