#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i++)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define x first
#define y second
#define pb(a) push_back(a)
const int N = 2010, mod = 1e9 + 7;
int n, k, f[N][N], fac[N * N], inv[N * N];
int C(int n, int m) { return 1LL * fac[n] * inv[n - m] % mod * inv[m] % mod; }
int pw(int a, int b) { 
	int w = 1; 
	for(;b; b >>= 1, a = 1LL * a * a % mod) 
		if (b & 1) w = 1LL * w * a % mod; 
	return w; 
}
int main() {
	scanf("%d%d",&n,&k);
	if (k == 1) { printf("1\n"); return 0; } 
	f[0][0] = 1;
	fac[0] = 1; rep(i,1,n * k) fac[i] = 1LL * fac[i - 1] * i % mod;
	inv[n * k - 1] = pw(fac[n * k - 1], mod - 2);
	dep(i,n * k - 2,0) inv[i] = 1LL * (i + 1) * inv[i + 1] % mod;

	rep(i,0,n - 1) rep(j,0,n - i) if (f[i][j]) {
		if (j < n) (f[i][j + 1] += f[i][j]) %= mod;
		if (j) f[i + 1][j - 1] = (f[i + 1][j - 1] + 1LL * C(k * (n - i) - j - 1, k - 2) * (n - i) % mod * f[i][j]) % mod; 
	}
	printf("%d\n",f[n][0]);
	return 0;
}