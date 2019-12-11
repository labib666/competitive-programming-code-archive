/*
USACO
3.3.4 - Home on the Range
DP
7.2.2014
/*
ID: Labib Rashid
LANG: C++
TASK: range
*/

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define x first
#define y second
#define inf 1000000007
#define pi 2*asin(1)
#define PII pair<int,int>
#define VI vector <int>
#define eps 1e-9

using namespace std;

string s[255];
int dr[255][255], dd[255][255], n;
int dp[255][255];
VI v;
bool vis[255][255];

int solve (int px, int py)
{
    if (px >= n || py >= n) return 0;
    vis[px][py] = 1;
    dp[px][py] = min(dp[px][py], solve(px+1,py+1)+1);
    return dp[px][py];
}

int main()
{
    //freopen ("range.txt","r",stdin);
    freopen ("range.in","r",stdin);
    freopen ("range.out","w",stdout);

    int i, j, k;

    cin >> n;
    for (i = 0; i < n; i++)
        cin >> s[i];

    for (i = 0; i < n; i++)
    {
        queue <int> q;
        for (j = 0; j < n; j++)
        {
            if (s[i][j] == '1') q.push(1);
            else {
                k = j-q.size();
                while (!q.empty()) {
                    dr[i][k] = q.size();
                    q.pop(); k++;
                }
            }
        }
        k = j-q.size();
        while (!q.empty()) {
            dr[i][k] = q.size();
            q.pop(); k++;
        }
    }

    for (i = 0; i < n; i++)
    {
        queue <int> q;
        for (j = 0; j < n; j++)
        {
            if (s[j][i] == '1') q.push(1);
            else {
                k = j-q.size();
                while (!q.empty()) {
                    dd[k][i] = q.size();
                    q.pop(); k++;
                }
            }
        }
        k = j-q.size();
        while (!q.empty()) {
            dd[k][i] = q.size();
            q.pop(); k++;
        }
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dp[i][j] = min(dd[i][j], dr[i][j]);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (vis[i][j]) continue;
            solve(i,j);
        }
    }

    for (i=0;i<n;i++)
        for(j=0;j<n;j++)
            v.pb (dp[i][j]);

    sort(v.begin(), v.end());

    for (i = 2; i <= n; i++)
    {
        k = v.end() - lower_bound (v.begin(), v.end(), i);
        if (k) cout << i << " " << k << endl;
    }

    return 0;
}
