/*
ID: Labib Rashid
LANG: C++
TASK: cowrace
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

using namespace std;

queue <int> q1, q2;

int main()
{
    freopen ("cowrace.in","r",stdin);
    freopen ("cowrace.out","w",stdout);

    int m, n, x, y, i, d1, d2, l, res;
    cin >> m >> n;

    while (m--)
    {
         cin >> x >> y;
         for (i=0; i <y; i++)
            q1.push (x);
    }
    while (n--)
    {
        cin >> x >> y;
         for (i=0; i <y; i++)
            q2.push (x);
    }

    res = -1, d1 = d2 = 0;
    l = 0;
    while (!q1.empty())
    {
        d1 += q1.front();
        q1.pop();
        d2 += q2.front();
        q2.pop();

        if (l != 1)
        {
            if (d1 > d2) {
                l = 1;
                res++;
                continue;
            }
        }
        if (l != 2)
        {
            if (d2 > d1)
            {
                l = 2;
                res++;
            }
        }
    }
    if (res == -1) res++;

    cout << res << endl;

    return 0;
}
