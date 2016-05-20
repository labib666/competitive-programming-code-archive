/*
USACO
3.4.3 - Electric Fence
Math - Geometry
1 Mar, 2014
/*
ID: Labib Rashid
LANG: C++
TASK: fence9
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

double check (int n, int m, int p) {
    double X, F, Y, sum = 0.0;
    int i, ans;
    for (i = 1; i < p; i++) {
        if (i == n) {
            sum += (double)m-1.0;
        }
        else if (i < n) {
            Y = (double) (m*i)/ (double) n ;
            F = floor(Y);
            sum += (F-eps < Y && F+eps > Y) ? F-1 : F;
        }
        else if (i > n) {
            Y = (double) (m*(i-p))/ (double) (n-p) ;
            F = floor(Y);
            sum += (F-eps < Y && F+eps > Y) ? F-1 : F;
        }
    }

    return sum;
}

double check2 (int n, int m, int p) {
    double X, F, Y, sum = 0.0;
    int i, ans;
    for (i = 1; i < p; i++) {
        if (i == n) {
            sum += (double)m-1.0;
        }
        else if (i < n) {
            Y = (double) (m*i)/ (double) n ;
            F = ceil(Y);
            sum += (F-eps < Y && F+eps > Y) ? F : F-1;
        }
        else if (i > n) {
            Y = (double) (m*(i-p))/ (double) (n-p) ;
            F = ceil(Y);
            sum += (F-eps < Y && F+eps > Y) ? F : F-1;
        }
    }

    return sum;
}

int main()
{
    //freopen ("fence9.txt","r",stdin);
    freopen ("fence9.in","r",stdin);
    freopen ("fence9.out","w",stdout);

    int n, m, p, ans;
    double sum;

    cin >> n >> m >> p;

    if (n <= p) sum = check(n, m, p);
    else sum = check(n, m, n) - check2(n-p, m, n-p);

    cout << (int) ceil(sum) << endl;

    return 0;
}
