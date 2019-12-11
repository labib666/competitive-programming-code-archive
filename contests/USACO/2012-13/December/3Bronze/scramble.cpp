/*
ID: Labib Rashid
LANG: C++
TASK: scramble
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# include <list>
# include <algorithm>
# include <utility>
# include <map>


using namespace std;

struct data {
    string x, int y;

    bool operator <(data const& o) const {
        if (x == o.x) {
            if (y > o.y)
                return (!is_rev) && o.is_rev;
        }
        return x < o.x;
    }
};

int main()
{
    int t,i,j,k,x,y;
    char m[20];
    list <string> n1;
    list <string> n2;
    data cow;
    int s1[50000], s2[50000];
    map <string,int> tag;


    freopen ("scramble.in","r",stdin);
    freopen ("scramble.out","w",stdout);

    scanf("%d", &t);
    for(i=0; i<t; i++) {
        scanf ("%s", m);
        k=strlen(m);
        sort (m,m+k);
        tag[m] = i;
        n1.push_front(m);

        reverse (m,m+k);
        tag[m] = i;
        n2.push_front(m);
    }
    n1.sort();
    n2.sort();

    //for(i=0; i<t; i++) {
     //   cout << n1[i] << " " << n2[i] << endl;
    //}

    while (!n1.empty())
    {
        cow.x = n1.top;
        cow.y = 1;
        q
    }

    /*
    x = 1;
    y = 1;

    while (!n1.empty())
    {
        if (n2.front() >= n1.front()) {
            s1[tag[n1.front()]] = y;
            x++;
            n1.pop_front();
        }
        else {
            s2[tag[n2.front()]] = x-1;
            y++;
            n2.pop_front();
        }
    }

    while (!n2.empty()) {
        s2[tag[n2.front()]] = x-1;
        n2.pop_front();
    }
    */

    for(i=0; i<t; i++) printf ("%d %d\n", s1[i], s2[i]);

    return 0;
}
