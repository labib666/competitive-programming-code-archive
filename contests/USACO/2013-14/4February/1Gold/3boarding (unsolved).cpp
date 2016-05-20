/*
ID: Labib Rashid
LANG: C++
TASK: boarding
*/

#include <algorithm>
#include <iostream>
#include <cstdio>

#define LL long long
#define MAX 200002

using namespace std;

LL N, T[MAX], S[MAX], V[MAX], A[4*MAX], F[4*MAX];

void Update (LL n, LL s, LL e, LL p1, LL p2, LL v) {
    if (s > p2 || e < p1) return;
    if (s >= p1 && e <= p2) {
        A[n] += v;
        F[n] += v;
        return;
    }

    if (F[n]) {
        F[2*n] += F[n], F[2*n+1] += F[n];
        A[2*n] += F[n], A[2*n+1] += F[n];
        F[n] = 0;
    }

    LL m = (s+e)/2;
    Update(2*n, s, m, p1, p2, v);
    Update(2*n+1, m+1, e, p1, p2, v);

    A[n] = max (A[2*n], A[2*n+1]);
    return;
}

LL Query (LL n, LL s, LL e, LL p1, LL p2) {
    if (s > p2 || e < p1) return 0;
    if (s >= p1 && e <= p2) return A[n];

    if (F[n]) {
        F[2*n] += F[n], F[2*n+1] += F[n];
        A[2*n] += F[n], A[2*n+1] += F[n];
        F[n] = 0;
    }

    LL m = (s+e)/2, v1, v2;
    v1 = Query(2*n, s, m, p1, p2);
    v2 = Query(2*n+1, m+1, e, p1, p2);

    return max (v1, v2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen ("3boarding.txt","r",stdin);
    //freopen ("boarding.in","r",stdin);
    //freopen ("boarding.out","w",stdout);

    LL i, j, k;

    cin >> N;
    for (i = N; i > 0; i--)
        cin >> S[i] >> T[i];

    for (i = 1; i <= N; i++) {
        k = Query(1, 1, N, 1, min(S[i]+i-1, N));
        V[i] = k + S[i] + T[i];
        Update(1, 1, N, S[i], S[i], T[i]+k);
    }

    LL ans = 0;
    for (i = 1; i <= N; i++)
        ans = max (ans, V[i]);

    cout << ans << endl;

    return 0;
}
