#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Rep(i,a) for(int i=0;i<a;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
const int N = (2e5 + 10) * 4, mod = 924844033;
int rev[N], w[2][N], L;
int pow(int a, int b){
	int w = 1;
	for(;b;b >>= 1, a = 1LL * a * a % mod) if (b & 1) w = 1LL * w * a % mod;
	return w;
}
void init(int &n){
	int m = 1, l = 0;
	while (m < n) m <<= 1, l++;
	n = m;
	rep(i,1,n - 1)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
	w[1][n] = pow(5, (mod - 1) >> l);
	dep(i,l - 1,1) w[1][1 << i] = (1LL * w[1][1 << (i + 1)] * w[1][1 << (i + 1)]) % mod;
	w[0][n] = pow(w[1][n], mod - 2);
	dep(i,l - 1,1) w[0][1 << i] = (1LL * w[0][1 << (i + 1)] * w[0][1 << (i + 1)]) % mod;
}
void fft(int *a, int l, int f){
	if (f == -1) f = 0;
	Rep(i,l) if (rev[i] < i) swap(a[i], a[rev[i]]);
	for(int n = 2; n <= l; n <<= 1){
		int mid = n >> 1, wn = w[f][n];
		for(int i = 0; i < l; i += n){
			int w = 1;
			Rep(j,mid){
				int t1 = a[i + j], t2 = 1LL * a[i + j + mid] * w % mod;
				a[i + j] = (t1 + t2) % mod;
				a[i + j + mid] = (t1 - t2) % mod;
				w = 1LL * w * wn % mod;
			}
		}
	}
	int invl = pow(l, mod - 2);
	if (!f) Rep(i,l) a[i] = 1LL * a[i] * invl % mod;
}
int n, a[N], ta[N], b[N], c[N], ans = 0;

struct edge{ int to, pre; } e[N << 1]; int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

int sz[N];
void dfs(int x, int f) {
	sz[x] = 1;
	reg(i,x) if (v != f) dfs(v, x), sz[x] += sz[v];
	if (x != 1) a[min(sz[x], n - sz[x])]++;
}

int pw(int a, int b) {
	int w = 1; 
	for(;b;b >>= 1, a = 1LL * a * a % mod) if (b & 1) w = 1LL * w * a % mod; 
	return w; 
}

int fac[N], inv[N];
void init() {
	fac[0] = 1; rep(i,1,n) fac[i] = 1LL * fac[i - 1] * i % mod;
	inv[n] = pw(fac[n], mod - 2); dep(i,n - 1,0) inv[i] = 1LL * (i + 1) * inv[i + 1] % mod;
}

int C(int n, int m) { 
	if (n < m) return 0;
	else return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
	scanf("%d",&n);
	rep(i,1,n - 1) { int x, y; scanf("%d%d",&x,&y); ins(x, y), ins(y, x); }
	init();
	dfs(1, 0);
	L = n * 2 + 2; init(L);
	rep(i,1,n) ta[i] = 1LL * fac[i] * a[i] % mod, b[i] = inv[n - i];
	fft(ta, L, 1), fft(b, L, 1);
	Rep(i,L) b[i] = 1LL * ta[i] * b[i] % mod;
	fft(b, L, -1);
	memset(ta, 0, sizeof(ta));
	rep(i,1,n) ta[i] = 1LL * fac[i] * a[n - i] % mod, c[i] = inv[n - i];
	fft(ta, L, 1), fft(c, L, 1);
	Rep(i,L) c[i] = 1LL * ta[i] * c[i] % mod;
	fft(c, L, -1);
	rep(k,1,n) {
		int ans = C(n, k) * 1LL * n % mod;
		ans = (ans - 1LL * inv[k] * b[n + k]) % mod;
		ans = (ans - 1LL * inv[k] * c[n + k]) % mod;
		if (ans < 0) ans += mod;
		printf("%d\n",ans);
	}
	return 0;
}