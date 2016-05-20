#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
# include <cstring>
# include <queue>
# define ll long long
# define pb push_back
# define x first
# define y second
# define inf 1000000007

using namespace std;

int n;

bool chk (int a)
{
    int p[25];
    int i, j, k;
    fill (p, p+25, 0);

    for (i = 0, k = 0; i < n-2; i++)
    {
        if ((a >> i) & 1) {
            k++;
            p[i+2] = k;
        }
    }
    k++;
    p[n] = k;

    j = k;

    while (j != 1)
    {
        if (p[j]) j = p[j];
        else return false;
    }

    return true;
}

int main()
{
    int t, tc, i, j, k;

    freopen("C-small-practice.in", "r", stdin);
    freopen("C-small-practice.txt", "w", stdout);

    cin >> t;
    tc = 0;

    while (tc < t)
    {
        ++tc;

        cin >> n;
        k = (1 << n-2);

        int ans = 0;

        for (i = 0; i < k; i++){
            //if (!((i >> n-2) & 1)) continue;
            if (chk(i)) {
                //bitset<24>x(i);
                //cout << i << " " << x << endl;
                ans++;
            }
        }

        ans %= 100003;

        printf ("Case #%d: %d\n", tc, ans);
    }

    return 0;
}

