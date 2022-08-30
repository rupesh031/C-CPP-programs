#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        unordered_map<int, int> mp;
        int n, k, i = 0, j = 0;
        cin >> n >> k;
        int arr[n];
        while (i < n)
            cin >> arr[i++];
        for (i = 0; i < n - 1; i++)
            for (j = 0; j < n - i - 1; j++)
                if (arr[j] < arr[j + 1])
                    swap(arr[j], arr[j + 1]);
        i = 0;
        j = 0;
        int newarr[n];
        while (i < n)
        {
            if (!mp[arr[i]])
            {
                mp[arr[i]] = 1;
                newarr[j] = arr[i];
                j++;
            }
            i++;
        }
        if (j >= k)
            cout << newarr[k - 1] << " ";
        else
            cout << -1 << " ";
        if (j - k > 0)
            cout << newarr[j - k];
        else
            cout << -1 << " ";
    }
    return 0;
}