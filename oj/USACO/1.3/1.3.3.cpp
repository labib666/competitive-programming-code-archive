/*
ID: Labib Rashid
LANG: C++
TASK: calfflac
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <vector>
# include <map>

using namespace std;

int main()
{
    char main [ 20000 ], main2 [20000];
    vector <char> sec;
    map < int , int > mp;
    int i, j, k, size, sz, max, start, end;

    freopen ( "calfflac.txt","r",stdin);
    //freopen ( "calfflac.in","r",stdin);
    //freopen ( "calfflac.out","w",stdout);

    gets (main);
    while (gets (main2)!= NULL){
        strcat(main,"#");
        strcat(main,main2);
    }
        //value = 0;
        sec.clear();
        max = 1;
        //cout << main <<endl;

        for ( i=0; i<strlen(main); i++ )
        {
            if ( main[i] <= 'z' &&main[i]>='a' )  {
                sec.push_back (main[i]);
                sz = sec.size() - 1;
                mp [sz] = i;
                //cout << mp [sz] << "\t" << sz  << "\t" << sec.back() <<  endl;
            }
            else if ( main[i] <= 'Z' &&main[i]>='A' )  {
                sec.push_back ('a'+main[i]-'A');
                sz = sec.size() - 1;
                mp [sz] = i;
                //cout << mp [sz] << "\t" << sz << "\t" << sec.back() <<  endl;
            }
        }
        sz = sec.size() - 1;

        for ( i=0; i<sz-max; i++ )
        {
            for ( size= min(sz-i,1999); size+1>max; size-- )
            {
                //cout << i << " " << size + 1 << endl;
                for ( j=i,k=i+size; j<=(2*i+size)/2; j++,k-- )
                {
                    //cout << sec [j] << sec [k] << endl;
                    if ( sec [k] != sec [j] ) break;
                    else if (j==((2*i+size)/2)) {
                        max = (size+ 1);
                        start = mp [i];
                        end = mp [i+size];
                        //cout << j+1 << sec[k] << " " << sec[j] << k+1 << endl;
                    }
                }
            }
        }
        printf("%d\n",max);
        //cout << start << " " << end << endl;
        for ( i=start; i<= end; i++ ) {
            if (main[i]=='#') printf("\n");
            else printf ( "%c", main[i] );
        }
        printf("\n");
    return 0;
}
