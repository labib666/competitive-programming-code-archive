#include <vector>
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

string s[4];
pair <int, int> cs[4], rs[4], sum;

int main()
{
    freopen ("A-large.in", "r", stdin);
    freopen ("A-large.txt", "w", stdout);

    int n, tc = 0, i, j, k;
    cin >> n;

    while (tc < n) {

    ++tc;
    int fail = 0, done = 0;

    for (i = 0; i < 4; i++)
        cin >> s[i];

    memset(cs, 0, sizeof (cs));
    memset(rs, 0, sizeof (rs));

    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++) {
            if (s[i][j] == 'X') rs[i].x++;
            else if (s[i][j] == 'O') rs[i].y++;
            else if (s[i][j] == 'T') rs[i].y++, rs[i].x++;
            else fail = 1;
        }
    }

    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++) {
            if (s[j][i] == 'X') cs[i].x++;
            else if (s[j][i] == 'O') cs[i].y++;
            else if (s[j][i] == 'T') cs[i].y++, cs[i].x++;
            else fail = 1;
        }
    }

    for (i = 0; i < 4; i++)
    {
        if (cs[i].x == 4 || rs[i].x == 4)
        {
            printf ("Case #%d: X won\n", tc);
            done = 1;
            break;
        }
        else if (cs[i].y == 4 || rs[i].y == 4)
        {
            printf ("Case #%d: O won\n", tc);
            done = 1;
            break;
        }
    }

    if (done) continue;

    sum.x = sum.y = 0;
    for(i = 0, j = 0; i < 4; i++, j++)
    {
        if (s[j][i] == 'X') sum.x++;
        else if (s[j][i] == 'O') sum.y++;
        else if (s[j][i] == 'T') sum.y++, sum.x++;
        else fail = 1;
    }

    if (sum.x == 4)
    {
        printf ("Case #%d: X won\n", tc);
        continue;
    }
    else if (sum.y == 4 || sum.y == 4)
    {
        printf ("Case #%d: O won\n", tc);
        continue;
    }

    sum.x = sum.y = 0;
    for(i = 0, j = 3; i < 4; i++, j--)
    {
        if (s[j][i] == 'X') sum.x++;
        else if (s[j][i] == 'O') sum.y++;
        else if (s[j][i] == 'T') sum.y++, sum.x++;
        else fail = 1;
    }

    if (sum.x == 4)
    {
        printf ("Case #%d: X won\n", tc);
        continue;
    }
    else if (sum.y == 4)
    {
        printf ("Case #%d: O won\n", tc);
        continue;
    }

    if (fail) printf ("Case #%d: Game has not completed\n", tc);
    else printf ("Case #%d: Draw\n", tc);

    }

    return 0;
}

