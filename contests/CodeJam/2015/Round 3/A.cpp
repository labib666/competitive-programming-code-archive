/*
ID: Labib666
LANG: C++
Contest: CodeJam Round 3
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

LL t, tc=0, N, D;
LL p[1000006];
PLL s[1000006];
LL S0, As, Cs, Rs, M0, Am, Cm, Rm;
vector <LL> E[1000006];

LL st[1000006], en[1000006], ttm;
LL tree[4*1000006], flag[4*1000006], sum[4*1000006];

void dfs (LL pos) {
    st[pos] = ttm++;
    for (LL i=0; i<E[pos].SZ; i++) {
        dfs(E[pos][i]);
    }
    en[pos] = ttm-1;
    return;
}

void build_tr(LL nd, LL ss, LL ee) {
    if (ss == ee) {
        tree[nd] = 1, flag[nd] = 0;
        //sum[nd] = 1;
        return;
    }

    LL md = (ss+ee)/2;
    build_tr(2*nd,ss,md);
    build_tr(2*nd+1,md+1,ee);

    //sum[nd] = sum[2*nd] + sum[2*nd+1];
    tree[nd] = tree[2*nd] + tree[2*nd+1];
    flag[nd] = 0;

    return;
}

void upd (LL nd, LL ss, LL ee, LL p1, LL p2, LL flg) {
    //cout << "upd" << " " << nd << " " << ss << " " << ee << " " << p1 << " " << p2 << " " << flg << endl;
    if (ss > p2 || ee < p1) return;
    if (ss == ee) {
        flag[nd] += flg;
        if (flag[nd] == 0) tree[nd] = 1;
        else tree[nd] = 0;
        return;
    }

    int md = (ss+ee)/2;
    upd(2*nd,ss,md,p1,p2,flg);
    upd(2*nd+1,md+1,ee,p1,p2,flg);

    tree[nd] = tree[2*nd] + tree[2*nd+1];
    flag[nd] = 0;

    return;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen ("zz test.txt","r",stdin);
    //freopen ("A-small-attempt0.in","r",stdin);
    //freopen (".out","w",stdout);

    scanf("%lld", &t);
    while (tc<t) {
        tc++;
        cin >> N >> D;

        for (int i=0; i<N; i++) E[i].clear();

        cin >> S0 >> As >> Cs >> Rs;
        cin >> M0 >> Am >> Cm >> Rm;

        s[0].X = S0, s[0].Y = 0; p[0] = M0;
        for (LL i=1; i<N; i++) {
            s[i].X = (s[i-1].X*As + Cs) % Rs; s[i].Y = i;
            p[i] = (p[i-1]*Am + Cm) % Rm;
            E[p[i]%i].PB (i);
        }


        //for (int i=0; i<N; i++) cout << i << " " << p[i] << " " << s[i].X << endl;

        ttm = 0;
        dfs(0);

        build_tr(1,0,N-1);
        //cout << tree[1] << endl;

        sort(s,s+N);

        int bnd = lower_bound(s, s+N, MP(s[0].X+D+1,0ll)) - s;
        for (LL i=bnd; i<N; i++) {
            upd(1,0,N-1,st[s[i].Y],en[s[i].Y],1);
            //cout << "remove " << s[i].Y << " " << st[s[i].Y] << " " << en[s[i].Y] << endl;
        }

        //cout << tree[1] << " " << bnd << " = bnd\n";

        LL ans = 0;
        for (LL i=0, j=bnd; i<N; i++) {
            while (j<N) {
                if (s[j].X <= s[i].X+D) {
                    upd(1,0,N-1,st[s[j].Y],en[s[j].Y],-1);
                    //cout << "add " << s[j].Y << " " << st[s[j].Y] << " " << en[s[j].Y] << endl;
                    j++;
                }
                else break;
            }
            //cout << i << " " << s[i].X << " " << s[i].Y << " " << j << " " << tree[1] << endl;
            ans = max(ans, tree[1]);
            upd(1,0,N-1,st[s[i].Y],en[s[i].Y],1);
            //cout << "remove " << s[i].Y << " " << st[s[i].Y] << " " << en[s[i].Y] << endl;
        }

        printf("Case #%lld: %lld\n", tc, ans);
    }

    return 0;
}
