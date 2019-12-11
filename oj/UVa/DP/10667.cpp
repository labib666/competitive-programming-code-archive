/*
UVa
DP - Max Sum
10667 - largest block
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>

using namespace std;

int grid[105][105];
int colsum[105][105];
int temp [105];

int main()
{
    int t, i, s, b, r1, r2, c1, c2, j, k, l, max, w, h;

    cin >> t;
    for (i=0; i<t; i++)
    {
        memset (grid, 0, sizeof(grid));
        max = 0;

        cin >> s >> b;

        for (j=0; j<b; j++)
        {
            cin >> r1 >> c1 >> r2 >> c2;

            if (r1 > r2) swap(r1, r2);
            if (c1 > c2) swap (c1, c2);

            for (k=r1; k<= r2; k++)
                for (l=c1; l<=c2; l++)
                    grid[k][l] = 1;
        }

        for (k=1; k<= s; k++)
            for (l=1; l<=s; l++)
                colsum[k][l] = grid[l][k] + colsum [k][l-1];

        for (j=1;j<=s; j++)
        {
            for (k=s; k>=j;k--)
            {
                for (l=1; l<=s; l++)
                    temp[l] = colsum[l][k] - colsum[l][j-1];

                h = k - j + 1;
                w = 0;
                for (l=1; l<=s; l++)
                {
                    if (temp[l] == 0) w++;
                    else w = 0;

                    if (h*w > max) max = h*w;
                }
            }
        }

        cout << max << endl;
    }
    return 0;
}
