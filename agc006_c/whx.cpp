#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Rep(i,a) for(int i = 0; i < (a); i++)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)//(a)!
#define dep(i,a,b) for(int i = (a); i >= (b); i--)
#define ab(a) ((a) > 0 ? (a) : -(a))
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 100010;
int a[N], ind[N], d[N], c[N], cl = 0;
bool vis[N];
int main() {
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	int m; LL k; scanf("%d%lld",&m,&k);
	rep(i,1,n - 1) ind[i] = i;
	rep(i,1,m) { int x; scanf("%d",&x); swap(ind[x - 1], ind[x]); }
	rep(i,1,n - 1) if (!vis[i]) {
		cl = 0; c[cl++] = i; vis[i] = true;
		for(int x = ind[i]; x != i; x = ind[x]) c[cl++] = x, vis[x] = true;
		rep(j,0,cl - 1) {
			int t = c[(j + k) % cl];
			d[c[j]] = a[t + 1] - a[t];
		}
	}
	LL s = a[1];
	rep(i,1,n) printf("%lld\n",s), s += d[i];
	return 0;
}