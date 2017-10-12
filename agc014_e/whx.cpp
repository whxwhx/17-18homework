#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i ++)
using namespace std;
const int N = 1e5 + 10;
typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)
multiset<pii> to[N];
typedef multiset<pii>::iterator sit;

int f[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void add_edge(int a, int b, int c);

pii q[N]; int l = 0, r = 0;

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	if (to[a].size() < to[b].size()) swap(a, b);
	f[b] = a;
	for(sit it = to[b].begin(); it != to[b].end(); it++) {
		int v = it->first, c = it->second;
		sit tmp = to[v].find(mp(b, c));
		to[v].erase(tmp);
		add_edge(v, a, c);
	}
}

void add_edge(int a, int b, int c) {
	sit it = to[a].find(mp(b, !c));
	if (it == to[a].end()) 
		to[a].insert(mp(b, c)), to[b].insert(mp(a, c));
	else {
		to[a].erase(it);
		it = to[b].find(mp(a, !c)); to[b].erase(it);
		q[r++] = mp(a, b);
	}
}

int main() {
	int n; scanf("%d",&n);
	rep(i,1,n) f[i] = i;
	rep(i,1,n - 1) {
		int a, b;
		scanf("%d%d",&a,&b);
		a = find(a), b = find(b);
		add_edge(a, b, 0);
	}
	rep(i,1,n - 1) {
		int a, b;
		scanf("%d%d",&a,&b);
		a = find(a), b = find(b);
		add_edge(a, b, 1);
	}
	while (l < r) merge(q[l].first, q[l].second), l++;
	rep(i,1,n) if (find(i) != find(1)) {
		printf("NO\n"); return 0;
	}
	printf("YES\n");
	return 0;
}