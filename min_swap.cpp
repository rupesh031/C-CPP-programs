#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int min_swap(int a[], int n)
{
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    int b[n];
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        mp1[a[i]] = i;
    }
    int i = 0;
    int swap = 0;
    while (i < n)
    {
        if (!mp2[b[i]])
        {
            mp2[b[i]] = 1;
            if (i != mp1[b[i]])
            {
                int c = mp1[b[i]];
                int temp = b[i];
                b[i] = b[c];
                b[c] = temp;
                i = min(i, c);
                swap++;
                continue;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }

    return swap;
}

int main()
{
    int a[] = {101, 758, 315,
               730, 472, 619,
               460, 479};
    int n = min_swap(a, 8);
    cout << endl;
    cout << n;
    return 0;
}