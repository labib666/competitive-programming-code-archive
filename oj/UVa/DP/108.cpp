/*
UVa
DP
108 - MAximum sum
22.1.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int main()
{
    int n,i,j,k;
    int s[100][100], colsum[100][100];

    cin >> n;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            cin >> s[i][j];
    }

    for (i=0; i<n; i++)
    {
        k = 0;
        for (j=0; j<n; j++)
        {
            k += s[j][i];
            colsum[i][j] = k;
        }
    }

    int mx = 0, temp[101];
    for (i = 0; i<n; i++)
    {
        for (k = n-1; k >= i; k--){
        for(j = 0; j<n; j++)
        {
            if (i == 0) temp[j] = colsum[j][k];
            else temp[j] = colsum[j][k] - colsum[j][i-1];
        }
        int sum = 0;
        for (j=0; j<n; j++)
        {
            sum = max(sum + temp[j], 0);
            if (sum > mx) mx = sum;
        }
        }
    }

    cout << mx << endl;

    return 0;
}
