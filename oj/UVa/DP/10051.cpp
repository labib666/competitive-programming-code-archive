/*
UVa
DP - LIS
10051 - Tower of cubes
6.2.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <string>

using namespace std;

struct two{
    int x, y;
};

int dp [505][6], c [505][6][2];
two mem [505][6];
string s[6] = {"front","back","left","right","top","bottom"};

inline void pseq(two st)
{
    if (st. x == -1) return;

    pseq (mem[st.x][st.y]);
    cout << st.x + 1 << " " << s[st.y] << endl;

    return;
}

int main()
{
    int n, i, j, k, l, cnt = 0;

    while (1)
    {
        cin >> n;
        if (n == 0) break;

        cnt ++;
        if (cnt != 1) cout << endl;
        for (i=0; i<n; i++)
            for (j=0; j<6; j++)
                dp[i][j] = 1;
        memset (mem, 0, sizeof(mem));
        for (i = 0; i < n; i++)
        {
            for (j = 0; j<6; j++) cin >> c[i][j][0];
            for (j = 0; j<6; j++) {
                if (j % 2 == 0) c[i][j][1] = c[i][j+1][0];
                else c[i][j][1] = c[i][j-1][0];
            }
        }

        int mx = 1;
        two start;
        start.x = 0, start.y = 0;
        for (j = 0; j < 6; j++) {
            dp [0][j] = 1;
            mem [0][j].x = -1, mem[0][j].y = -1;
        }
        for (i = 1; i < n; i++)
        {
            for (l = 0; l < 6; l++){
                int res = 1;
                two dest;
                dest.x = -1, dest.y = -1;
                for (j = i - 1; j >= 0; j--)
                {
                    for (k = 0; k<6; k++)
                    {
                        if (c[j][k][1] == c[i][l][0]){
                            if(res < dp[j][k] + 1)
                            {
                                res = dp[j][k] + 1;
                                dest.x = j;
                                dest.y = k;
                            }
                        }
                    }
                }
                dp[i][l] = res;
                mem [i][l] = dest;

                if (mx < res)
                {
                    mx = res;
                    start.x = i, start.y = l;
                }
            }
        }

        printf ("Case #%d\n%d\n", cnt, mx);
        pseq (start);
    }

    return 0;
}
