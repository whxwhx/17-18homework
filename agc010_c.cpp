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
const int N = 1e5 + 10;
int n, a[N], t, c[N];
 
struct edge{ int to, pre; }e[N << 1]; int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)
 
int d[N];
bool flag = true;
int r[N], rt;
void dfs(int x, int f) {
	if (d[x] == 1) { r[x] = a[x]; return; }
	LL s = 0; 
	reg(i,x) if (v != f) dfs(v, x), s += r[v];
	if (s < a[x] || s > 2 * a[x]) flag = false;
	r[x] = 2 * a[x] - s; if (x == rt && r[x]) flag = false;
	reg(i,x) if (r[v] > a[x]) flag = false;
}
 
int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	if (n == 2) { printf(a[1] == a[2] ? "YES" : "NO"); return 0; }
	rep(i,1,n - 1) {
		int a, b; scanf("%d%d",&a,&b);
		ins(a, b), ins(b, a);
		d[a]++, d[b]++;
	}
	rt = 0;
	rep(i,1,n) if (d[i] > 1) rt = i;
	dfs(rt, 0);
	printf(flag ? "YES" : "NO");
	return 0;
}