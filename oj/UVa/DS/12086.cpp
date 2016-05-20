/*
UVa
DS
12086 - potentiometers
22.3.2103
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int p[200005], s[201005/1000];

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
            if (!(i % 1000))
                s[i/1000] = 0;
            scanf ("%d", &p[i]);
            s[i/1000] += p[i];
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
                s[x/1000] += y - p[x];
                p[x] = y;
            }

            else if (s2 == M)
            {
                scanf ("%d %d", &x, &y);
                x--;
                y--;

                if (x/1000 == y/1000)
                {
                    ans = 0;
                    for (i = x; i <= y; i++)
                        ans += p[i];
                    printf ("%d\n", ans);
                    continue;
                }

                ax = x/1000 + 1, ay = y/1000 - 1;
                ans = 0;
                for (i = ax; i <= ay; i++)
                    ans += s[i];

                for (j = x; j/1000 < ax; j++)
                    ans += p[j];

                for (j = y; j/1000 > ay; j--)
                    ans += p[j];

                printf ("%d\n", ans);
            }
        }
    }
    return 0;
}
