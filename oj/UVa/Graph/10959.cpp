/*
UVa
graph
10959 - the party, part - 1
13.3.1023
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <vector>
# include <queue>

using namespace std;
struct two {
    int p, c;
};

queue <two> q;
int v[1005], c[1005];
vector <int> e[1005];

int main ()
{
    int t, i, p, d, j, k;
    two t1, t2;

    cin >> t;
    while (t--)
    {
        cin >> p >> d;
        while (d--)
        {
            cin >> i >> j;
            e[i].push_back(j);
            e[j].push_back(i);
        }
        memset (v, 0, sizeof (v));
        memset (c, 0, sizeof (c));

        t1.p = 0, t1.c = 0;
        q.push (t1);

        while (!q.empty())
        {
            t1 = q.front();
            q.pop();

            if (v[t1.p]) continue;
            v[t1.p] = 1;
            c[t1.p] = t1.c;

            for (i=0; i<(int)e[t1.p].size(); i++)
            {
                if (v[e[t1.p][i]]) continue;
                t2.p = e[t1.p][i], t2.c = t1.c+1;
                q.push (t2);
            }
        }

        e[0].clear();
        for (i=1; i < p; i++) {
                cout << c[i] << endl;
                e[i].clear();
        }
        if (t) cout << endl;
    }
    return 0;
}
