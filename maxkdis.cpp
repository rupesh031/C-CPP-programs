#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {6, 5, 1, 2, 3, 2, 1, 4, 5};
    unordered_map<int, int> umap;
    int k = 3, max = 0, start = 0, end = 0, distict = 0, rstart;
    int prev = 0, now = 0;

    for (int i = 0; i < 9; i++)
    {
        if (umap.find(a[i]) != umap.end())
        {
            umap[a[i]]++;
        }
        else
        {
            umap[a[i]] = 1;
            distict++;
        }
        if (distict == k)
        {
            if (now > prev)
            {
                rstart = start;
                end = i;
            }
            prev = now;
            now = now - a[start];
            start++;
        }
        now++;
    }
    for (int i = rstart; i <= end; i++)
        cout << a[i] << " ";
    return 0;
}