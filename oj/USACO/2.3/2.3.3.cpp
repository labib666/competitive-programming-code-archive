/*
USACO
dfs
2.3.3 - zero sum
21.4.2013
*/
/*
ID: Labib Rashid
LANG: C++
TASK: zerosum
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

int n, c[10];
string s = " +-";

void call (int a)
{
    int i, j, k, ans, sum, now;
    if (a != n)
    {
        for (i = 0; i < 3; i++){
            c[a] = i;
            call (a+1);
        }
        return;
    }

    sum = 0, now = 1, ans = 1;
    for (i = 1; i < n; i++)
    {
        if (!c[i]) {
            now = now*10 + i+1;
            continue;
        }
        if (ans == 1) sum += now;
        else sum -= now;

        ans = c[i];
        now = i+1;
    }
    if (ans == 1) sum += now;
    else sum -= now;


    if (sum) return;

    cout << 1;
    for (i = 1; i < n; i++)
        cout << s[c[i]] << i+1;
    cout << endl;

    return;
}

int main()
{
    freopen ("zerosum.in","r",stdin);
    freopen ("zerosum.out","w",stdout);

    cin >> n;
    call (1);

    return 0;
}

