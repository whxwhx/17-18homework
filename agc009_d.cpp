#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 100010;
 
struct edge{ int to, pre; }e[N << 1]; int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)
 
int w[N], ans = 0;
void dfs(int x, int f) {
	w[x] = 0; int cnt[19]; rep(i,0,18) cnt[i] = 0;
	reg(i,x) if (v != f) { dfs(v, x); rep(j,0,18) if (w[v] >> j & 1) cnt[j]++; }
	int t = 0; dep(i,18,0) if (!cnt[i]) t = i; else if (cnt[i] >= 2) break;
	ans = max(ans, t);
	w[x] = 1 << t; rep(i,t + 1,18) if (cnt[i]) w[x] |= 1 << i;
}
 
int main() {
	int n; scanf("%d",&n);
	rep(i,1,n - 1) { int a, b; scanf("%d%d",&a,&b), ins(a, b), ins(b, a); }
	dfs(1,0); printf("%d\n",ans);
	return 0;
}