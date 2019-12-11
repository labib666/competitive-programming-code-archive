#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cctype>
#include<sstream>

#include<vector>
#include<list>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>

#define F first
#define S second
#define pb push_back
#define it iterator
#define pq priority_queue
#define mp make_pair
#define PI acos(-1)
#define DIFF(a, b) ((a)>(b)?((a)-(b)):((b)-(a)))
#define SQR(x) ((x)*(x))
#define INF 1<<25
#define MAX 100

using namespace std;

struct data
{
    int dst, cst;
};

data key[MAX][MAX];
int fst[MAX];

int main()
{
    int n, m, qr, i, j, k, c, s, d, u, v, w, cas=0, ans;
    while(scanf("%d %d %d", &n, &m, &qr) && (n||m||qr))
    {
        if(cas)printf("\n");
        for(i=1; i<=n; i++)
        {
            scanf("%d", &fst[i]);
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(i==j)key[i][i].dst=0, key[i][i].cst=fst[i];
                else key[i][j].dst=INF, key[i][j].cst=max(fst[i], fst[j]);
            }
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            key[u][v].dst=w;
            key[v][u].dst=w;
        }
        for(k=1; k<=n; k++)
        {
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    d=key[i][k].dst+key[k][j].dst;
                    c=max(key[i][k].cst, key[k][j].cst);
                    if(key[i][j].dst+key[i][j].cst>d+c)
                    {
                        key[i][j].dst=d;
                        key[i][j].cst=c;
                    }
                }
            }
        }
        for(k=1; k<=n; k++)
        {
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    d=key[i][k].dst+key[k][j].dst;
                    c=max(key[i][k].cst, key[k][j].cst);
                    if(key[i][j].dst+key[i][j].cst>d+c)
                    {
                        key[i][j].dst=d;
                        key[i][j].cst=c;
                    }
                }
            }
        }
        printf("Case #%d\n", ++cas);
        for(i=1; i<=qr; i++)
        {
            scanf("%d %d", &s, &d);
            ans=key[s][d].dst+key[s][d].cst;
            //cout<<key[s][d].cst<<endl;
            if(ans>=INF)printf("-1\n");
            else printf("%d\n", ans);
        }
    }
    return 0;
}
