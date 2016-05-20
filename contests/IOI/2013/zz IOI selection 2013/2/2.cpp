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

using namespace std;

struct cow {
    int h, m;
    bool operator < (const cow &p) const {
        if (h == p.h) {
            return m < p.m;
        }
        else return h < p.h;
    }
};

int main()
{
    int n, i, j, k, ans = 0;
    ll hi = 0;
    cow c[200005];

    cin >> n;
    for (i = 0; i < n; i++)
        cin >> c[i].h >> c[i].m;

    sort (c, c+n);

    for (i = 0; i < n; i++){
        if (hi <= c[i].m) {
            hi += c[i].h;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
