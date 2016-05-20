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

string s[55], str = "\\a";

bool chk (int a, int b)
{
    int i, j, k;

    if (s[a][b+1] == '#' && s[a+1][b+1] == '#' && s[a+1][b] == '#')
    {
        s[a][b+1] = str[0];
        s[a+1][b] = str[0];
        s[a][b] = '/';
        s[a+1][b+1] = '/';
        return true;
    }

    return false;
}

int main()
{
    int t, tc = 0, r, c, i, j, k;

    freopen ("A-large-practice.in", "r", stdin);
    freopen ("A-large-practice.txt", "w", stdout);

    cin >> t;
    while (tc < t)
    {
        ++tc;

        cin >> r >> c;

        for (i = 0; i < r; i++)
            cin >> s[i];
        s[r].clear();
        for (i = 0; i < c; i++)
            s[r] += '.';

        bool fail = 0;
        for (i = 0; i < r; i++){
            for (j = 0; j < c; j++){
                if (s[i][j] == '#'){
                    if (!chk(i,j))
                    {
                        fail = 1;
                        break;
                    }
                }
            }
            if (fail) break;
        }

        if (fail) printf ("Case #%d:\nImpossible\n", tc);
        else {
            printf ("Case #%d:\n", tc);
            for (i = 0; i < r; i++)
                cout << s[i] << endl;
        }
    }

    return 0;
}
