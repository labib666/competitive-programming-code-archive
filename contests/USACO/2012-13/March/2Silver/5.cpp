/*
ID: Labib Rashid
LANG: C++
TASK: painting
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <queue>
# include <vector>
# include <algorithm>

using namespace std;

struct go {
    int c, id, s;
    bool operator < (const go &p) const {
        if (c == p.c) {
            return s > p.s;
        }
        else return c > p.c;
    }
};

priority_queue <go> q1,q2;
vector <int> line, a[50005];

bool bs (int c, int b) {
    bool ans = false;
    int hi, lo , mid;
    hi = (int) a[b].size() - 1;
    lo = 0;

    while (hi >= lo)
    {
        mid = (hi+lo)/2;

        if (a[b][mid] > c) hi = mid - 1;
        else if (a[b][mid] < c) lo = mid + 1;
        else {
            ans = true;
            break;
        }
    }
    return ans;
}

int main()
{
    int n, i, x1, y1, x2, y2, j, k, l, ans;
    go g1, g2;

    freopen ("painting.in" , "r" , stdin);
    freopen ("painting.out", "w" , stdout);

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        g1.c = x1, g1.id = i, g1.s = 1;
        g2.c = x2, g2.id = i, g2.s = 2;
        q1.push (g1);
        q1.push (g2);
        g1.c = y1, g1.id = i, g1.s = 1;
        g2.c = y2, g2.id = i, g2.s = 2;
        q2.push (g1);
        q2.push (g2);
    }

    while (!q1.empty())
    {
        g1 = q1.top();
        q1.pop();

        if (g1.s == 1)
            line.push_back(g1.id);

        else {
            for (i = 0; i < (int)line.size(); i++)
            {
                if (line[i] == g1.id) {
                    line.erase(line.begin() + i);
                    break;
                }
                a[g1.id].push_back (line[i]);
            }
        }
    }
    for (i = 0; i < n; i++)
        sort (a[i].begin(), a[i].end());

    ans = n;
    while (!q2.empty()) {
        g1 = q2.top();
        q2.pop();

        if (g1.s == 1)
            line.push_back(g1.id);

        else {
            int cont = 0, fail = 0;
            for (i=0; i < (int)line.size(); i++)
            {
                if (line[i] == g1.id) {
                    line.erase(line.begin() + i);
                    break;
                }
                if (cont) continue;
                else {
                    if (bs (line[i],g1.id) == true) {
                        fail = 1;
                        cont = 1;
                    }
                }
            }
            if (fail) ans --;
        }
    }
    cout << ans << endl;
    return 0;
}

