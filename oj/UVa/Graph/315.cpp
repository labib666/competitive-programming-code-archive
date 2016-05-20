/*
UVa
graph
315 - networks
2.4.2013
*/

# include <cstdio>
# include <cstring>
# include <sstream>
# include <string>
# include <iostream>
# include <vector>

using namespace std;

vector <int> e[105];
int v[105];

void dfs (int a, int b)
{
    int i, j, k;

    v[a] = 1;
    for (i = 0; i < (int) e[a].size(); i++)
    {
        j = e[a][i];
        if (v[j] || b == j)
            continue;
        dfs (j, b);
    }
    return;
}

int main (){
    int n, i, j, k;
    string s, z = "0";
    char s1 [500];

    while (1)
    {
        cin >> n;
        if (!n) break;
        gets (s1);

        while (1){
            gets (s1);
            s = s1;
            if (s == z) break;

            stringstream ss;
            ss << s;
            ss >> j;
            while (ss >> k) {
                e[j].push_back (k);
                e[k].push_back (j);
            }
        }

        int ans = 0;
        for (i = 1; i <= n; i++)
        {
            memset (v, 0, sizeof (v));

            if (i == 1) dfs (2, 1);
            else dfs (1, i);

            int sum = 0;
            for (j = 1; j <= n; j++)
                sum += v[j];

            if (sum < n - 1)
                ans++;
        }

        cout << ans << endl;

        for (i = 1; i <= n; i++)
            e[i].clear ();
    }

    return 0;
}
