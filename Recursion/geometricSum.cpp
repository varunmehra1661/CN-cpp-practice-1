#include <bits/stdc++.h>
using namespace std;

double rec_geoSum(int k)
{
    if (k == 0)
        return 1;
    int num = 2;
    for (int i = 1; i < k; i++)
    {
        num = num * 2;
    }
    double power = 1 / (double)num;
    return power + rec_geoSum(k - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        cout << rec_geoSum(k);
    }
}