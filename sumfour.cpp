#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {29, 42, 12, 34, 1, 5, 6, 10, 7, 8};
    unordered_map<int, pair<int, int>> umap;
    int sum = 32;
    int f = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            int t = a[i] + a[j];
            if (umap.find(sum - t) != umap.end())
            {
                pair<int, int> p = umap[sum - t];
                if (i != p.first && i != p.second && j != p.first && j != p.second)
                {
                    cout << endl;
                    cout << a[i] << " "
                         << " " << a[j] << " " << a[p.first] << " " << a[p.second];
                    f = 1;
                    break;
                }
            }
            umap[t] = make_pair(i, j);
        }
    }
    if (f)
        cout << "sum found";
    else
        cout << "not found";
    return 0;
}