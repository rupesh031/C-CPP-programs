#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {29, 42, 12, 34, 1, 5, 6, 10, 7, 8};
    unordered_map<int, int> umap;
    int dp[10];
    memset(dp, 0, sizeof(dp));
    int max = 0;

    for (int i = 0; i < 10; i++)
    {
        if (umap.find(a[i] - 1) != umap.end())
        {
            dp[i] = dp[umap[a[i] - 1]] + 1;
        }
        else
        {
            dp[i] = 1;
        }
        max = dp[i] > max ? dp[i] : max;
        umap[a[i]] = i;
    }
    cout << max;
}