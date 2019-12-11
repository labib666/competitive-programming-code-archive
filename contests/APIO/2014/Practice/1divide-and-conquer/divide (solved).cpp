/*
ID: Labib666
LANG: C++
Contest & task: APOI 2014 practise, divide & conquer
*/

#include <bits/stdc++.h>

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define X first
#define Y second
#define VI vector <int>
#define PB push_back
#define INF 1000000007ll
#define PI 2*asin(1)
#define EPS 1e-9

using namespace std;


LL N, P[100002], D[100002], G[100002], S[100002];
set <PLL> Q;
set <PLL>::iterator it;

int main()
{

    freopen ("divide.in","r",stdin);
    freopen ("divide.out","w",stdout);

    LL i, j, k, ans = 0;
    PLL now;

    cin >> N;

    for (i = 0; i < N; i++) {
        cin >> P[i] >> G[i] >> D[i];
        if ( i > 0 ) {
            S[i-1] += D[i-1] - P[i] + P[i-1];
            S[i] = S[i-1]; G[i] += G[i-1];
        }
    }

    Q.insert(make_pair(0,0));
    for (i = 0; i < N; i++) {

        k = (i == 0) ? 0 : S[i-1];
        k += D[i];

        it = Q.upper_bound (make_pair(k, INF*INF));
        it--;

        now = *it;
        ans = max(G[i] + now.Y, ans);

        Q.insert(make_pair(S[i], -G[i]));

        while (1) {
            it = Q.find(make_pair(S[i], -G[i]));
            it++;
            if (it == Q.end()) break;
            now = *it;
            if (-now.Y < G[i]) break;
            Q.erase(it);
        }

        it = Q.find(make_pair(S[i], -G[i]));
        if (it == Q.begin()) continue;
        it--;
        if (-now.Y > G[i]) continue;
        Q.erase(++it);
    }

    cout << ans << endl;

    return 0;

}
