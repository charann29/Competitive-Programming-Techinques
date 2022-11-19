
#include <bits/stdc++.h>
using namespace std;
bool palindrome(int a[], int i, int j)
{
    while (i < j)
    {
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int find(int a[], int n, int k, int st, vector<int> &dp)
{

    if (st >= n)
        return 0;
    if (dp[st] != -1)
        return dp[st];
    int maxi = 0;
    for (int i = st + k - 1; i < n; i++)
    {
        if (palindrome(a, st, i))
        {
            maxi = max(maxi, find(a, n, k, i + 1, dp)) + 1;
        }
    }
    return dp[st] = max(maxi, find(a, n, k, st + 1, dp));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> dp(n, -1);
        cout << find(a, n, k, 0, dp);
    }
    return 0;
}