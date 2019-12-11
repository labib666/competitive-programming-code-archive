/*
ID: Labib666
LANG: C++
Contest: APIO 2015
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

#define MAXN 30004


int n, m;
int b[MAXN], p[MAXN], d[MAXN];
vector <int> v[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);

    memset(d,-1,sizeof(d));

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> b[i] >> p[i];
        v[b[i]].PB (i);
    }

    d[b[0]] = 0;
    bool pass = 0;

    for (int i=0; ; ) {
        if (d[b[1]] == i) { pass=1; break; }

        for (int j=0; j<n; j++) {
            if (d[j] == i && v[j].size() != 0) {

                for (int l = 0; l < v[j].size(); l++) {
                    for (int k = j-p[v[j][l]]; k >= 0; k-=p[v[j][l]]) {
                        if (d[k] <= i && d[k] != -1) continue;
                        d[k] = (d[k] == -1) ? d[j] + (j-k)/p[v[j][l]] : min (d[k],d[j] + (j-k)/p[v[j][l]]);
                    }
                    for (int k = j+p[v[j][l]]; k < n; k+=p[v[j][l]]) {
                        if (d[k] <= i && d[k] != -1) continue;
                        d[k] = (d[k] == -1) ? d[j] + (k-j)/p[v[j][l]] : min (d[k],d[j] + (k-j)/p[v[j][l]]);
                    }
                }
            }
        }

        int cur = -1;
        for (int j=0; j<n; j++) {
            if (d[j] == -1 || d[j] <= i || v[j].size()==0 ) continue;
            cur = (cur == -1) ? d[j] : min (d[j],cur);
        }
        if (cur == -1) break;
        i = cur;

    }

    if (pass) cout << d[b[1]] << endl;
    else cout << "-1\n";

    return 0;
}
