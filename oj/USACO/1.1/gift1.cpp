/*
ID: Labib Rashid
LANG: C++
TASK: gift1
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <vector>
# include <map>

using namespace std;

int main()
{
    char name[20], dummy, name2[20];
    map < *char , int > mp;
    int n, i, j, r, mon, frn, gift;
    vector  < *char > names;

    //freopen ( "gift1.in","r",stdin);
    //freopen ( "gift1.out","w",stdout);

    cin >> n;
    int money [n];
    memset ( money, 0, sizeof(money));

    for ( i=0; i<n; i++ )
    {
        gets (name);
        names.push_back(name);
        mp [name] = i;
    }

    for ( i=0; i<n; i++ ) cout << mp [names[i]] << endl;

    /*for ( i=0; i<n; i++ )
    {
        gets (name);
        scanf ( "%d %d", &mon, &frn);
        gets (dummy);

        if ( frn != 0 )
        {
            r = mon % frn;

            gift = (mon - r)/frn;

            money [mp[name]] = -gift*frn + r;

            for ( j=0; j<frn; j++ )
            {
                gets ( name2 );
                money [mp[name2]] += gift;
            }
        }
        else if ( money !=0 ) money [mp[name]] += mon;
    }

    for ( i=0; i<n; i++ )
    {
        printf ( "%s %d\n", names[i], money[mp[names[i]]]);
    }*/

    return 0;
}
