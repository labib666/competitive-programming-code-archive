/*
ID: Labib Rashid
LANG: C++
TASK: A
CONTEST: practise contest 2
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <string>

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
#define LINF 1000000000000000007
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(LL I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)


int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

LL N, T, now, ans;
LL id[102], low[102], ins[102];
VLL v[102]; stack <LL> st;
string s;

void scc (LL pos) {
    id[pos] = low[pos] = now; now++;
    ins[pos] = 1; st.push (pos);
    FOR(i,0,v[pos].SZ) {
        LL j = v[pos][i];
        if (id[j] != 0 && ins[j] == 0) continue;
        if (id[j] == 0) {
            scc (j);
            low[pos] = min (low[pos], low[j]);
        }
        else if (id[j] != 0 && ins[j] == 1) {
            low[pos] = min(low[pos], id[j]);
        }
    }
    if (low[pos] == id[pos]) {
        ans++;
        while (1) {
            LL k = st.top();
            st.pop();
            ins[k] = 0;
            if (k == pos) break;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    cin >> T;
    while (T--) {
        cin >> N;
        FOR(i,0,N) {
            v[i].clear();
            cin >> s;
            FOR(j,0,N) {
                if (s[j]=='Y') v[i].PB (j);
            }
        }

        now = 1, ans = 0    ;
        fill(id,id+N,0);

        FOR(i,0,N) {
            if (id[i] != 0) continue;
            scc (i);
        }

        cout << ans << endl;
    }


    return 0;
}
