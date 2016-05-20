/*
ID: Labib666
LANG: C++
Contest: CodeJam R1C
Task: B
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

int F[110];

void build_failure_function(string pattern)
{

  int m = pattern.size();

  F[0] = F[1] = 0;

  for(int i = 2; i <= m; i++) {

    int j = F[i - 1];
    for( ; ; ) {

      if(pattern[j] == pattern[i - 1]) {
        F[i] = j + 1; break;
      }

      if(j == 0) { F[i] = 0; break; }

      j = F[j];
    }
  }
  return;
}


int t, tc=0, k, l, s, c[30], seen[110][110];
double p[30], dp[110][110];
string b, d;


double solve (int pos, int mat) {

    if (pos == s) return 0.0;
    if (seen[pos][mat]) return dp[pos][mat];

    seen[pos][mat] = 1;

    char ch = 'A'; double ans = 0.0;

    for (int cc=0; cc<26; cc++, ch++) {

        if (c[cc] == 0) continue;

        int cur = mat, cmat, flag = 0;

        while (1) {
            if (ch == d[cur]) {
                cmat = cur+1;
                if (cmat == d.size()) { flag = 1; cmat = F[cmat]; }
                break;
            }
            if (cur == 0) {
                cmat = 0;
                break;
            }
            cur = F[cur];
        }

        if (flag == 0) ans += p[cc] * solve(pos+1,cmat);
        else ans += p[cc] * (1+solve(pos+1,cmat));
    }
    return dp[pos][mat] = ans;
}


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("B-large.in","r",stdin);
    freopen ("B-large.out","w",stdout);

    cin >> t;
    while (tc < t) {
        tc++;
        memset (seen, 0, sizeof(seen));
        memset (c, 0, sizeof(c));

        cin >> k >> l >> s;

        cin >> b >> d;

        for (int i=0; i<k; i++) {
            c[b[i]-'A']++;
        }
        for (int i=0; i<30; i++) p[i] = (double)c[i]/(double)k;

        build_failure_function(d);

        int tot = 0;

        for (int i=0, j=0; i<s; ) {
            i++; j++;
            if (j == l) { tot++; j = F[j]; }
        }

        for (int i=0; i<l; i++) {
            if (c[d[i]-'A'] == 0) tot = 0;
        }

        double ans = solve(0,0);

        printf("Case #%d: %.8lf\n", tc, tot-ans);
    }


    return 0;
}
