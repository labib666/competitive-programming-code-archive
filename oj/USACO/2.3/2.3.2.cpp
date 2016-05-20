/*
ID: Labib Rashid
LANG: C++
TASK: nocows
*/

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

const int N = 200, K = 100, MOD = 9901;
int ans[N][K];

int main()
{
#ifndef LOCAL
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
#endif

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    for (int ki = 1; ki <= k; ki++)
    {
        ans[1][ki] = 1;
        for (int ni = 3; ni <= n; ni += 2)
        {
            for (int i = 1; i <= ni - 2; i++)
            {
                ans[ni][ki] += ans[i][ki-1] * ans[ni-1-i][ki-1];
                ans[ni][ki] %= MOD;
            }
        }
    }
    printf("%d\n", (ans[n][k] - ans[n][k-1] + MOD) % MOD);
    return 0;
}

