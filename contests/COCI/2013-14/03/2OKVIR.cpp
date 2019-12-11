#include <iostream>
using namespace std;
string s[25];
string in[25];

int main() {
	int n, m, u, l , r, d, w, h, i, j, x, y;
	cin >> n >> m;
	cin >> u >> l >> r >> d;
	h = n + u + d;
	w = m + l + r;
	
	for (i = 0; i < n; i++)
		cin >> in[i];
	
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			s[i] += ((i+j)%2==0) ? '#' : '.';
		}
	}
	
	for (i = u, x = 0; x < n; i++, x++)
	{
		for (j = l, y = 0 ; y < m; y++,j++)
		{
			s[i][j] = in[x][y];
		}
	}
	
	for (i = 0; i < h; i++)
		cout << s[i] << endl;
	
	return 0;
}