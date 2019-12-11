# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int main ()
{
    char sub[100000], str[100000];
    int i, size, size2, j, check;
    while (scanf ("%s", sub) != EOF)
    {
        scanf ("%s", str);
        size = strlen (sub);
        size2 = strlen (str);

        check = 0;
        j = 0;
        for (i=0;i<size;i++)
        {
            if (i!=0) j++;
            for ( ; j < size2; j++)
            {
                if (sub[i] == str[j]){
                   if (i == size -1) check ++;
                   break;
                }
            }
         }
         if (check == 1) printf ("Yes\n");
         else printf ("No\n");
     }
     return 0;
}
