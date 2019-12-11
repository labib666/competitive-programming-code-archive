/*
UVa
DS
514 - rails
9.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <stack>

using namespace std;

stack <int> q;

inline void pint (int a, int b)
{
    for (int i = a; i <= b; i++)
        q.push(i);
    return;
}

int main()
{
    int n, i, j, cur, ans;
    int out [1005];

    while (1)
    {
        cin >> n;
        if (n == 0) break;

        while (1)
        {
            cin >> out[0];
            if (out[0] == 0) break;

            for (i=1; i<n; i++)
                cin >> out[i];

            cur = 0, ans = 1;
            for (i=0; i<n; i++) {
                if (cur < out[i]){
                    pint (cur+1, out[i]);
                    cur = out[i];
                }
                if (q.top() == out[i]) {
                    q.pop();
                    continue;
                }
                else {
                    ans = 0;
                    break;
                }
            }
            if (ans) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << endl;
    }

    return 0;
}
