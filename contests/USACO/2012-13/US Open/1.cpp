/*
ID: Labib Rashid
LANG: C++
TASK: gravity
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <queue>

using namespace std;

struct two {
    int px, py, pg, pa;

    bool operator < (const two &p) const {
        return pa > p.pa;
    }
};

string s[505];
int v[505][505][2], n;
priority_queue <two> q;

void makemove (int px, int py, int pg, int pa) {
    int i;
    two t1;

    if (pg) {
        for (i = px+1; i < n; i++) {
            if (s[i][py] == '#')
                break;
        }

        if (i == n || s[i-1][py] == '#')
            return;

        t1.px = i-1, t1.py = py, t1.pg = pg, t1.pa=pa;
        q.push (t1);
    }
    else {
        for (i = px-1; i >= 0; i--)
            if (s[i][py] == '#')
                break;

        if (i == -1|| s[i+1][py] == '#')
            return;

        t1.px = i+1, t1.py = py, t1.pg = pg, t1.pa = pa;
        q.push (t1);
    }
    return;
}

int main()
{
    int m, i, j, k;
    two t1, t2, c, d;

    freopen ("gravity.txt","r",stdin);
    //freopen ("gravity.out","w",stdout);

    cin >> n >> m;
    for (i=0; i<n; i++)
    {
        cin >> s[i];

        for (j=0; j<m; j++){

            if (s[i][j] == 'C')
                c.px = i, c.py = j;

            if (s[i][j] == 'D')
                d.px = i, d.py = j;
        }
    }

    memset (v, 0, sizeof(v));

    int fail = 1;
    c.pg = 1, c.pa = 0;

    q.push (c);

    while (!q.empty())
    {
        t1 = q.top ();
        q.pop();

        //cout << t1.px << " " << t1.py << endl;

        if (t1.px == d.px && t1.py == d.py) {
            fail = 0;
            break;
        }
        if (v[t1.px][t1.py][t1.pg])
            continue;

        v[t1.px][t1.py][t1.pg] = 1;

        if (t1.py != n-1) makemove (t1.px, t1.py + 1, t1.pg, t1.pa);
        if (t1.py != 0) makemove (t1.px, t1.py - 1, t1.pg, t1.pa);
        makemove (t1.px, t1.py, (t1.pg+1)%2, t1.pa+1);
    }

    if (!fail) cout << t1.pa << endl;
    else cout << -1 << endl;

    return 0;
}
