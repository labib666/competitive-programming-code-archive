/*
ID: Labib666
LANG: C++
Contest & task: APIO 2014 practice, Task - Trading
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

VI S[300002], E[300002];
bool Gate[300002];
int V[300002], B[300002], N, M;
priority_queue <PII> Q;

int main()
{
    //freopen ("trading.txt","r",stdin);
    freopen ("trading.in","r",stdin);
    freopen ("trading.out","w",stdout);

    int i, j, k;

    scanf ("%d %d", &N, &M);
    for (i = 0; i < M; i++) {
        cin >> B[i] >> j >> V[i];
        S[B[i]].PB (i);
        E[j].PB (i);
    }

    for (i = 1; i <= N; i++) {
        for (j = 0; j < S[i].size(); j++) {
            k = S[i][j];
            Gate[k] = 1;
            Q.push (make_pair(V[k]+N-B[k], k));
        }

        PII now;
        while (!Q.empty()) {
            now = Q.top();
            if (Gate[now.Y]) break;
            Q.pop();
        }

        for (j = 0; j < E[i].size(); j++) {
            k = E[i][j];
            Gate[k] = 0;
        }

        if (Q.empty()) cout << "0\n";
        else cout << V[now.Y] + i - B[now.Y] << endl;
    }


    return 0;
}
