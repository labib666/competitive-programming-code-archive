# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int p[200005], s[201005/3];

int main()
{
    int t = 0, n, x, y, ax, ay, i, j, k, ans;
    string s2, e = "END", S = "S", M = "M";
    char s1[100];

    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        if (t) cout << endl;

        for (i = 0; i < n; i++)
        {
            if (!(i % 3))
                s[i/3] = 0;
            scanf ("%d", &p[i]);
            s[i/3] += p[i];
        }

        printf ("Case %d:\n", ++t);
        while (1)
        {
            scanf ("%s", s1);
            s2 = s1;
            if (s2 == e)
                break;

            if (s2 == S)
            {
                scanf("%d %d", &x, &y);

                x--;
                s[x/3] = y - p[x];
                p[x] = y;
            }

            else if (s2 == M)
            {
                scanf ("%d %d", &x, &y);
                x--;
                y--;

                if (x/3 == y/3)
                {
                    ans = 0;
                    for (i = x; i <= y; i++)
                        ans += p[i];
                    printf ("%d\n", ans);
                    continue;
                }

                ax = x/3 + 1, ay = y/3 - 1;
                ans = 0;
                for (i = ax; i <= ay; i++)
                    ans += s[i];
                //cout << ans << " " << s[ax] << " "  << s[ay] << endl;
                for (j = x; j/3 < ax; j++)
                    ans += p[j];
                //cout << ans << endl;
                for (j = y; j/3 > ay; j--)
                    ans += p[j];
                //cout << ans << endl;

                printf ("%d\n", ans);
            }
        }
    }
    return 0;
}

