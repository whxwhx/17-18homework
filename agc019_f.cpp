#include <iostream>
#include <cstdio>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 1e6 + 10, mod = 998244353;
int fac[N], inv[N];
int pw(int a, int b) { 
	int w = 1; 
	for(;b;b >>= 1, a = 1LL * a * a % mod) if (b & 1) w = 1LL * w * a % mod; 
	return w; 
}
int C(int n, int m) {
	return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
	int n, m; scanf("%d%d",&n,&m);
	if (n < m) swap(n, m);
	fac[0] = 1; rep(i,1,N - 10) fac[i] = 1LL * fac[i - 1] * i % mod;
	inv[N - 10] = pw(fac[N - 10], mod - 2); 
	dep(i,N - 11,0) inv[i] = 1LL * (i + 1) * inv[i + 1] % mod;
	int ans = n, d = pw(C(n + m, n), mod - 2);
	rep(i,1,m)
		ans = (ans + 1LL * C(n + m - 2 * i, n - i) * C(2 * i - 1, i) % mod * d) % mod;
	printf("%d\n",ans);
	return 0;
}