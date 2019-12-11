# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstring>

using namespace std;

long long int a[35][15];
long long int dp[35],dest[35],order[35];
long long int d, n, mp, mi;

inline bool cmp(long long int i, long long int j){
    long long int k;
    for (k=0; k<d; k++){
        if (a[i][k] > a[j][k])
            return i > j;
        else if (a[i][k] < a[j][k])
            return i < j;
    }
    return i > j;
}

inline void find_path (long long int a, long long int k)
{
    if (k == 0)
    {
        printf("%lld ", a+1);
        return;
    }
    find_path (dest[a], k-1);
    if (k != mp -1 )printf ("%lld ", a+1);
    else printf ("%lld\n", a+1);
    return;
}

int main()
{
    long long int c, i, j, k, l, m;

    while (scanf ("%lld %lld", &n, &d)!=EOF)
    {
        memset (dest, 0, sizeof(dest));
        memset (dp, 0, sizeof(dp));
        memset (order, 0, sizeof(order));
        memset (a, 0, sizeof(a));

        for (i=0; i<n;i++)
            for (j=0; j<d; j++)
                scanf("%lld", &a[i][j]);

        for (i=0; i<n; i++) order[i] = i;

        for (i=0; i<n; i++){
            sort (a[i], a[i]+d);
            //reverse (a[i], a[i]+d);
        }

        sort (order, order +n, cmp);

        /*for (i=0; i<n; i++) {
            cout << i << " " << endl;
            int k = order[i];
            for (j=0; j<d; j++)
                cout << a[k][j] << " ";
            cout << endl;
        }*/

        dp[order[n-1]] = 1;
        dest[order[n-1]] = n;
        for (i = n-2; i>=0; i--)
        {
            k = order[i];
            //cout << "checkin >> " << k << endl;
            for (j=i+1; j<n; j++)
            {
                l = order[j];
                c = 1;
                for (m = 0; m<d; m++)
                {
                    if (a[k][m] <= a[l][m]) {
                        c = 0;
                        break;
                    }
                }
                if (c == 1) break;
            }
            if (c == 0)
            {
                //cout << "NO\n";
                dest[k] = n;
                dp[k] = 1;
                continue;
            }

            dest[k] = l;
            dp[k] = dp[l] + 1;
            //cout << "Yes " << l << " " << dp[k] << endl;
        }

        //for (i=0; i<n; i++)
            //cout << i << " " << dp[i] << " " << dest[i] << endl;

        mp = -1, mi = 0;
        for (i=0; i<n; i++)
        {
            if (dp[i] > mp)
            {
                mp = dp[i];
                mi = i;
            }
        }

        printf ("%lld\n", mp);
        find_path(mi,mp-1);
    }

    return 0;
}
