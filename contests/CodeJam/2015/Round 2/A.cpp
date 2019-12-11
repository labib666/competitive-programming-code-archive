/*
ID: Labib666
LANG: C++
Contest: CodeJam 2015 Online Round 2
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

int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

string s[200];
int t, r, c, tc = 0;
int XX[] = {-1,1,0,0}, YY[] = {0,0,1,-1};

int check (int a, int b, int dir) {

    int cost = 2;

    for (int k=0; k<4; k++){

        int aa = a+XX[k], bb = b+YY[k], rees = 0;

        for ( ; aa < r && aa >= 0 && bb < c && bb >= 0; aa += XX[k], bb += YY[k] ) {
            if (s[aa][bb] != '.') { rees = 1; break; }
        }

        if (rees == 1) {
            cost = min (cost, 1);
            if (dir == k) cost = 0;
        }

    }

    return cost;

}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("A-large.in","r",stdin);
    freopen ("A-large.out","w",stdout);



    cin >> t;
    while (tc<t) {

        tc++;
        cin >> r >> c;

        printf("Case #%d: ", tc);

        for (int i=0; i<r; i++) cin >> s[i];

        bool fail = 0; int ans = 0, vv;

        for (int i=0; i<r; i++) {

            for (int j=0; j<c; j++) {

                if (s[i][j] == '^') vv = check(i,j,0);
                else if (s[i][j] == 'v') vv = check(i,j,1);
                else if (s[i][j] == '>') vv = check(i,j,2);
                else if (s[i][j] == '<') vv = check(i,j,3);
                else continue;

                if (vv == 2) {
                    fail = 1;
                    //cout << "impossible for " << i+1 << " " << j+1 << endl;
                }

                else if (vv == 1) {
                    ans++;
                    //cout << "change for " << i+1 << " " << j+1 << endl;
                }

                if (fail) break;
            }

            if ( fail ) break;

        }

        if (fail) cout << "IMPOSSIBLE\n";
        else cout << ans << endl;
    }


    return 0;
}
