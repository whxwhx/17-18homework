#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
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

const int N = 2010;

int n, a[N], d[N];
struct edge{ int to, pre; } e[(N * N) << 1]; int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; d[b]++; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)
priority_queue<pii> q;
void topsort() {
	rep(i,1,n) if (!d[i]) q.push(mp(a[i], i));
	while (!q.empty()) {
		int x = q.top().second; q.pop(); printf("%d ",a[x]);
		reg(i,x) {
			d[v]--;
			if (!d[v]) q.push(mp(a[v], v));
		}
	}
	printf("\n");
}

int c[N][N]; bool vis[N];
void dfs(int x) {
	vis[x] = true;
	vector<pii> ch;
	rep(i,1,n) if (c[x][i] && !vis[i]) ins(x, i), dfs(i);
}

void build() {
	sort(a + 1, a + n + 1);
	rep(i,1,n) rep(j,1,n) c[i][j] = (gcd(a[i], a[j]) > 1);
	rep(i,1,n) if (!vis[i]) dfs(i);
}

int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d", a + i);
	build();
	topsort();
	return 0;
}