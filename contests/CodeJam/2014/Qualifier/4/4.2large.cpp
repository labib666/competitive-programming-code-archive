/*
ID: Labib Rashid
LANG: C++
TASK: Code Jam 2014
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

#define LL long long
#define PB push_back
#define X first
#define Y second
#define INF 1000000007
#define PI 2*asin(1)
#define PII pair<int,int>
#define VI vector <int>
#define EPS 1e-9

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

double W1[1001], W2[1001];
int A[1001];

int main()
{
    //freopen (".txt","r",stdin);
    freopen ("D-large.in","r",stdin);
    freopen ("d-large.out","w",stdout);

    int t, tc=0, n, i, j, k, s1, s2;

    cin >> t;
    while (tc < t) {
        tc++;

        cin >> n;
        for (i=0;i<n;i++) cin >> W1[i];
        for (i=0;i<n;i++) cin >> W2[i];

        sort (W1, W1+n);
        sort (W2, W2+n);
        fill (A, A+n, 0);

        s1 = s2 = 0;

        for (i=n-1, j=0, k=n-1; i >= 0; i--) {
            if (W1[i] > W2[k]) { j++; s1++; }
            else k--;
        }

        for (i=0; i<n; i++) {
            for (j=0;j<n;j++) {
                if (!A[j] && W1[j] > W2[i]) {
                    A[j] = 1;
                    s2++; break;
                }
            }
        }

        printf ("Case #%d: %d %d\n", tc, s2, s1);
    }

    return 0;
}
