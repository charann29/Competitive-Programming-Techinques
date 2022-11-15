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

// method to recursively generate unique subsets.

vi arr;

vector<vi> genpow(int n)
{
    vector<vi> res;
    int i, j;
    rep(i, (1 << n))
    {
        vi str;
        rep(j, n)
        {
            if (i & (1 << j))
            {
                str.pb(arr[j]);
            }
        }
        res.pb(str);
    }
    return res;
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

        rep(i, n)
        {
            int t;
            cin >> t;
            arr.pb(t);
        }

        vector<vi> vect;
        vect = genpow(n);
        rep(i, (int)vect.size())
        {
            rep(j, (int)vect[i].size())
            {
                cout << vect[i][j] << " ";
            }
            cout << endl;
        }
    }
}