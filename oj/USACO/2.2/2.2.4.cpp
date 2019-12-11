/*
USACO
complete search
2.2.4 - party lamps
31.3.2013
*/
/*
ID: Labib Rashid
LANG: C++
TASK: lamps
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

vector <int> on, off;
vector <string> ans;
string lamp;
int c[5], n, cnt;

void chk (int k)
{
    if (k > cnt || (k%2) != (cnt%2))
        return;

    int i, fail = 0;

    for (i = 0; i < (int) on.size(); i++)
        if (lamp[on[i]] != '1') fail = 1;
    for (i = 0; i < (int) off.size(); i++)
        if (lamp[off[i]] != '0') fail = 1;

    if (fail) return;
    ans.push_back (lamp);
    return;
}

void gen (int a) {
    int i, j, k;

    if (a == 0) {
        lamp.clear();
        for (i=0; i <= n; i++)
            lamp += '1';

        if (c[1]) {
            for (i = 1; i <= n; i++){
                if (lamp[i] == '1')
                    lamp[i] = '0';
                else
                    lamp[i] = '1';
            }
        }
        if (c[2]) {
            for (i = 1; 2*i - 1 <= n; i++){
                if (lamp[2*i - 1] == '1')
                    lamp[2*i - 1] = '0';
                else
                    lamp[2*i - 1] = '1';
            }
        }
        if (c[3]) {
            for (i = 1; 2*i <= n; i++){
                if (lamp[2*i] == '1')
                    lamp[2*i] = '0';
                else
                    lamp[2*i] = '1';
            }
        }
        if (c[4]) {
            for (i = 0; 3*i + 1 <= n; i++){
                if (lamp[3*i + 1] == '1')
                    lamp[3*i + 1] = '0';
                else
                    lamp[3*i + 1] = '1';
            }
        }

        chk (c[1]+c[2]+c[3]+c[4]);
        return;
    }

    c[a] = 1;
    gen (a-1);

    c[a] = 0;
    gen (a-1);

    return;
}

int main ()
{
    int i, j, k;

    freopen ("lamps.in", "r", stdin);
    freopen ("lamps.out", "w", stdout);

    cin >> n >> cnt;

    while (1)
    {
        cin >> i;
        if (i == -1)
            break;
        on.push_back (i);
    }
    while (1)
    {
        cin >> i;
        if (i == -1)
            break;
        off.push_back (i);
    }

    memset (c, 0, sizeof (c));
    gen (4);

    if ((int)ans.size() == 0){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    sort (ans.begin(), ans. end());
    for (i = 0; i < (int) ans.size(); i++){
        for (j = 1; j <= n; j++) cout << ans[i][j];
        cout << endl;
    }

    return 0;
}


