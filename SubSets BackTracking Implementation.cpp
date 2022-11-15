#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, n) for (i = 0; i < n; i++)
#define repr(i, n) for (i = n; i > 0; i--)
#define repa(i, a, n) for (i = a; i < n; i++)
#define repit(x, k) for (auto x : k)
#define vi vector<int>
#define fi first
#define se second
#define pb(t) push_back(t)
#define mp(a, b) make_pair(a, b)
#define mtup(a, b, c) make_tuple(a, b, c)
#define fbo(x) find_by_order(x) // value at position
#define ook(x) order_of_key(x)  // position of value
#define lowb(x) lower_bound(x)
#define uppb(x) upper_bound(x)
#define M 1000000007

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void ssUtil(vector<vi> &result, vi &subset, vi &prime, int index)
{
    result.pb(subset);
    for (int i = index; i < (int)prime.size(); i++)
    {
        subset.pb(prime[i]);
        ssUtil(result, subset, prime, i + 1);
        subset.pop_back();
    }
}
vector<vector<int>> subset_search(vector<int> &prime)
{
    vi subset;
    vector<vi> result;
    int index = 0;
    ssUtil(result, subset, prime, index);
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i, j;
    int t = 1;
    // cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vi arr(n);
        vector<vi> result;
        rep(i, n) { cin >> arr[i]; }
        result = subset_search(arr);

        rep(i, (int)result.size())
        {
            rep(j, (int)result[i].size())
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
}