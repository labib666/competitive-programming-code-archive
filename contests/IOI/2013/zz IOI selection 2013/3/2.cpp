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
# define eps 1e-9

using namespace std;

struct grade {
    double t, p;
    bool operator < (const grade &k) const {
        return t/p < k.t/k.p;
    }
};

grade g[5005];
double tsum[5005], psum[5005];
double frac [5005];
vector <int> sol;

int main()
{
    int n, i, j, k;
    double a, b, c;

    cin >> n;
    tsum[0] = psum[0] = 0.0;

    for (i = 1; i <= n ; i++){
        cin >> j >> k;
        g[i].t = j, g[i].p = k;
    }
    sort (g+1, g+n+1);

    //for (i=1; i <= n; i++)
        //cout << i << " " << g[i].t << " " << g[i].p << endl;

    for (i = 1; i <= n ; i++)
    {
        tsum[i] = tsum[i-1] + g[i].t;
        psum[i] = psum[i-1] + g[i].p;
    }

    int ans = 0;
    for (i = 0; i <= n; i++)
    {
        a = (tsum[n]-tsum[i])/(psum[n]-psum[i]);

        for (j = 1; j <= n; j++)
            frac[j] = g[j].t - g[j].p*a;

        sort (frac+1, frac+n+1);
        reverse(frac+1, frac+n+1);

        double sum = 0.0;
        for (j = 1; j <= i; j++)
            sum += frac[j];

        if (sum > eps){
            ans++;
            sol.pb (i);
        }
    }

    cout << ans << endl;
    for (i = 0; i < (int) sol.size(); i++)
        cout << sol[i] << endl;

    return 0;
}
