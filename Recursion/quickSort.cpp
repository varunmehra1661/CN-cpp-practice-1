#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int p_back_clrs(int a[], int s, int e)
{
    int pivot = a[e];
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[j], &a[i]);
        }
    }
    swap(&a[e], &a[i + 1]);
    return i + 1;
}

void QuickSort(int a[], int s, int e)
{
    if (s >= e)
        return;
    int p = p_back_clrs(a, s, e);

    QuickSort(a, s, p - 1);
    QuickSort(a, p + 1, e);
}
void quickSort(int input[], int size)
{

    int start = 0;
    int end = size - 1;

    QuickSort(input, start, end);
}
int main()
{
    int input[] = {5, 9, 8, 5, 2, 7, 1};
    int len = sizeof(input) / sizeof(int);
    quickSort(input, len);
    for (int i = 0; i < len; i++)
    {
        cout << input[i] << " ";
    }
}
