/*
ID: Labib Rashid
LANG: C++
TASK: 2
CONTEST: CodeJam 2014 R2
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

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)


LL N, a[1002], tmp[1002];
VLL b,c;

LL solve();

int main(){

    //freopen("input.txt","r",stdin);
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.txt","w",stdout);

    LL T, tc, mx, i, j, k;
    LL ans, now, ms;

    cin >> T;
    tc = 0;

    while(tc < T){
        tc++;

        cin >> N;
        mx = 0;
        for(i = 0; i < N; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        ans = INF;
        for(ms = 0; ms < (1ll<<N); ms++){
            b.clear();
            c.clear();

            for(i = 0; i < N; i++){
                if(a[i] == mx){
                    b.PB(a[i]);
                    continue;
                }
                if(ms & (1<<i)) b.PB(a[i]);
                else c.PB(a[i]);
            }

            sort(b.begin(), b.end());

            sort(c.begin(), c.end());
            reverse(c.begin(), c.end());

            for(i = 0; i < c.size(); i++)
                b.PB(c[i]);

            now = solve();
            ans = min(now,ans);
        }

        printf("Case #%lld: %lld\n",tc, ans);
    }

    return 0;
}

LL solve()
{
    int i, j, tt, now, sv;

    for(i = 0; i < N; i++)
        tmp[i] = a[i];

    tt = 0;
    for(i = 0; i < N; i++){
        now = b[i];
        if(tmp[i]== b[i]) continue;
        for(j = 0; j < N; j++){
            if(tmp[j]== now){
                sv = j;
                break;
            }
        }

        for(j = sv; j > i; j--){
            swap(tmp[j],tmp[j-1]);
            tt++;
        }
    }

    return tt;
}
