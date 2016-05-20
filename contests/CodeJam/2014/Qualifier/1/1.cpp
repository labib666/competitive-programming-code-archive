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

int main()
{
    //freopen (".txt","r",stdin);
    freopen ("A-small-attempt0.in","r",stdin);
    freopen ("A-small-attempt0.out","w",stdout);

    int t, tc = 0, r1, r2, i, j, k;
    int A[4][4], B[4][4], C[20];

    cin >> t;
    while (tc<t) {
        tc++;

        cin >> r1;
        for (i=0;i<4;i++) {
            for (j=0;j<4;j++) {
                cin >> A[i][j];
            }
        }

        cin >> r2;
        for (i=0;i<4;i++) {
            for (j=0;j<4;j++) {
                cin >> B[i][j];
            }
        }

        memset (C, 0, sizeof (C));

        for (i=0;i<4;i++)
            C[A[r1-1][i]]++;

        for (i=0;i<4;i++)
            C[B[r2-1][i]]++;

        int fail = 1;

        for (i=1;i<=16;i++) {
            if (C[i] > 1) {
                if (fail == 1) {
                    fail = 0;
                    k = i;
                    continue;
                }
                else {
                    fail = 2;
                    break;
                }
            }
        }

        if (fail == 0) printf ("Case #%d: %d\n", tc, k);
        else if (fail == 1) printf ("Case #%d: Volunteer cheated!\n", tc);
        else printf ("Case #%d: Bad magician!\n", tc);
    }

    return 0;
}
