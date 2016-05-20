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

vector <int> e[100005];
int in[100005], sol[100005], v[100005], n;

void dfs (int a)
{
    int i, j, k, l;
    for (i = 0; i < (int) e[a].size(); i++){
        j = e[a][i];
        v[j]++;
        if (v[j] != in[j]) continue;
        if (sol[j] == 1) continue;
        sol[j] = 1;
        dfs (j);
    }
    return;
}

int main()
{
    int m, i, j, k, a;
    cin >> n >> m;

    memset(in, 0, sizeof(in));
    for (i = 1; i <= n; i++)
        e[i].clear();

    while (m--) {
        scanf ("%d %d", &i, &j);
        e[i].push_back (j);
        in[j]++;
    }

    memset(sol, 0, sizeof (sol));

    for (i = 2; i <= n; i++)
    {
        if (in[i] != 1) continue;
        if (sol[i]) continue;
        sol[i] = 1;
        fill(v+i+1, v+n+1, 0);
        dfs (i);
    }

    int ans = 0;
    for (i = 2; i <= n; i++)
        if (sol[i])
            ans++;

    cout << ans << endl;
    for (i = 2; i <= n; i++)
        if (sol[i])
            cout << i << endl;

    return 0;
}
