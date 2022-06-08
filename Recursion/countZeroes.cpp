#include <bits/stdc++.h>
using namespace std;

int rec_countZeroes(int n)
{
    if (n == 0)
        return 0;
    int rem = n % 10;
    if (rem == 0)
    {
        return 1 + rec_countZeroes(n / 10);
    }
    else
    {
        return rec_countZeroes(n / 10);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << rec_countZeroes(n);
    }
}