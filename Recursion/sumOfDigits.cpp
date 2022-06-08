#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int rem = n % 10;
    return sumOfDigits(n / 10) + rem;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << sumOfDigits(n);
    }
}