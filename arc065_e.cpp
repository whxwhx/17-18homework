#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#define ab(x) ((x) < 0 ? -(x) : (x))
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a; i <= b; i++) 
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
typedef long long LL;
const int N = 100010;
 
struct point { int x, y, id; } t[N];
inline bool operator < (const point &a, const point &b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
 
int n, D, a, b, f[N];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void merge(int a, int b) { a = find(a), b = find(b); if (a != b) f[a] = b; }
 
void init() {	
	rep(i,1,n) { int a = t[i].x, b = t[i].y; t[i] = (point){a + b, a - b, i}; }
	D = max(ab(t[a].x - t[b].x), ab(t[a].y - t[b].y)); 
}
 
map<int, int> d; int cnt;
void work_init() {
	cnt = 0; d.clear();
	rep(i,1,n) if (d.find(t[i].y) == d.end()) d[t[i].y] = ++cnt;
}
 
map<int, int> s[N];
void check(int y, int i, int id) {
	if (d.find(y) == d.end()) return; else y = d[y];
	while (!s[y].empty() && t[i].x - s[y].begin()->first > D) s[y].erase(s[y].begin());
	while (s[y].size() > 1) {
		int tmp = s[y].begin()->second; s[y].erase(s[y].begin()); 
		merge(tmp, id);
	}
	if (!s[y].empty()) merge(s[y].begin()->second, id);
}
 
void work() {
	work_init(); rep(i,1,cnt) s[i].clear();
	sort(t + 1, t + n + 1);
	rep(i,1,n) {
		check(t[i].y - D, i, t[i].id), check(t[i].y + D, i, t[i].id);
		s[d[t[i].y]][t[i].x] = t[i].id;
	}
}
 
int ans[N];
 
int calc(int y, int i) {
	if (d.find(y) == d.end()) return 0; else y = d[y];
	while (!s[y].empty() && t[i].x - s[y].begin()->first > D) s[y].erase(s[y].begin());
	return s[y].size();
}
 
void cal() {
	work_init(); rep(i,1,cnt) s[i].clear();
	sort(t + 1, t + n + 1);
	rep(i,1,n) {
		ans[t[i].id] += calc(t[i].y - D, i) + calc(t[i].y + D, i);
		s[d[t[i].y]][t[i].x] = t[i].id;
	}
}
 
void calc() { cal(); rep(i,1,n) swap(t[i].x, t[i].y); cal(); rep(i,1,n) swap(t[i].x, t[i].y); }
 
int dx[2];
set< pair<int, int> > S;
 
int main() {
	scanf("%d%d%d",&n,&a,&b);
	rep(i,1,n) scanf("%d%d",&t[i].x,&t[i].y);
	
	init();
	
	rep(i,1,n) f[i] = i; work();
	rep(i,1,n) swap(t[i].x, t[i].y); work(); rep(i,1,n) swap(t[i].x, t[i].y);
 
	merge(a, b);
	calc(); LL s = 0; rep(i,1,n) if (find(i) == find(a)) s += ans[i];
	dx[0] = -D, dx[1] = D;
	rep(i,1,n) S.insert(mp(t[i].x, t[i].y));
	rep(i,1,n) if (find(t[i].id) == find(a)) {
		rep(j,0,1) if (S.find(mp(t[i].x + dx[j], t[i].y - D)) != S.end()) s--;
	}
	printf("%lld\n",s);
	return 0;
}