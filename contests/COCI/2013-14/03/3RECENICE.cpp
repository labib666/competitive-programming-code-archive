/*
ID: Labib Rashid
LANG: C++
TASK:
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
# include <cstring>
# include <queue>

# define ll long long
# define pb push_back
# define x first
# define y second
# define inf 1000000007
# define pi 2*asin(1)
# define PII pair<int,int>
# define VI vector <int>
# define loop(a,s,e) for(a=s;a<e;a++)
# define rloop(a,s,e) for(a=s-1;a>=e;a--)

using namespace std;

ll gcd (ll a, ll b)
{
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

int bitcount (int a)
{
    return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;
}

string dec1[20] = {"",  "one", "two", "three", "four", "five", "six", "seven", "eight","nine", "ten",  "eleven",  "twelve",  "thirteen",  "fourteen",  "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
string dec2[10] = {"", "", "twenty", "thirty", "forty","fifty", "sixty", "seventy", "eighty", "ninety" };
string dec3[10] = {"", "onehundred","twohundred",  "threehundred",  "fourhundred",  "fivehundred",  "sixhundred","sevenhundred", "eighthundred", "ninehundred" };
string s[25], num = "$";
int tot;

bool check (int n)
{
    int sum = 0;
    sum += dec3[n/100].size();
    if (n%100 < 20) sum += dec1[n%100].size();
    else sum += dec2[(n%100 - n%10)/10].size() + dec1[n%10].size();

    if (sum+tot == n) {
    	//cout << n << " " << tot << " " << sum << endl;
    	//cout << dec1[n/100] << " ";
    	//(n%100<20) ? cout << dec[n%100] << endl : cout << dec2[(n%100 - n%10)/10]+dec1[n%10] << endl;
    	return 1;
    }
    return 0;
}

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int n, pos, i, j, k;
    tot = 0;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s[i];
        if (s[i] == num) pos = i;
        else tot += s[i].size();
    }

    for (i = 1; i < 1000; i++)
    {
        if (!check(i)) continue;
        string ans;
        ans += dec3[i/100];
        if (i%100 < 20) ans += dec1[i%100];
        else ans += dec2[(i%100-i%10)/10] + dec1[i%10];
        s[pos] = ans;
        break;
    }

    for (i = 0; i < n; i++)
        (i != n-1) ? cout << s[i] << " " : cout << s[i] << endl;

    return 0;
}
