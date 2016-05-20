/*
UVa
DP - big int fibonacci
495 - fibonacci freeze
4.2.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int dp[5001][5001], check[5001];

void add (int p, int c1, int c2)
{
    int c = 0, sum, i;
    for(i=0;i<5001;i++)
    {
        sum = dp[c1][i]+ dp[c2][i]+ c;
        dp[p][i] = sum%10;
        c = sum/10;
    }
    return;
}

void fn(int a)
{
    if (check[a] == 1) return;

    check[a]++;

    fn(a-1);
    fn(a-2);

    add(a,a-1,a-2);

    return;
}

int main()
{
    int n;
    memset(dp, 0, sizeof(dp));
    memset (check, 0, sizeof(check));

    check[0] = check[1] = check[2] = 1;
    dp[1][0] = dp[2][0] = 1;
    dp[0][0] = 0;
    fn (5000);

    int i;
    while (scanf("%d", &n)!=EOF)
    //for (n=0;n<=50;n++)
    {
        if(n==0){
            cout << "The Fibonacci number for " << n << " is 0\n" ;
            continue;
        }

        cout << "The Fibonacci number for " << n << " is " ;
        int c = 0;

        for (i=5000; i>=0; i--)
        {
            if(dp[n][i] > 0 && c == 0)
                c = 1;

            if (c == 1) cout << dp[n][i];
        }
        cout << endl;
    }

    return 0;
}
