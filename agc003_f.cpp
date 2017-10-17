#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i++)
using namespace std;
typedef long long LL;
const int N = 1010, mod = 1e9 + 7;
int n, m; LL k;
char s[N][N];

bool check_vertical() {
	rep(i,1,m) if (s[1][i] == '#' && s[n][i] == '#') return true;
	return false;
}

bool check_horizontal() {
	rep(i,1,n) if (s[i][1] == '#' && s[i][m] == '#') return true;
	return false;
}

struct mat{ int a[2][2]; }; 
mat operator * (const mat &a, const mat &b) {
	static mat w;
	Rep(i,2) Rep(j,2) w.a[i][j] = 0;
	Rep(i,2) Rep(j,2) Rep(k,2) w.a[i][k] = (w.a[i][k] + 1LL * a.a[i][j] * b.a[j][k]) % mod;
	return w;
}
mat pw(mat a, LL b) {
	mat w; Rep(i,2) Rep(j,2) w.a[i][j] = (i == j);
	for(;b;b >>= 1, a = a * a) if (b & 1) w = w * a;
	return w;
}

int main() {
	scanf("%d%d%lld",&n,&m,&k);
	rep(i,1,n) scanf("%s",s[i] + 1);
	bool t1 = check_vertical(), t2 = check_horizontal();
	if ((t1 && t2) || (k <= 1)) printf("1\n");
	else {
		int cnt = 0, tot = 0, c2 = 0;
		rep(i,1,m) if (s[1][i] == '#' && s[n][i] == '#') cnt++;
		rep(i,1,n) if (s[i][1] == '#' && s[i][m] == '#') cnt++;

		rep(i,1,n) rep(j,1,m) if (s[i][j] == '#') tot++;

		if (t1) {
			rep(i,2,n) rep(j,1,m) if (s[i - 1][j] == '#' && s[i][j] == '#') 
				c2++;
		} else if (t2) {
			rep(i,1,n) rep(j,2,m) if (s[i][j - 1] == '#' && s[i][j] == '#') 
				c2++;
		}

		mat a; 
		a.a[0][0] = tot, a.a[0][1] = mod - c2;
		a.a[1][0] = 0, a.a[1][1] = cnt;
		a = pw(a, k - 1);
		int ans = (a.a[0][0] + a.a[0][1]) % mod;
		if (ans < 0) ans += mod;
		printf("%d\n",ans);
	}
	return 0;	
}
