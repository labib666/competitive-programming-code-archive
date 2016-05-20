/*
ID: Labib666
LANG: C++
Contest: COCI mock 2
Task: A
*/

#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector <int>
#define VLL vector <LL>
#define PQI priority_queue <int>
#define PQLL priority_queue <LL>
#define QI queue <int>
#define QLL queue <LL>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define SZ size()
#define INF 1000000007
#define LINF 1000000000000000007ll
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)

#define MAXN



int n, m, last[1048][2048], dp[1048][2048], a[1048];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen ("zz test.txt","r",stdin);

    cin >> n >> m;
    for (int i=1; i<=m; i++) cin >> a[i];

    reverse(a+1, a+m+1);
    memset(dp, 0, sizeof(dp));

    for (int i=1; i<=n; i++) dp[0][i] = 1;

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (j == a[i]) continue;
            if (j != 1 && dp[i-1][j-1] == 1) dp[i][j] = 1, last[i][j] = j-1;
            if (j != n && dp[i-1][j+1] == 1) dp[i][j] = 1, last[i][j] = j+1;
        }
    }

    int pos = 0;
    for (int i=1; i<=n; i++) {
        if (dp[m][i] == 1) { pos = i; break; }
    }

    if (pos==0) {
        cout << "menyerah\n";
        return 0;
    }

    int now = m;
    while (now) {
        cout << pos << endl;
        pos = last[now][pos];
        now--;
    }


    return 0;
}
