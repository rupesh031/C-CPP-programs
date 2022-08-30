#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a[] = {29, 42, 12, 34, 1};
    unordered_map<int, int> umap;

    int val = 0;
    int temp[5];
    memcpy(temp, a, 5 * sizeof(int));
    sort(temp, temp + 5);
    for (int i = 0; i < 5; i++)
        umap[temp[i]] = i;
    for (int j = 0; j < 5; j++)
        a[j] = umap[a[j]];
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
}