/*
USACO
Greedy
1.3.2 - milk
6.12.12
*/

/*
ID: Labib Rashid
LANG: C++
TASK: milk
*/

# include <cstdio>
# include <iostream>
# include <utility>
# include <algorithm>

using namespace std;

int main()
{
    int need, farm, i;
    long long int ans = 0;
    pair <int,int> pro[5005];

    freopen ( "milk.in","r",stdin);
    freopen ( "milk.out","w",stdout);

    scanf ("%d %d", &need, &farm);

    for (i=0; i<farm; i++)
    {
        scanf("%d %d",&pro[i].first, &pro[i].second);
    }

    sort (pro, pro+farm);

    i = 0;
    while (need > 0)
    {
        ans += pro[i].first * min (need,pro[i].second);
        need -= min (need,pro[i].second);
        i++;
    }

    printf("%lld\n", ans);

    return 0;
}

