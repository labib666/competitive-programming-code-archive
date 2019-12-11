/*
USACO
prime + palindrome, NT
1.5.2 - prime palindromes
26.2.2013
/*
ID: Labib Rashid
LANG: C++
TASK: pprime
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

vector <int> prime, res, pal;
int ara [10001], s[] = {0,1,10,100,1000};
string odd[] = {"0","1","2","3","4","5","6","7","8","9"};

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

    for (i=0;;i++)
    {
        if (prime[i] == 11) break;
        res.pb(prime[i]);
    }
    return;
}

inline void ppal (int n)
{
    int k = n/2;
    int i,j,p,q,r,m;
    string str,str1,str2;
    char cstr[8];

    i = s[k];

    for (j=0; j < 5; j++)
    {
        m = i + 2*i*j;
        for (p = m; p < m + i; p++)
        {
            stringstream ss;
            ss << p;
            ss >> str;
            strcpy (cstr, str.c_str());

            reverse (cstr,cstr+k);
            str1 = cstr;

            if (n%2){
            for (r = 0; r < 10; r++)
            {
                stringstream ss2;
                str2 = str + odd[r] + str1;
                ss2 << str2;
                ss2 >> q;
                pal.pb (q);
            }
            }
            else {
                str2 = str + str1;
                stringstream ss2;
                ss2 << str2;
                ss2 >> q;
                pal.pb (q);
            }
        }
    }
    return;
}

inline void findprime()
{
    int i, j, m;
    for (i=0; i<(int)pal.size();i++)
    {
        int k = pal[i], check = 1;
        for (j = 0; j < (int) prime.size(); j++)
        {
            m = k/prime[j];
            if (m < prime[j]) break;
            if ((k%prime[j])) continue;
            check = 0;
            break;
        }
        if (check) res.pb(k);
    }
    return;
}

int main()
{
    freopen ("pprime.in","r", stdin);
    freopen ("pprime.out","w", stdout);

    int a, b, i;
    sieve();
    for (i=2;i<=8;i++) ppal(i);
    findprime();
    sort (res.begin(), res.end());

    cin >> a >> b;

    for (i=0;i < (int)res.size();i++)
    {
        if (res[i] < a) continue;
        else if (res[i] > b) break;
        cout << res[i] << endl;
    }

    return 0;
}
