/*
ID: Labib Rashid
LANG: C++
TASK: fence8
*/
/*
USACO
4.1.2 - Fence Rails
DFS, Optimization techniques
2 April 2014
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

int gcd (int a, int b)
{
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

int bitcount (int a)
{
    return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;
}

int N, R, K;
int board[52], bsum[52];
int rail[1025], rsum[1025], rused[1025], rleft;

bool solve (int pos, int bleft) {
    if (pos == N) return 1;
    if (bsum[N] - bsum[pos+1] + bleft < rleft) return 0;

    for (int i=K-1; i>=0; i--) {
        if (rused[i] || rail[i] > bleft) continue;
        rused [i] = 1;
        rleft -= rail[i];
        if (solve(pos, bleft-rail[i])) return 1;
        rused [i] = 0;
        rleft += rail[i];
        while (i > 0 && rail[i-1] == rail[i]) i--;
    }

    return solve(pos+1, board[pos+1]);
}

bool check () {
    fill (rused, rused+K, 0);
    rleft = rsum [K];
    return solve(0, board[0]);
}

int main()
{
    //freopen ("fence8.txt","r",stdin);
    freopen ("fence8.in","r",stdin);
    freopen ("fence8.out","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int hi, lo, i, j;

    cin >> N;
    for (i=0;i<N;i++)
        cin >> board[i];

    sort (board, board+N);
    for (i=0;i<N;i++)
        bsum[i+1] = bsum[i]+board[i];


    cin >> R;
    for (i=0;i<R;i++)
        cin >> rail[i];

    sort (rail, rail+R);
    for (i=0;i<R;i++)
        rsum[i+1] = rsum[i]+rail[i];

    while (R && rsum[R] > bsum[N]) R--;
    while (R && rail[R-1] > board[N-1]) R--;

    lo = 0, hi = R;
    while (hi >= lo) {
        K = (hi+lo)/2;
        if (check()) lo = K + 1;
        else hi = K - 1;
    }

    cout << hi << endl;

    return 0;
}
