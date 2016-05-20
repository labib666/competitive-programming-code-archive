/*
USACO
complete search
2.1.5 - hamming distances
27.3.2013
*/
/*
ID: Labib Rashid
LANG: C++
TASK: hamming
*/

# include <cstdio>
# include <cstring>
# include <algorithm>
# include <iostream>

using namespace std;

int bit (int a)
{
    int n = 0;
    while (a > 0) {
        a = a&(a-1);
        n++;
    }
    return n;
}

int main()
{
    int n, b, c, i, j, k, a;
    int ans [70];

    freopen ("hamming.in", "r", stdin);
    freopen ("hamming.out", "w", stdout);

    cin >> n >> b >> c;

    k = 0;
    for (i = 0; i < 1 << 20; i++) {
        int fail = 0;
        for (j = 0; j < k; j++) {
            a = (ans[j]^i);
            if (bit(a) < c) {
                fail = 1;
                break;
            }
        }
        if (fail) continue;
        ans[k++] = i;
        if (k == n) break;
    }

    for (i = 0; i < n; i++)
    {
        if ((i+1)%10 && (i+1 != n)) cout << ans[i] << " ";
        else cout << ans[i] <<endl;
    }

    return 0;
}
