#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i ++)
using namespace std;
const int N = 4e4 + 10, mod = 998244353;
int n, f[N], fac[N], inv[N], s[N], L;
char a[N], b[N];
int C(int n, int m) {
	return fac[n] * 1LL * inv[n - m] % mod * inv[m] % mod;
}
int pw(int a, int b) { 
	int w = 1; for(;b;b >>= 1, a = 1LL * a * a % mod) if (b & 1) w = 1LL * w * a % mod;
	return w; 
}


int rev[N], w[2][N];
void nttinit(int &n){
	int m = 1, l = 0;
	while (m < n) m <<= 1, l++;
	n = m;
	rep(i,1,n - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
	w[1][n] = pw(3, (mod - 1) >> l);
	dep(i,l - 1,1) w[1][1 << i] = (1LL * w[1][1 << (i + 1)] * w[1][1 << (i + 1)]) % mod;
	w[0][n] = pw(w[1][n], mod - 2);
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
	int invl = pw(l, mod - 2);
	if (!f) Rep(i,l) a[i] = 1LL * a[i] * invl % mod;
}

int t; 
void conv(int a[], int b[], int c[]) {
	static int ta[N], tb[N];
	Rep(i,t) ta[i] = tb[i] = 0;
	Rep(i,L) ta[i] = a[i], tb[i] = b[i];
	fft(ta, t, 1), fft(tb, t, 1);
	Rep(i,t) c[i] = 1LL * ta[i] * tb[i] % mod;
	fft(c, t, -1);
	rep(i,L,t) c[i] = 0;
}

void pw(int a[], int b, int w[]) {
	memset(w, 0, (N - 1) * sizeof(w[0])); w[0] = 1;
	for( ;b; b >>= 1, conv(a, a, a)) if (b & 1) conv(w, a, w);
}

int sc[N], g[N];
void init(int c) {
	L = n + 1; t = L * 2; nttinit(t);
	rep(i,1,n - c + 1) sc[i] = inv[i];
	pw(sc, c, g);
	rep(i,c,n) g[i] = 1LL * g[i] * fac[i] % mod;
}


int count_chain(int c, int m) {
	return g[m + c];
}

int main() {
	scanf("%s",a + 1); scanf("%s",b + 1); n = strlen(a + 1);
	fac[0] = 1; rep(i,1,n) fac[i] = 1LL * i * fac[i - 1] % mod;
	inv[n] = pw(fac[n], mod - 2); dep(i,n - 1,0) inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
	int cnt = 0; rep(i,1,n) if (a[i] != b[i]) cnt++; cnt /= 2;
	int m = 0; rep(i,1,n) if (a[i] == '1') m++; swap(n, m);
	int ans = 0;
	init(cnt);
	rep(i,0,n - cnt) {
		int rest = (n - cnt) - i;
		int cof = 1LL * C(n - cnt, i) * fac[i] % mod * fac[cnt] % mod * fac[n - cnt - i] % mod * count_chain(cnt, n - cnt - i) % mod;
		ans = (ans + 1LL * cof * fac[i] % mod * C(n, i)) % mod;
	}
	if (ans < 0) ans += mod;
	printf("%d\n",ans);
	return 0; 
}