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
    freopen ("B-large.in","r",stdin);
    freopen ("b-large.out","w",stdout);

    int t, tc = 0, i, j;
    double T, C, F, X, R;

    cin >> t;
    while (tc < t) {
        tc++;

        cin >> C >> F >> X;
        T = 0.0;
        R = 2.0;

        while (1) {
            if ( (X-C)*(R+F) > R*X ) {
                T += C/R;
                R = R + F;
            }
            else {
                T += X/R;
                break;
            }
        }

        printf ("Case #%d: %0.7lf\n", tc, T);
    }


    return 0;
}
