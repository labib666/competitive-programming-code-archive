/*
UVa
Dijkstra
544 - Heavy Cargo
15.1.13
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# include <map>
# include <queue>
# include <vector>

using namespace std;

# define pb push_back

struct edge {
    int u, c;
    bool operator < (const edge &p) const{
        return c < p.c;
    }
};

int x;
map <string,int> tag;

void check (string a)
{
    if (tag[a] == 0){
        tag[a] = x;
        x ++;
    }

    return;
}

int main()
{
    int n, r, i, j, k, start, dest, v, cnt = 0;
    edge ccity;
    int val[201], visited[201];
    vector <int> city[201], cost[201];
    priority_queue <edge> q;
    string name1, name2;

    while (1)
    {
        cnt++;
        x = 1;
        memset (val, 0, sizeof(val));
        memset (visited, 0, sizeof(visited));
        for (i = 0; i <= 200; i++) {
            city[i].clear();
            cost[i].clear();
        }
        while (!q.empty()) q.pop();

        scanf ("%d %d", &n, &r);
        if (n+r == 0) break;

        for (i = 0; i<r; i++)
        {
            cin >> name1 >> name2 >> v;

            check (name1);
            check (name2);

            j = tag[name1];
            k = tag[name2];

            city[j].pb(k);
            city[k].pb(j);

            cost[j].pb(v);
            cost[k].pb(v);
        }

        cin >> name1 >> name2;

        start = tag[name1];
        dest = tag[name2];

        val[start] = 0;
        visited[start] = 1;

        for (i=0; i<city[start].size(); i++)
        {
            ccity.u = city[start][i];
            ccity.c = cost[start][i];
            q.push(ccity);
        }

        while (!q.empty())
        {
            ccity = q.top();
            q.pop();
            j=ccity.u;
            k=ccity.c;

            if(visited[j] == 1) continue;

            visited[j] = 1;
            val[j] = k;

            for (i=0; i<city[j].size(); i++)
            {
                ccity.u = city[j][i];
                ccity.c = min(cost[j][i],k);
                q.push(ccity);
            }
        }

        cout << "Scenario #" << cnt << "\n";
        cout << val[dest] << " tons" << endl << endl;
    }

    return 0;
}
