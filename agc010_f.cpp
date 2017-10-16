#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 3010;
int n, a[N];

struct edge { int to, pre; } e[N << 1]; int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

bool f[N];
void dfs(int x, int fa) {
	f[x] = false;
	reg(i,x) if (v != fa) {
		dfs(v, x);
		if (a[v] < a[x] && !f[v]) f[x] = true;
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a + i);
	rep(i,1,n - 1) {
		int a, b; scanf("%d%d",&a,&b);
		ins(a, b), ins(b, a);
	}
	rep(i,1,n) { dfs(i, 0); if (f[i]) printf("%d ",i); }
	printf("\n");
	return 0; 
}