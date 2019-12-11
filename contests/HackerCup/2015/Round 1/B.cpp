/*
ID: Labib666
LANG: C++
Contest: Hacker Cup Round 1
Task: B
*/

#include <bits/stdc++.h>

using namespace std;

//----------------------------------------------
#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector <int>
#define VLL vector <LL>
#define PQI priority_queue <int>
#define PQLL priority_queue <LL>
#define QI queue <int>
#define QLL queue <LL>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define SZ size()
#define INF 1000000007
#define LINF 1000000000000000007ll
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)
//--------------------------------------------------


struct node
{
	node *next[26+1];
	node()
	{
		for(LL i=0;i<26;i++) next[i]=NULL;
	}
}*root;

LL insert(string str,LL len)
{
	node *curr=root; LL res = len;
	for(LL i=0;i<len;i++)
	{
		LL id=str[i]-'a';
		if(curr->next[id]==NULL)  {
			curr->next[id]=new node();
			res = min (res, i+1);
		}
		curr=curr->next[id];
	}
	return res;
}
void del(node *cur)
{        
      for(LL i=0;i<26;i++)
             if(cur->next[i])
                  del(cur->next[i]) ;
 
         
         delete(cur) ;
}



int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
	freopen ("in.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    
    LL t, tc=0, n, ans = 0, pp;
    string s;
    
    scanf ("%lld", &t);
    while (tc<t) {
		tc++; ans = 0;
		root = new node();
		
		scanf ("%lld", &pp);
		for (LL i=0; i<pp; i++) {
			cin >> s;
			n = s.size();
			
			ans += insert(s,n);
		}
		
		printf ("Case #%lld: %lld\n", tc, ans);
		del(root); 
	}


    return 0;
}
