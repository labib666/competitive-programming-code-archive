/*
USACO
Greedy
1.3.2 - barn1
6.12.12
*/

/*
ID: Labib Rashid
LANG: C++
TASK: barn1
*/

# include <cstdio>
# include <algorithm>
# include <iostream>

using namespace std;

int main()
{
    int m, s, c, i, ans = 0;
    int dist[205];
    int cow[205];

    freopen ( "barn1.in","r",stdin);
    freopen ( "barn1.out","w",stdout);

    scanf ("%d %d %d",&m, &s, &c);
    for ( i=0; i<c; i++ )
    {
        scanf("%d",&cow[i]);
    }

    sort (cow, cow+c);

    ans += cow[0] - 1;
    ans += s - cow[c-1];

    //cout << "ANS = " << ans << endl;

    for ( i=1; i<c; i++ )
    {
        dist [i - 1] = cow[i] - cow[i-1] - 1;
    }

    sort(dist, dist + c - 1);

    int add = 0;
    for (i=0; i<min(m-1,c-1); i++){
        add += dist[c-2-i];
        //cout << i + 1 << " " << dist[c-2-i] << endl;
    }

    ans = s - ans - add;

    printf("%d\n", ans);

    return 0;
}
