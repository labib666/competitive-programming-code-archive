/*
ID: Labib Rashid
LANG: C++
TASK: ride
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int main ()
{
    char com[ 10 ], team [ 10 ];
    int i, product1, product2;
    product1 = product2 = 1;

    freopen ( "ride.in","r",stdin);
    freopen ( "ride.out","w",stdout);

    gets (com);
    gets (team);

    for ( i=0; i<strlen(com); i++ ) {
        product1 *= (com[i] - 'A' + 1);
        product1 = product1 % 47;
        //cout << product1 << " " << team[i] - 'A' + 1 << endl;
    }
    for ( i=0; i<strlen(team); i++ ) {
        product2 *= (team[i] - 'A' + 1);
        product2 = product2 % 47;
        //cout << product2 << " " << team[i] - 'A' + 1 << endl;
    }


    if ( product1 == product2 ) cout << "GO\n";
    else cout << "STAY\n";

    return 0;
}
