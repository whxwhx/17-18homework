//C(a[i] + a[j] + b[i] + b[j], a[i] + a[j])
//(-a[i], -b[i])->(a[j], b[j])
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
typedef pair<int, int> pii;
#define x first
#define y second
const int N = 4010, mod = 1e9 + 7;
int n, a[int(2e5) + 10], b[int(2e5) + 10], f[N][N], fac[2 * N], inv[2 * N];
int C(int n, int m) { return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod; }
int pw(int a, int b) { int w = 1; for(;b;b >>= 1, a = 1LL * a * a % mod) if (b & 1) w = 1LL * w * a % mod; return w; }
int main() {
	fac[0] = 1; rep(i,1,2 * N - 5) fac[i] = 1LL * i * fac[i - 1] % mod;
	inv[2 * N - 5] = pw(fac[2 * N - 5], mod - 2); dep(i,2 * N - 6,0) inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
	scanf("%d",&n);
	rep(i,1,n) scanf("%d%d",a + i, b + i);
	rep(i,1,n) f[2001 - a[i]][2001 - b[i]]++;
	rep(i,1,N - 5) rep(j,1,N - 5) 
		f[i][j] = ((f[i][j] + f[i - 1][j]) % mod + f[i][j - 1]) % mod;
	int ans = 0;
	rep(i,1,n) ans = (ans + f[2001 + a[i]][2001 + b[i]]) % mod;
	rep(i,1,n) ans = (ans - C(2 * a[i] + 2 * b[i], 2 * a[i])) % mod;
	if (ans < 0) ans += mod;
	printf("%lld\n",1LL * ans * pw(2, mod - 2) % mod);
	return 0;
}
