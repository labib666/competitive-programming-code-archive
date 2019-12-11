# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# include <map>

using namespace std;

string name [] = {"Alice", "Betsy", "Corinne", "Debra"};

int main()
{
    int i, m, t;

    map <string,int> tag;
    char n[10], s[50], c;
    int save[4]={0,0,0,0};

    for (i=0; i<4; i++)
        tag[name[i]] = i;

    scanf ("%d", &t);
    for (i=0; i<t; i++)
    {
        scanf ("%s %s", n, s);

        sscanf (s, "%c %d", &c, &m);

        if (c == '+') save[tag[n]] += m;
        else save[tag[n]] -= m;
    }

    for (i=0; i<4; i++)
        cout << name[i] << " " << save[i] << endl;

    return 0;
}

