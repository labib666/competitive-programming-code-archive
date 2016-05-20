/*
ID: Labib Rashid
LANG: C++
TASK:
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
# define pi 2*asin(1)

using namespace std;

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int n, w, h, i, j, k;
    string s[100];
    pair <int, int> p1, p2;

    cin >> n >> w >> h;

    for (i = 0; i < h; i++)
        cin >> s[i];

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (s[i][j] == '1')
                p1.x = i, p1.y = j;
            if (s[i][j] == '2')
                p2.x = i, p2.y = j;
        }
    }

    if (p1 == p2) cout << 0 << endl;
    else if (p1.x == p2.x || p1.y == p2.y)
        cout << 1 << endl;
    else if (p1.x == 0 || p1.x == h-1 || p2.x == 0 || p2.x == h-1)
        cout << 2 << endl;
    else if (p1.y == 0 || p1.y == w-1 || p2.y == 0 || p2.y == w-1)
        cout << 2 << endl;
    else cout << 3 << endl;

    return 0;
}

