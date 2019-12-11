/*
ID: Labib666
LANG: C++
Contest: Code Jam 2015 Qualifier
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

LL t, tc = 0, now, sz, ans;
string s;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("A-large.in","r",stdin);
    freopen ("A-large.out","w",stdout);


    cin >> t;
    while (tc<t) {
        tc++; now = ans = 0;

        cin >> sz; sz++;
        cin >> s;

        for (int i=0; i<sz; i++) {
            if (s[i] == '0') continue;
            if (now < i) {
                ans += (i-now);
                now = i;
            }
            now += (s[i]-'0');
        }
        printf("Case #%lld: %lld\n", tc, ans);
    }


    return 0;
}
