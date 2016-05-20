/*
USACO
2.2.3 - runaround numbers
complete search
31.3.2013
*/
/*
ID: Labib Rashid
LANG: C++
TASK: runround
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

vector <int> s;
int vis[10], num;

void gen (int a, int k)
{
    if (!a) {
        s.push_back (num);
        return;
    }

    for (int i = 1; i < 10; i++)
    {
        if (vis[i]) continue;

        num += k*i, vis[i] = 1;
        gen (a-1, k*10);

        num -= k*i, vis[i] = 0;
    }

    return;
}

int bs (int a) {
    int hi, lo, mid;
    hi = s.size()-1, lo = 0;

    while (hi >= lo) {
        mid = (hi+lo) / 2;

        if (s[mid] > a)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return lo;
}

bool chk (int a, int k) {
    int arr [10], p, q, i, v[10];
    memset (v, 0, sizeof (v));

    for (i = 0; i < k; i++) {
        arr[i] = a%10;
        a /= 10;
    }

    q = k-1, p = 0;
    while (1) {
        if (p == k && q == k-1)
            return true;
        if (v[q])
            break;
        v[q] = 1, p++;
        q = 362880 + q - arr[q];
        q %= k;
    }

    return false;
}

int main()
{
    int n, i, j, k, ans = 0;

    freopen ("runround.in", "r", stdin);
    freopen ("runround.out", "w", stdout);

    cin >> n;

    i = n, k = 0;
    while (i > 0){
        k++;
        i /= 10;
    }

    while (1){
        num = 0;
        memset (vis, 0, sizeof (vis));
        gen (k, 1);
        sort (s.begin (), s.end ());

        j = bs (n);
        bool tr = false;

        for (i = j; i < (int) s.size(); i++){
            tr = chk (s[i], k);
            if (tr) {
                ans = s[i];
                break;
            }
        }
        if (tr) break;

        s.clear();
        k++;
    }

    cout << ans << endl;

    return 0;
}
