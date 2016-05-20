/*
ID: Labib666
LANG: C++
Contest & task: APIO 2014 practice, Task - burrow
*/

#include <bits/stdc++.h>

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define X first
#define Y second
#define VI vector <int>
#define PB push_back
#define INF 1000000007
#define PI 2*asin(1)
#define EPS 1e-9

using namespace std;


LL F[1002][1002], G[1002][1002], N, M, K;

void Mark (LL val) {
    for (LL i = M-1; i >= 0; i--) {
        for (LL j = 0; j < N; j++) {
            if (F[j][i] >= val)
                G[j][i] = i==M ? 1 : G[j][i+1]+1;
            else
                G[j][i] = 0;
        }
    }
    return;
}

LL check() {
    LL ans = 0;
    for (LL i = 0; i < M; i++) {
        LL A[1002], B[1002];
        stack <PLL> C;

        for (LL j = 0; j < N; j++) {
            while (!C.empty() && C.top().X > G[j][i]) {
                PLL now = C.top(); C.pop();
                A[now.Y] = now.X*(j-now.Y);
            }
            C.push(make_pair(G[j][i], j));
        }
        while (!C.empty()) {
            PLL now = C.top(); C.pop();
            A[now.Y] = now.X*(N-now.Y);
        }

        for (LL j = N-1; j >= 0; j--) {
            while (!C.empty() && C.top().X > G[j][i]) {
                PLL now = C.top(); C.pop();
                B[now.Y] = now.X*(now.Y-j-1);
            }
            C.push(make_pair(G[j][i], j));
        }
        while (!C.empty()) {
            PLL now = C.top(); C.pop();
            B[now.Y] = now.X*(now.Y);
        }

        for (LL j = 0; j < N; j++) {
            ans = max (A[j] + B[j], ans);
        }
    }
    return ans;
}

int main()
{
    //freopen ("burrow.txt","r",stdin);
    freopen ("burrow.in","r",stdin);
    freopen ("burrow.out","w",stdout);

    LL i, j, k, hi = 1, lo = INF, mid, ans = K;

    cin >> N >> M >> K;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cin >> F[i][j];
            lo = min (lo, F[i][j]);
            hi = max (hi, F[i][j]);
        }
    }

    while (hi >= lo) {
        mid = (hi+lo)/2;
        Mark(mid);
        k = check();

        if (k >= K) {
            ans = k;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    cout << hi << " " << ans << endl;

    return 0;
}
