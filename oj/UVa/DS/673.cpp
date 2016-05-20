/*
UVa
DS
673 - parentheses balance
13.3.2013
*/

# include <cstdio>
# include <iostream>
# include <stack>
# include <cstring>

using namespace std;

stack <int> q;
int main()
{
    int t, i, cancel;
    char s[150];

    cin >> t;
    gets (s);
    while (t--)
    {
        gets(s);
        cancel = 0;
        for (i = 0; i < (int)strlen(s); i++) {
            if (s[i] == '(') q.push(1);
            else if (s[i] == '[') q.push(2);
            else {
                if (s[i] == ')'){
                    if (q.empty() || q.top() != 1) {
                        cancel = 1;
                        break;
                    }
                    else q.pop();
                }
                if (s[i] == ']'){
                    if (q.empty() || q.top() != 2) {
                        cancel = 1;
                        break;
                    }
                    else q.pop();
                }
            }
        }
        if (!q.empty()) cancel = 1;
        while (!q.empty()) q.pop();
        if (cancel) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}
