#include <bits/stdc++.h>
using namespace std;

int rec_multiplication(int m, int n)
{
    if (n == 0)
        return 0;
    int a = rec_multiplication(m, n - 1);
    return a + m;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, n;
        cin >> m >> n;
        cout << rec_multiplication(m, n);
    }
}