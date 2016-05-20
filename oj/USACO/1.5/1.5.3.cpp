/*
ID: Labib Rashid
LANG: C++
TASK: sprime
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
# include <vector>
# include <string>
# include <sstream>
# define pb push_back

using namespace std;

int p[] = {2,3,5,7}, ara [10001];
string odd[] = {"1", "3", "7", "9"};
vector <int> res [9], test, prime;

inline void sieve ()
{
    int i, j;
    fill (ara, ara + 10001, 1);

    for (i=2;i<=100;i++)
    {
        if (ara[i]){
            prime.pb (i);
            for (j=i; j<=10000/i; j++)
                ara[i*j] = 0;
        }
    }

    for (i=101; i<=10000; i++)
        if (ara[i])
            prime.pb (i);

    return;
}

inline void prod(int len)
{
    int i, j, k;
    string str, str2;
    //test.clear();
    for (i=0; i<(int)res[len-1].size();i++)
    {
        stringstream ss;
        ss << res[len-1][i];
        ss >> str;
        for(j=0;j<4;j++)
        {
            str2 = str + odd[j];
            stringstream ss2;
            ss2 << str2;
            ss2 >> k;
            test.pb (k);
        }
    }
    return;
}

inline void findprime (int len)
{
    int i, j, k, m, check;
    prod (len);
    for (i=0; i< (int)test.size(); i++)
    {
        k = test[i], check = 1;
        for (j=0; j<(int)prime.size(); j++)
        {
            m = k/prime[j];
            if (m < prime[j]) break;
            if ((k%prime[j])) continue;
            check = 0;
            break;
        }
        if (check) res[len].pb(k);
    }
    test.clear();
    return;
}

inline void findres ()
{
    int i;
    for (i=0;i<4; i++) res[1].pb (p[i]);
    sieve();

    for (i = 2; i <9; i++)
        findprime(i);

    return;
}

int main()
{
    int n, i;
    findres();

    freopen ("sprime.in","r", stdin);
    freopen ("sprime.out","w", stdout);

    cin >> n;
    sort (res[n].begin(),res[n].end());
    for (i=0; i<(int)res[n].size(); i++)
        cout << res[n][i] << endl;

    return 0;
}
