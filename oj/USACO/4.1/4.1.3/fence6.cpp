/*
USACO
4.1.3 - Fence Loops
Dijkstra
2 April 2014
/*
ID: Labib Rashid
LANG: C++
TASK: fence6
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>

#define INF 0x33333333
#define PII pair <int,int>
#define X first
#define Y second

using namespace std;

int M[202][202], V[202], S[202][202], F[202], N;

int BFS (int pos){
    memset(F, 0, sizeof(F));
    F[pos] = 1;

    int Last = pos+N, i; bool fail = 1;
    PII now;
    priority_queue <PII> Q;

    for (i=1; i<=N; i++) if (S[pos][i]) {
        Q.push(make_pair(-V[i],i));
    }

    while (!Q.empty()) {
        now = Q.top();
        Q.pop();

        if (F[now.Y]) continue;
        F[now.Y] = 1;

        if (S[now.Y][pos+N]) {
            fail = 0;
            break;
        }

        for (i=1; i<=N; i++) {
            if (F[i]) continue;
            if (!M[now.Y][i]) continue;
            Q.push(make_pair(now.X-V[i], i));
        }
    }

    return (fail) ? INF : V[pos]-now.X;
}

int main()
{
    //freopen ("fence6.txt","r",stdin);
    freopen ("fence6.in","r",stdin);
    freopen ("fence6.out","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, j, k1, k2, u, v, ans = INF;

    cin >> N;

    for (i=0;i<N;i++) {
        cin >> u;
        cin >> V[u] >> k1 >> k2;

        for (j=0;j<k1;j++) {
            cin >> v;
            M[u][v] = 1;
            S[u][v] = 1;
        }
        for (j=0;j<k2;j++) {
            cin >> v;
            M[u][v] = 1;
            S[v][N+u] = 1;
        }
    }

    for (i=1;i<=N;i++) {
        j = BFS(i);
        if (j < ans) ans = j;
    }

    cout << ans << endl;

    return 0;
}
