#include"tile.h"
#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PII pair <int,int>
#define PLL pair <LL,LL>
#define X first
#define Y second
#define MP make_pair
#define VI vector <int>
#define VLL vector <LL>
#define PB push_back
#define PQI priority_queue <int>
#define PQLL priority_queue <LL>
#define QI queue <int>
#define QLL queue <LL>
#define SZ size()
#define INF 1000000007
#define LINF 1000000000000000007ll
#define PI 2.0*asin(1.0)
#define EPS 1e-9

#define FOR(I,A,B)  for(int I = (A); I < (B); ++I)
#define ALL(A)      ((A).begin(), (A).end())
#define MEM(A,V)    memset(A, (V), sizeof A)

int gcd (int a, int b) { return (b == 0) ? a : gcd (b,a%b); }
int bitcount (int a) { return (a==0) ? 0 : 1+bitcount(a&(a-1)); }
LL bigmod (LL a, LL pw, LL pr) {
    if (pw == 0) return 1ll;
    LL ans = bigmod (a, pw/2, pr);
    ans = (ans*ans) % pr;
    if (pw%2) ans = (ans * a) % pr;
    return ans;
}

int now, p[200005][6];

void tile(int x1, int x2, int y1, int y2, int bx, int by) {

    if (x2-x1 == 1) {
        int cnt = 0;
        FOR(xx,x1,x2+1) {
            FOR(yy,y1,y2+1) {
                if (xx==bx && yy==by) continue;
                p[now][cnt] = xx;
                p[now][cnt+1] = yy;
                cnt += 2;
            }
        }
        now++;
        return;
    }

    int xx1 = (x1+x2)/2, yy1 = (y1+y2)/2, tmp = now, cnt = 0; now++;
    if (bx >= x1 && bx <= xx1 && by >= y1 && by <= yy1)
        tile(x1,xx1,y1,yy1,bx,by);
    else {
        tile(x1,xx1,y1,yy1,xx1,yy1);
        p[tmp][cnt] = xx1, p[tmp][cnt+1] = yy1;
        cnt += 2;
    }
    if (bx >= x1 && bx <= xx1 && by > yy1)
        tile(x1,xx1,yy1+1,y2,bx,by);
    else {
        tile(x1,xx1,yy1+1,y2,xx1,yy1+1);
        p[tmp][cnt] = xx1, p[tmp][cnt+1] = yy1+1;
        cnt += 2;
    }

    if (bx > xx1 && by >= y1 && by <= yy1)
            tile(xx1+1,x2,y1,yy1,bx,by);
    else {
        tile(xx1+1,x2,y1,yy1,xx1+1,yy1);
        p[tmp][cnt] = xx1+1, p[tmp][cnt+1] = yy1;
        cnt += 2;
    }
    if (bx > xx1 && by > yy1)
        tile(xx1+1,x2,yy1+1,y2,bx,by);
    else {
        tile(xx1+1,x2,yy1+1,y2,xx1+1,yy1+1);
        p[tmp][cnt] = xx1+1, p[tmp][cnt+1] = yy1+1;
        cnt += 2;
    }

    return;
}

void placeTile(int n, int x, int y, int pos[][6])
{
    int x1 = 0, y1 = 0, x2 = (1<<n)-1, y2 = (1<<n)-1;
    now = 0;
    tile(x1,x2,y1,y2,x,y);
    FOR(i,0,now) {
        FOR(j,0,6) {
            pos[i][j] = p[i][j];
        }
    }
    return;
}
