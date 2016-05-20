/*
UVa
graph
10308 - roads in the north
7.3.2013
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <vector>
# include <sstream>
# include <queue>

using namespace std;
struct two {
    int p, c;
    bool operator < (const two &l) const{
        return c > l.c;
    }
};

vector <int> e[10005], c[10005];
priority_queue <two> q;
int d [10005], v[10005];

inline void dijk (int a)
{
    two t1, t2;
    int i, j, k;
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));

        t1.p = a;
        t1.c = 0;
        q.push(t1);

        while (!q.empty())
        {
            t1 = q.top();
            q.pop();

            i = t1.p, j = t1.c;
            if (v[i]) continue;

            v[i] = 1;
            d[i] = j;

            for (k=0; k< (int)e[i].size(); k++)
            {
                if (v[e[i][k]]) continue;
                t2.p = e[i][k], t2.c = j+ c[i][k];
                q.push(t2);
            }
        }
}

int main()
{
    char s1[100];
    string s2;
    int i, j, k;
    two t1, t2;
    while (gets (s1) != NULL)
    {
        if ((int)strlen(s1))
        {
            s2 = s1;
            stringstream ss;
            ss << s2;
            ss >> i;
            ss >> j;
            ss >> k;

            e[i].push_back (j);
            c[i].push_back (k);
            e[j].push_back (i);
            c[j].push_back (k);
            continue;
        }

        dijk(1);
        for (k=1, i = -1, j = 0;k <= 10004; k++) {
            if (i < d[k]) {
                i = d[k];
                j = k;
            }
        }
        dijk(j);
        for (k=1, i = -1, j = 0;k <= 10004; k++) {
            if (i < d[k]) {
                i = d[k];
                j = k;
            }
        }
        cout << i << endl;
        for (i=0; i<10005; i++) {
            e[i].clear();
            c[i].clear();
        }
    }

        dijk(1);
        for (k=1, i = -1, j = 0;k <= 10004; k++) {
            if (i < d[k]) {
                i = d[k];
                j = k;
            }
        }

        dijk(j);
        for (k=1, i = -1, j = 0;k <= 10004; k++) {
            if (i < d[k]) {
                i = d[k];
                j = k;
            }
        }
        cout << i << endl;

    return 0;
}
