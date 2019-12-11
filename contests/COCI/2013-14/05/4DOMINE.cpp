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
#include <cstring>
#include <queue>

#define ll long long
#define pb push_back
#define x first
#define y second
#define inf 1000000007
#define pi 2*asin(1)
#define PII pair<int,int>
#define VI vector <int>
#define eps 1e-9

using namespace std;

int dp[1002][1002][2][2][2], a[1002][3];
int n, k, i, j;

int solve (int pos, int left, int p1, int p2, int p3)
{
    if (left == 0) return 0;
    if (pos == n) return -inf*2;

    int &ret = dp[pos][left][p1][p2][p3], i, j;
    if (ret != -1) return ret;

    ret = -inf*2;

    if (p1 && p2) ret = max(ret, solve(pos, left-1, 0, 0, p3)+a[pos][0]+a[pos][1]);
    if (p3 && p2) ret = max(ret, solve(pos, left-1, p1, 0, 0)+a[pos][2]+a[pos][1]);
    if ( pos == n-1 ) {ret = max(ret,solve(pos+1,left,p1,p2,p3)); return ret;}

    for (i = 0; i < (1<<3); i++)
    {
        int sum = 0, pp1 = 1, pp2 = 1, pp3 = 1, cnt = 0;
        bool fail = 0;

        for (j = 0; j < 3; j++)
        {
            if (i&(1<<j)){
                if (j == 0 && !p1) {fail = 1; break;}
                else if (j == 1 && !p2) {fail = 1; break;}
                else if (j == 2 && !p3) {fail = 1; break;}

                sum += a[pos][j] + a[pos+1][j];

                if (j == 0) pp1 = 0;
                else if (j == 1) pp2 = 0;
                else if (j == 2) pp3 = 0;

                cnt++;
            }
        }
        if (fail) continue;
        if (cnt > left) continue;

        sum += solve(pos+1, left - cnt, pp1, pp2, pp3);
        ret = max(ret, sum);
    }

    return ret;
}

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int i, j, k;
    cin >> n >> k;
    for (i =0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    memset(dp, -1, sizeof (dp));

    int ans = solve (0, k, 1, 1, 1);

    cout << ans << endl;


    return 0;
}
