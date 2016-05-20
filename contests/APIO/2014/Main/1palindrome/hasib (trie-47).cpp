/**
   __      __            ______             _________     __     ______
  |  |    |  |          /  __  \           /   _____ \   |  |   |   __  \
  |  |    |  |         /  /  \  \          |  |     \/   |  |   |  |  \  \
  |  |    |  |        /  /    \  \         |  |          |  |   |  |   \  \
  |  |____|  |       /  /######\  \        |  |______    |  |   |  |___*  /
  |   ____   |      /              \       |______   |   |  |   |   ___  X
  |  |    |  |     /  /##########\  \             |  |   |  |   |  |   *  \
  |  |    |  |    /  /            \  \            |  |   |  |   |  |   /  /
  |  |    |  |   /  /              \  \   /\______|  |   |  |   |  |__/  /
  |__|    |__|   \_/                \_/   \__________|   |__|   |_______/


**/



#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
#define dump(x) cout<<#x<<" = "<<x<<endl

using namespace std;

#define take(args...) asdf,args

struct ASDF{
    ASDF& operator,(int &a) {
        sf("%d", &a);
        return *this;
    }
    ASDF& operator,(long int &a){
        sf("%ld", &a);
        return *this;
    }
    ASDF& operator,(long long int &a){
        sf("%lld", &a);
        return *this;
    }
    ASDF& operator,(char &c){
        sf("%c", &c);
        return *this;
    }
    ASDF& operator,(double &d){
        sf("%lf", &d);
        return *this;
    }

    template<typename T>
    ASDF& operator,(T &a){
        cin>>a;
        return *this;
    }
}asdf;


template<typename T>
ostream& operator<<(ostream& output, vector<T>&v)
{
    output<<"[ ";
    if(SZ(v))
    {
        output<<v[0];
    }
    FOR(i, 1, SZ(v))
    {
        output<<", "<<v[i];
    }
    output<<" ]";
    return output;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& output, pair<T1, T2>&p)
{
    output<<"( "<<p.fr<<", "<<p.sc<<" )";
    return output;
}


//Header ends here


struct DATA{
    int count;
    DATA *child[26];
    DATA()
    {
        count = 0;
        mem(child, 0);
    }
};

ll mxResult = 0;

int xtra;

void recurse(DATA *node, int len)
{
    //dump(len);
    mxResult = max(mxResult, (ll)node->count*((ll)len*2 + xtra ));

    for(int i=0; i<26; i++)
    {
        if(node->child[i] != NULL)
        {
            recurse(node->child[i], len+1);
        }
    }

    delete node;

}



int main()
{
    read("palindrome.in");
    write("palindrome.out");


    string ss;

    cin>>ss;

    DATA *root = new DATA();
    DATA *now;

    char ch;

    for(int i=0; i<SZ(ss); i++)
    {
        int p, q;
        p = q = i;
        now = root;

        while(-1 < p && q < SZ(ss) && ss[p] == ss[q])
        {
            ch = ss[p] - 'a';

            if(now->child[ch] == NULL)
            {
                now->child[ch] = new DATA();
            }
            now = now->child[ch];
            now->count++;

            p--, q++;
        }
    }




    xtra = -1;

    recurse(root, 0);




    root = new DATA();

    for(int i=1; i<SZ(ss); i++)
    {
        int p, q;
        p = i-1;
        q = i;
        now = root;

        while(-1<p && q<SZ(ss) && ss[p] == ss[q])
        {
            ch = ss[p] - 'a';
            if(now->child[ch] == NULL)
            {
                now->child[ch] = new DATA();
            }

            now = now->child[ch];
            now->count++;

            p--, q++;

        }
    }



    xtra = 0;

    //cerr<<"starting another recurse"<<endl;


    recurse(root, 0);



    cout<<mxResult<<endl;












}
