/*
UVa
DS
10258 - contest scoreboard
8.3.2013
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <sstream>
# include <queue>

using namespace std;

struct rank {
    int t, s, p;
    bool operator < (const rank a) const {
        if (s == a.s) {
            if (p == a.p) {
                return t > a.t;
            }
            else return p > a.p;
        }
        else return s < a.s;
    }
};

int att[105];
vector <int> t[105], p[105];
vector <string> v[105];
priority_queue <rank> qu;

void res (int a)
{
    int i, j, c[10], q[10];
    rank b;
    string ac = "C", wa = "I";
    fill (q, q+10, 0);
    fill (c, c+10, 0);

    for (i = 0; i < (int) v[a].size(); i++)
    {
        if (q[p[a][i]]) continue;
        if (v[a][i] == wa) {
            c[p[a][i]] += 20;
            continue;
        }
        if (v[a][i] == ac) {
            q[p[a][i]] = 1;
            c[p[a][i]] += t[a][i];
        }
    }
    int tot = 0, sol = 0;
    for (i = 1; i < 10; i++)
    {
        if (q[i]){
            tot += c[i];
            sol ++;
        }
    }

    b.t = a, b.s = sol, b.p = tot;
    qu.push (b);
    return;
}

int main()
{
    int ti, i, j, k;
    string s, s1;
    char s2 [100];
    memset(att, 0, sizeof(att));

    cin >> ti;
    gets (s2);
    gets (s2);

    while (ti--)
    {
        if (gets (s2) != NULL){
        if (strlen(s2))
        {
            ti ++;
            s1 = s2;
            stringstream ss;
            ss << s1;

            ss >> i;
            ss >> j;
            ss >> k;
            ss >> s;

            att[i] = 1;
            t[i].push_back (k);
            p[i].push_back (j);
            v[i].push_back (s);

            continue;
        }
        else
        {
            for (i= 1; i<101; i++)
                if (att[i])
                    res(i);

            while (!qu.empty())
            {
                cout << qu.top().t << " " << qu.top().s << " " << qu.top().p << endl;
                qu.pop();
            }

            for (i = 0; i <= 100; i++)
            {
                att [i] = 0;
                v[i].clear();
                p[i].clear();
                t[i].clear();
            }
            cout << endl;
            continue;
        }
        }
        else
        {
            for (i= 1; i<101; i++)
                if (att[i])
                    res(i);

            while (!qu.empty())
            {
                cout << qu.top().t << " " << qu.top().s << " " << qu.top().p << endl;
                qu.pop();
            }
            break;
        }
    }

    return 0;
}
