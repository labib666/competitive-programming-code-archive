/*
ID: Labib Rashid
LANG: C++
TASK: paint
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# include <vector>

using namespace std;

# define in push_back

    int n, m, i, x, y, z;
    int cow[1010];
    string c,p = "L";
    char c1[3];
    vector <int > stat[1010];

int main ()
{
    memset(cow, 0, sizeof(cow));

    scanf ("%d %d", &n, &m);

    for (i=0; i<m; i++)
    {
        scanf ("%d %d %s", &x, &y, c1);
        c = c1;
        if (c == p) z = 2;
        else z = 1;
        b = 0;

        if (cow[x] == 0)
        {
            if (cow[y] == 0)
            {
                cow[x] = 1;
                cow[y] = z;
            }

            else if (cow[y] == 1)
            {
                if (z == 1) cow[x] = 1;
                else cow[x] = 2;
            }

            else if (cow[y] == 2)
            {
                if (z == 2) cow[x] = 1;
                else cow[x] = 2;
            }

            stat[y].in(x);
        }

        else if (cow[x] == 1)
        {
            if (cow[y] == 0)
            {
                cow[y] = z;
            }

            else if (cow[y] != z)
            {
                find(y,y,z);
                if (b == 1) break;
            }

            stat[y].in(x);
        }

        else if (cow[x] == 1)
        {
            if (cow[y] == 0)
            {
                cow[y] = z;
            }

            else if (cow[y] != z)
            {
                find(y,y,z);
                if (b == 1) break;
            }

            stat[y].in(x);
        }

        else if (cow[x] == 2)
        {
            if (cow[y] == 0)
            {
                cow[y] = z;
            }

            else if (cow[y] != z)
            {
                find(y,y,z);
                if (b == 1) break;
            }

            stat[y].in(x);
        }
    }
    return 0;
}
