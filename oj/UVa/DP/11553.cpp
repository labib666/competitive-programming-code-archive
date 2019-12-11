# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>

using namespace std;

int dp [260][260], k1, k2, n;
int choc [10][10];

int findres (int mask1, int mask2, int len)
{
    cout << mask1 << " & " << mask2 << " & " << len << endl;

    if (len == 0)
        return 0;

    if (dp[mask1][mask2] != -1)
        return dp[mask1][mask2];

    int i, j, c1, c2, c3, c4, cost, a, b;
    int nchoc [2][10];

    if ((n - len)%2) // wants to minimize
        cost = 0x33333333;
    else // wants to maximize
        cost = -0x33333333;

    for (i = 1; i <= n; i++) { // trying all row
        if (1 & mask1 >> i) continue;

        mask1 |= (1 << i); // taking from row i-1
        c1 = 0; // points to be earned taking this row
        for (a=0; a<n; a++) {
            c1 += choc[i-1][a];
            nchoc [0][a] = choc [i-1][a];
            choc[i-1][a] = 0;
        }

        if ((n - len)%2) //wants to maximize
            c4 = 0x33333333;
        else //wants to minimize
            c4 = -0x33333333;

        for (j = 1; j <= n; j++) { // trying all col
            if (1 & mask2 >> j) continue;

            mask2 |= (1 << j); //taking from col j-1
            c2 = 0; // points to be earned taking this col
            for (a=0; a<n; a++) {
                c2 += choc[a][j-1];
                nchoc [1][a] = choc [a][j-1];
                choc[a][j-1] = 0;
            }

            c3 = findres (mask1, mask2, len-1); //what do we get??

            if ((n - len)%2)
                if (c3 + (-1)*c2 > c4) c4 = c3 + (-1)*c2; //maximizing
            else
                if (c3 + c2 < c4) c4 = c3 + c2; //minimizing

            // fixing column
            mask2 &= (~(1 << j));
            for (a=0; a<n; a++)
                choc [a][j-1] = nchoc [1][a];
        }

        // min-max cost
        if ((n - len)%2) // if opposite
            if (cost > (-1)*c1 + c4) cost = (-1)*c1 + c4;
        else // if same
            if (cost < c1 + c4) cost = c1 + c4;

        // fixing row
        mask1 &= (~(1 << i));
        for (a=0; a<n; a++)
            choc [i-1][a] = nchoc [0][a];
    }

    dp[mask1][mask2] = cost; // final cost for p1
    cout << cost << " " << mask1 << " " << mask2 << endl;
    return cost;
}

int main()
{
    int t, i, j, k, msk1, msk2;

    cin >> t;
    while (t--){
        cin >> n;

        msk1 = msk2 = 1;

        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                cin >> choc[i][j];

        memset (dp, -1, sizeof (dp));

        int ans = findres (msk1, msk2, n);

        cout << ans << endl;
    }

    return 0;
}
