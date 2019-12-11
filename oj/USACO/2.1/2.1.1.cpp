/*
ID: Labib Rashid
LANG: C++
TASK: castle
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int m[55][55], p[55][55], cnt[2505], k, r, c, b, d, dx, dy;
int X[] = {1,-1,0,0};
int Y[] = {0,0,1,-1};
int D[] = {3,1,2,0};

void flow (int x, int y)
{
    int i, xi, yi;
    p[x][y] = k;
    cnt[k]++;

    for (i=0; i<4; i++)
    {
        xi = x + X[i], yi = y + Y[i];
        if ( m[x][y] &( 1 << D[i] ) )
            continue;
        if ( p[xi][yi] != -1)
            continue;
        flow (xi, yi);
    }

    return;
}

void check (int x, int y)
{
    int i;
    int xi, yi;

        xi = x - 1, yi = y, i = 1;
        if (xi < 0 || xi >= r || yi < 0 || yi >= c) i = 0;
        if ( i && (m[x][y] & ( 1 << 1 )) && p[xi][yi] != p[x][y] ){
            if (b < cnt[p[x][y]] + cnt[p[xi][yi]])
            {
                b = cnt[p[x][y]] + cnt[p[xi][yi]];
                dx = x+1, dy = y+1, d = 1;
            }
        }

        xi = x, yi = y+1, i = 1;
        if (xi < 0 || xi >= r || yi < 0 || yi >= c) i = 0;
        if ( (m[x][y] & ( 1 << 2 )) && p[xi][yi] != p[x][y] ){
            if (b < cnt[p[x][y]] + cnt[p[xi][yi]])
            {
                b = cnt[p[x][y]] + cnt[p[xi][yi]];
                dx = x+1, dy = y+1, d = 0;
            }
        }

    return;
}

int main ()
{
    int i, j, a;

    freopen ("castle.in", "r", stdin);
    freopen ("castle.out", "w", stdout);

    cin >> c >> r;
    for (i = 0; i < r; i++)
        for (j=0; j<c; j++)
            cin >> m[i][j];

    memset (p, -1, sizeof (p));
    memset (cnt, 0, sizeof (cnt));

    k = 0, a = 0;
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++) {
            if (p[i][j] == -1){
                flow (i,j);
                a = max (a, cnt[k]);
                k++;
            }
        }
    }

    /*for (i = 0; i < r; i++){
        for (j = 0; j < c; j++)
            cout << p[i][j] << " ";
        cout << endl;
    }*/

    b = 0;
    for (j = 0; j <= c-1; j++){
        for (i = r - 1; i >= 0; i--) {
            check (i,j);
        }
    }

    if (d) printf ("%d\n%d\n%d\n%d %d N\n", k, a, b, dx, dy);
    else printf ("%d\n%d\n%d\n%d %d E\n", k, a, b, dx, dy);

    return 0;
}
