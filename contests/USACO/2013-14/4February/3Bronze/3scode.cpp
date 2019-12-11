/*
ID: Labib Rashid
LANG: C++
TASK: scode
*/

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

#define inf 2014
using namespace std;

char s[102], rs[102];
int n, dp[102][102];

int solve (int a, int b) {
    if (a >= b) return 0;
    if (a+1 == b) return 1;

    int &ret = dp[a][b], KMP[102];
    if (ret != -1) return ret;

    ret = 1;

    // ***###---------               (remove from the beginning)

    KMP[a] = KMP[a+1] = a;
    for (int i=a+1; i<=b; i++) {
        if (i>a+1) {
        int k = KMP[i-1];
            while (1) {
                if (s[k] == s[i-1]) {KMP[i] = k+1; break;}
                else if (k == a) {KMP[i] = a; break;}
                else k = KMP[k];
            }
        }
        if (i == b) continue;
        int k = KMP[i];
        while (1) {
            if (s[k] == s[i]) {
                if (2*(k-a+1) == (i-a+1))
                    ret = (ret + solve(k+1,b))%inf;
            }
            if (k == a) break;
            else k = KMP[k];
        }
    }

    // ***----------###               (remove from two ends)

    int k = KMP[b];
    while (1) {
        if (2*(k-a+1) >= (b-a+1)) {k = KMP[k]; continue;}
        if (s[k] == s[b]) {
                ret = (ret + solve(k+1,b))%inf;
                ret = (ret + solve(a,b-(k-a)-1))%inf;
        }
        if (k == a) break;
        else k = KMP[k];
    }

    // ---------***###                  (remove from the end)

    KMP[n-b-1] = KMP[n-b] = n-b-1;
    for (int i=n-b; i<n-a-1; i++) {
        if (i > n-b) {
            int k = KMP[i-1];
            while (1) {
                if (rs[k] == rs[i-1]) {KMP[i] = k+1; break;}
                else if (k == n-b-1) {KMP[i] = n-b-1; break;}
                else k = KMP[k];
            }
        }
        int k = KMP[i];
        while (1) {
            if (rs[k] == rs[i]) {
                if (2*(k-(n-b-1)+1) == (i-(n-b-1)+1))
                    ret = (ret + solve(a,b-(k-(n-b-1)+1)))%inf;
            }
            if (k == n-b-1) break;
            else k = KMP[k];
        }
    }

    return ret;
}

int main()
{
    //freopen ("3_Sil_3_Bro_scode.txt","r",stdin);
    freopen ("scode.in","r",stdin);
    freopen ("scode.out","w",stdout);

    cin >> s;
    n = strlen(s);

    strcpy(rs, s);
    reverse (rs, rs+n);

    memset(dp, -1, sizeof (dp));
    cout << solve (0,n-1)-1 << endl;


    return 0;
}
