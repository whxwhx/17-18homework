#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long LL;
const int N = 100010, mod = 1e9 + 7;
int f[N][2], s[N][2], n, pa[N], pb[N]; LL a, b, x[N];
int main() {
	cin >>n>>a>>b;
	rep(i,1,n) scanf("%lld",&x[i]);
	pa[1] = 1; rep(i,2,n) pa[i] = (x[i] - x[i - 1] >= a) ? pa[i - 1] : i - 1;
	pb[1] = 1; rep(i,2,n) pb[i] = (x[i] - x[i - 1] >= b) ? pb[i - 1] : i - 1;
	int ra = 1, rb = 1; bool A = true, B = true;
	rep(i,1,n) {
		if (i > 1) { if (x[i] - x[i - 1] < a) A = false; if (x[i] - x[i - 1] < b) B = false; }
		rep(d,0,1) s[i][d] = s[i - 1][d];
		//A
		while (x[i + 1] - x[ra] >= b) ra++;
		int r = ra - 1, l = pa[i];
		if (l <= r) f[i][0] = (s[r][1] - s[l - 1][1]) % mod;
		if (A) f[i][0]++;
		//b
		while (x[i + 1] - x[rb] >= a) rb++;
		r = rb - 1, l = pb[i];
		if (l <= r) f[i][1] = (s[r][0] - s[l - 1][0]) % mod;
		if (B) f[i][1]++;
		//s
		rep(d,0,1) (s[i][d] += f[i][d]) %= mod;
	}
	int ans = (s[n - 1][0] - s[pb[n] - 1][0]) % mod + (s[n - 1][1] - s[pa[n] - 1][1]) % mod;
	ans += A + B;
	ans %= mod; if (ans < 0) ans += mod;
	cout <<ans<<endl;
}