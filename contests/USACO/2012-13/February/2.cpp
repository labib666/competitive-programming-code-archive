/*
ID: Labib Rashid
LANG: C++
TASK: crossings
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <queue>

using namespace std;

struct two1 {
    int c, p;
    bool operator < (const two1 &s) const {
        if (p == s.p)
            return c < s.c;
        else return p > s.p;
    }
};
struct two2 {
    int c, p;
    bool operator < (const two2 &s) const {
        if (p == s.p)
            return c > s.c;
        else return p > s.p;
    }
};

int val[100005];
priority_queue <two1> q1;
priority_queue <two2> q2;

void process (int c1)
{
    two2 t2;
    int c2;
    while (1)
    {
        t2 = q2.top();
        q2.pop();

        c2 = t2.c;

        if (c1 != c2) {
            val [c2] = 1;
            continue;
        }

        val [c2] = 1;
        break;
    }
    return;
}

int main()
{
    int n, i, j, k;
    two1 t1;
    two2 t2;

    freopen ("crossings.in","r",stdin);
    freopen ("crossings.out","w",stdout);

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> j >> k;
        t1.c = t2.c = i;
        t1.p = j, t2.p = k;
        q1.push (t1);
        q2.push (t2);
    }

    memset (val, 0, sizeof (val));
    while (!q1.empty())
    {
        t1 = q1.top();
        q1.pop();
        if (val[t1.c])
            continue;
        if (q2.top().c == t1.c) {
            q2.pop();
            continue;
        }
        process (t1.c);
    }
    int ans = n;
    for (i = 0; i < n; i++)
        ans -= val[i];

    cout << ans << endl;

    return 0;
}
