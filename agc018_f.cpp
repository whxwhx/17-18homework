#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 2e5 + 10, M = 1e6 + 10;
int n, a[N], b[N];

struct edge{ int to, pre; } e[M << 1]; int u[N], l = 1;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

int da[N], db[N];

void insert(int a, int b) { ins(a, b), ins(b, a); }

int vis[M];
void dfs(int x) {
	for(int &i = u[x]; i; i = e[i].pre) {
		if (vis[i >> 1]) continue;
		vis[i >> 1] = i;
		dfs(v);
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n) { scanf("%d",a + i); if (~a[i]) da[a[i]]++; }
	rep(i,1,n) { scanf("%d",b + i); if (~b[i]) db[b[i]]++; }
	rep(i,1,n) if ((da[i] & 1) ^ (db[i] & 1)) { printf("IMPOSSIBLE\n"); return 0; } 
	printf("POSSIBLE\n");
	rep(i,1,n) if (~a[i]) insert(a[i], i);
	rep(i,1,n) if (~b[i]) insert(n + b[i], n + i);
	rep(i,1,n) if (a[i] == -1) rep(j,1,n) if (b[j] == -1)
		insert(i, n + j);
	static int id[N];
	rep(i,1,n) if (!(da[i] & 1)) insert(i, i + n), id[i] = l >> 1;
	dfs(1);
	rep(i,1,n) if (da[i] & 1) printf("0 ");
	else printf("%d ",(vis[id[i]] & 1) ? 1 : -1);
	printf("\n");
	return 0;
}