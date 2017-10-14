#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define Rep(i,a) for(int i = 0; i < a; i++)
using namespace std;
#define pb(a) push_back(a)
const int N = 1e5 + 10;
int n, a[N];
vector<int> ch[N], s[N]; int f[N];
void dfs(int x) {
	int len = ch[x].size();
	Rep(i,len) dfs(ch[x][i]);
	sort(s[x].begin(), s[x].end());
	f[x] = len;
	Rep(i,len) f[x] = max(f[x], s[x][i] + len - i);
	if (x > 1) s[a[x]].pb(f[x]);
}

int main() {
	scanf("%d",&n); rep(i,2,n) scanf("%d",a + i);
	rep(i,2,n) ch[a[i]].pb(i);
	dfs(1);
	printf("%d\n",f[1]);
	return 0;
}