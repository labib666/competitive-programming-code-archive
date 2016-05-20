# include <stdio.h>
# include <iostream>
# include <string.h>
# include <vector>
# include <algorithm>
# include <set>
# define ll long long

using namespace std;

struct neweve{
    int g,t;
    ll p;

    bool operator < (const neweve &k) const {
        if(g == k.g){
            if(t!=k.t)
                return t>k.t;
            else return p < k.p;
        }
        else return g > k.g;
    }
};

neweve eve[200005];

int main()
{
    int i;
    int n,m,count = 0;
    ll sol = 0;
    scanf("%d %d",&n,&m);

    multiset <ll> s;
    multiset <ll> ::iterator it;
    s.clear();

    for(i = 0; i < n; i++){
        cin >> eve[i].p >> eve[i].g;
        eve[i].t = 0;
    }

    for(i = 0 ; i < m; i++){
        cin >> eve[i+n].p >> eve[i+n].g;
        eve[i+n].t = 1;
    }
    sort(eve, eve+m+n);
    // sorting things


    for(i = 0; i < m+n; i++)
    {
        if(eve[i].t == 1)
            s.insert(eve[i].p);
            // got a grass

        if(eve[i].t == 0)
        {
            it = s.lower_bound(eve[i].p); // have i got what it takes
            if(it == s.end())
                continue;
            sol = sol + *it;
            s.erase(it);
            count++;
        }
    }

    if(count != n)
        sol = -1;

    cout << sol << endl;

    return 0;
}
