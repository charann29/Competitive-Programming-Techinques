#include <bits/stdc++.h>
using namespace std;

bool isF(int mid, int arr[], int n, int k)
{
    int pos = arr[0];
    int elements = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
            if (elements == k)
                return true;
        }
    }
    return 0;
}
int largestMinDist(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int res = -1;

    int left = 1, right = arr[n - 1];
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isF(mid, arr, n, k))
        {
            res = max(res, mid);
            left = mid + 1;
        }
        else
            right = mid;
    }

    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int largestMinDist(int[], int, int);
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << largestMinDist(arr, n, k);
        }

    return 0;
}